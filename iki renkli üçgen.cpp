#include <GL/glut.h>

void render (void);

//main fonk i�inde bo� bir glut �er�evesi olu�turdum.
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Ay�eg�l Demirta�");
	glutDisplayFunc(render);
	glutMainLoop();
}

void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	  glPolygonMode(GL_FRONT,GL_FILL);
      glBegin(GL_POLYGON);
      glColor3f( 1, 0,0 );
		glVertex2f(-0.5,-0.5);
		glVertex2f(0.5,-0.5);
		glVertex2f(0.0,0.5);
	glEnd();
 
	  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glBegin(GL_POLYGON);
        glColor3f(   0,  0, 1 );
		glVertex2f(-0.5,-0.5);
		glVertex2f(0.5,-0.5);
		glVertex2f(0.0,0.5);
	 glEnd();
	glutSwapBuffers();
}

