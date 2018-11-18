#include <GL\glut.h>

//rotation variables
GLfloat xRotated, yRotated, zRotated;

void display(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
	glTranslatef(0.0,0.0,-4.5);
	
    glColor3f(1.0, 0.5, 0.0); 
    glRotatef(xRotated,0.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,0.0);
    glScalef(1.0,1.0,1.0);
	
    glutSolidSphere(0.2,16,16);
    glutSwapBuffers();
}

void reshapeFunc(int x, int y)
{
    if (y == 0 || x == 0) return; 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
     
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glViewport(0,0,x,y);
}

void idleFunc(void)
{
    yRotated += 0.01;
    display();
}

int main (int argc, char **argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	  
    // create the window 
	glutInitWindowSize(640,480);
    glutCreateWindow("Solar System Project");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
     xRotated = yRotated = zRotated = 30.0;
     xRotated=33;
     yRotated=40;
    glClearColor(0.0,0.0,0.0,0.0);
    
    //Assign  the function used in events
    glutDisplayFunc(display);
    glutReshapeFunc(reshapeFunc);
    
    //use idle for continuity of the natural movement
    glutIdleFunc(idleFunc);
    glutMainLoop();
    return 0;
}
