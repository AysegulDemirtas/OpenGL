#include <windows.h> //for Code::Blocks user

#include <GL/glut.h>

#include <stdio.h>

#include <gl\gl.h>

#include <gl\glu.h>

#include <stdlib.h>

GLuint texture;


struct Image {

    unsigned long sizeX;

    unsigned long sizeY;

    char *data;

};

typedef struct Image Image;

#define checkImageWidth 64
#define checkImageHeight 64


int ImageLoad(char *filename, Image *image) {
    FILE *file;
    unsigned long size; // size of the image in bytes.
    unsigned long i; // standard counter.
    unsigned short int planes; // number of planes in image (must be 1)
    unsigned short int bpp; // number of bits per pixel (must be 24)
    char temp; // temporary color storage for bgr-rgb conversion.
    if ((file = fopen(filename, "rb"))==NULL){
        printf("File Not Found : %s\n",filename);
        return 0;
    }
    fseek(file, 18, SEEK_CUR);
    if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
        printf("Error reading width from %s.\n", filename);
        return 0;
    }
    if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
        printf("Error reading height from %s.\n", filename);
        return 0;
    }
    size = image->sizeX * image->sizeY * 3;
    if ((fread(&planes, 2, 1, file)) != 1) {
        printf("Error reading planes from %s.\n", filename);
        return 0;
    }
    if (planes != 1) {
        printf("Planes from %s is not 1: %u\n", filename, planes);
        return 0;
    }
    if ((i = fread(&bpp, 2, 1, file)) != 1) {
        printf("Error reading bpp from %s.\n", filename);
        return 0;

	}

    fseek(file, 24, SEEK_CUR);
    image->data = (char *) malloc(size);


    if ((i = fread(image->data, size, 1, file)) != 1) {
        printf("Error reading image data from %s.\n", filename);
        return 0;
    }

    for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
        temp = image->data[i];
        image->data[i] = image->data[i+2];
        image->data[i+2] = temp;
    }
    return 1;
}


Image * loadTexture(){
    Image *image1;
    image1 = (Image *) malloc(sizeof(Image));
    if (!ImageLoad("floor.bmp", image1)) {
        exit(1);
    }
    return image1;
}


void myinit(void)
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    Image *image1 = loadTexture();
  
    // Create Texture
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //scale linearly when image smalled than texture
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX, image1->sizeY, 0,
    GL_RGB, GL_UNSIGNED_BYTE, image1->data);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);
}



void display(void){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Back off twentyfive units to be able to view from the origin.
    glTranslatef ( 0.0, 0.0, -20.0 );

    glBindTexture(GL_TEXTURE_2D, texture);

    glBegin(GL_QUADS);

	glTexCoord2f( 0.0f, 1.0f ); 
	glVertex3f( -10.0f, 10.0f, 0.0f );
	//top left
	glTexCoord2f( 0.0f, 0.0f ); 
	glVertex3f( -10.0f, -10.0f, 0.0f );
	//bottom left
	glTexCoord2f( 1.0f, 0.0f ); 
	glVertex3f( 10.0f, -10.0f, 0.0f );	
	//bottom right
	glTexCoord2f( 1.0f, 1.0f ); 
	glVertex3f( 10.0f, 10.0f, 0.0f );	
	//top right
	glEnd( );

    glutSwapBuffers();

}


void myReshape(int w, int h){

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluPerspective(60.0, 1.0*(GLfloat)w/(GLfloat)h, 1.0, 30.0);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(0.0, 0.0, -3.6);

}


int main(int argc, char** argv)

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutCreateWindow("Texture Mapping - Programming Techniques");

    myinit();

    glutReshapeFunc (myReshape);

    glutDisplayFunc(display);


    glutMainLoop();

    return 0;

}

