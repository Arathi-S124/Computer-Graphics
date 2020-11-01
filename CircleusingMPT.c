
AIM:-  Draw circle using Mid Point Theoram.
CODE:-
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
int xc, yc;
int rad;
void plot_point(int x, int y)
{ glPointSize(5);
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glVertex2i(xc+x, yc-y);
  glVertex2i(xc+y, yc+x);
  glVertex2i(xc+y, yc-x);
  glVertex2i(xc-x, yc-y);
  glVertex2i(xc-y, yc-x);
  glVertex2i(xc-x, yc+y);
  glVertex2i(xc-y, yc+x);
  glEnd();
}

void MPT_circle(int r)
{
  int x=0,y=r;
  float pk=1-r;
  plot_point(x,y);
  int k;
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
    plot_point(x,y);
  }
  glFlush();
}


void circle_it(int radius)
{
  glClear(GL_COLOR_BUFFER_BIT);
  MPT_circle(radius);
}

void myInit()
{
  glClearColor(1.0,0,0,0);
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(0 , 640 , 0 , 480);
}
void myDisplay()
{ circle_it(rad); 
  glRasterPos2i(400,400);
  glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,"ARATHI S");
  glFlush(); }
void main(int argc, char **argv)
{  printf("Enter the values of xc and yc ,that is center points of circle : ");  
        scanf("%d%d",&xc,&yc); 
  printf("Enter radius=");
  scanf("%d",&rad);
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  glutCreateWindow("MPT for circle");
  myInit();
  glutDisplayFunc(myDisplay);
  glutMainLoop();
}
