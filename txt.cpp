#include <GL/glut.h>

void drawString (void *font, float x, float y, char *str);

void render(void);


void drawString (void *font, float x, float y, char *str){
	
	char *ch;
	glRasterPos3f(x,y,0.0);
	for (ch=str; *ch; ch++){
		glutBitmapCharacter( font , (int)*ch);
	}
	
}

int main(int argc,char** argv)
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Ayþegül Demirtaþ Text Display HW");
	glutDisplayFunc(render);
	
	glutMainLoop();
}


void render(void)
{

	glColor3f(1.0,1.0,1.0);
	drawString (GLUT_BITMAP_HELVETICA_18,-0.7,0.0,"This is a homework for ceng 315 Course");
	
	glEnd();
	
	glutSwapBuffers();
}


