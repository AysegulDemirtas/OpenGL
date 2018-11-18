#include <GL/glut.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//this program executes a triangle
//you can control the tiny movement of it by use 8-6-4-2-5 

void render (void);

void keyboard (unsigned char c, int x, int y);

//this is again the same main as the first homework
int main(int argc,char** argv)
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("Ayþegül Demirtaþ HW2");
	glutDisplayFunc(render);
	
	//the only difference is this keyboard function 
	//instead of mouse function
	glutKeyboardFunc(keyboard);

	glutMainLoop();
}

//Sorun bu fonksiyonun içinde
void keyboard (unsigned char c, int x, int y)
{
	//xi burda tanýmlamayý denemiþtim
	//float x = 0.2;
	
	//press 8 triangle goes up
	if(c == 56){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
		glColor3f(0,1,0);
		glVertex2f(-0.0,-0.4);
		glVertex2f(0.5,-0.4);
		glVertex2f(0.0,0.6);
	glEnd();
	
	glutSwapBuffers();
	}
	
	//press 6 triangle goes to right
	if(c == 54){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
		glColor3f(0,1,0);
		glVertex2f(0.1,-0.5);
		glVertex2f(0.6,-0.5);
		glVertex2f(0.1,0.5);
	glEnd();
	
	glutSwapBuffers();
	}
	
	//press 5 triangle goes to its original position
	if(c == 53){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
		glColor3f(0,1,0);
		glVertex2f(0.0,-0.5);
		glVertex2f(0.5,-0.5);
		glVertex2f(0.0,0.5);
	glEnd();
	
	glutSwapBuffers();
	}
	
	//press 4 triangle goes to left
	if(c == 52){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
		glColor3f(0,1,0);
		glVertex2f(-0.1,-0.5);
		glVertex2f(0.4,-0.5);
		glVertex2f(-0.1,0.5);
	glEnd();
	
	glutSwapBuffers();
	}
	
	//press 2 triangle goes down
	if(c == 50){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
		glColor3f(0,1,0);
		glVertex2f(0.0,-0.6);
		glVertex2f(0.5,-0.6);
		glVertex2f(0.0,0.4);
	glEnd();
	
	glutSwapBuffers();
	}
	
}

//It creates the initial triangle 
void render(void)
{
	glClearColor(0.5f, 0.5f, 0.3f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_TRIANGLES);
		glColor3f(0,1,0);
		glVertex2f(-0.0,-0.5);
		glVertex2f(0.5,-0.5);
		glVertex2f(0.0,0.5);
	glEnd();
	
	glutSwapBuffers();
}


