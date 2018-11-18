#include <GL/glut.h>  

//initialize gl background
void initGL() {
   glClearColor(0.5f, 0.2f, 1.0f, 0.0f); 
   glClearDepth(1.0f);                   
   glEnable(GL_DEPTH_TEST);  
   glDepthFunc(GL_LEQUAL);    
   glShadeModel(GL_SMOOTH);  
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  
}
 
//display function
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);  
 
   //set the viewport into suitable one
   glLoadIdentity();            
   glTranslatef(-1.5f, 0.0f, -6.0f);  
   
   // Begin drawing the color cube
   glBegin(GL_QUADS);              
   
      // Top face (y = 1.0f)
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
 
      // Bottom face (y = -1.0f)    
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
 
      // Front face  (z = 1.0f)   
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
 
      // Back face (z = -1.0f)   
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
 
      // Left face (x = -1.0f)  
      glVertex3f(-1.0f,  1.0f,  1.0f);   
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);

      // Right face (x = 1.0f) 
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();  
   
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}
 
void reshape(GLsizei width, GLsizei height) {  

	//set projection
 	glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
     
    gluPerspective(45.0f,(GLdouble)width/(GLdouble)height,0.1f,100.0f);
    glViewport(0,0,width,height);  //wievport is whole screen
}
 
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);            
   glutInitDisplayMode(GLUT_DOUBLE); 
   glutInitWindowSize(640, 480);   
   glutInitWindowPosition(50, 50); 
   glutCreateWindow("week9-hw1");  
        
   glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
   glColor3f(1.0f, 0.5f, 0.0f);//orange 
   
   
   glutDisplayFunc(display);       
   glutReshapeFunc(reshape);      
   initGL();                       
   glutMainLoop();                 
   return 0;
}
