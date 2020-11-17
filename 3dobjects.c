Creating 3D Shapes like Cube, Sphere and others. WAP to create any three 3D objects:
1) CUBE
2) SPHERE
3) CONE
4) TEAPOT.

CODE:-
#include<math.h>
#include<stdio.h>
#include<GL/glut.h>
GLfloat xRotated, yRotated, zRotated;
GLdouble base=1;
GLdouble size=1;
GLdouble height=1.5;
GLint slices =25;
GLint stacks =25;
void cone(void);
void teapot(void);
void display(void);
void cube(void);
void reshape(int x, int y);
int ans;
void idle(void)
{
 
	xRotated += 0.01;
	yRotated += 0.01;
    zRotated += 0.01; 
    if (ans==1) cone();
    else if (ans==2) teapot(); 
    else cube(); 
   // display();
    glEnd();
   glFlush();
}

 

int main (int argc, char **argv)
{
    glutInit(&argc, argv); 
    glutInitWindowSize(350,350);
    glutCreateWindow("3D Objects");
    xRotated = yRotated = zRotated = 30.0;
    xRotated=43;
    yRotated=50;
 
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
void display(void)
{ glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0,0,1);
  
  printf("\nTransformations:\n");
    printf("\n1. Cone");
    printf("\n2. Teapot");
    printf("\n3. Cube");
    printf("\n4. Exit");
    printf("\nEnter choice:");

    scanf("%d",&ans);
    switch(ans)
    {
      case 1: idle(); 
              break;
      case 2: teapot();
              break;
      case 3: cube();
              break;
      case 4: exit(1);
	break; 
       default: printf("wrong input");
     }
    
  glEnd();
  glFlush();
}
void cone(void)
{

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-5.0);
    glColor3f(0.9, 0.3, 0.2); 
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0);
    glScalef(1.0,1.0,1.0);
    glutWireCone(base,height,slices,stacks);
    glFlush();        
  
}

void teapot(void)
{

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-4.0);
    glColor3f(0.0, 0.0, 1.0); 
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,0.0);
    glScalef(1.0,1.0,1.0);
    glutWireTeapot(size);     
    glFlush();   
        
}
void cube(void)
{

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-5.0);
    glColor3f(0.9, 0.3, 0.2); 
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0);
    glScalef(1.0,1.0,1.0);
    glutWireCube(size);
    glFlush();      
  
}


void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;   
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  
   }

