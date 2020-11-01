AIM:- Draw circle using the polar equations.

CODE:-

    #include <GL/glut.h>
    #include <stdio.h>
    #include<math.h> 
    float pi=3.14;
    int xc,yc,r; 
 
void Circle(int xc, int yc, int r) {

       float i, ang;
       glPointSize(3);
       glColor3f(1,0,1);
       glBegin(GL_POINTS);
       for(i=0; i<100; i++)
        {    ang= i*2*(pi*100);
             glVertex3f(xc+cos(ang)*r, yc+(sin(ang)*r),0);
        }

       glEnd();
}
void myDisplay() {
       glClear(GL_COLOR_BUFFER_BIT);
       glColor3f(1,0,1);
       Circle(xc, yc, r);
       glRasterPos2i(400,400);
       glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,"ARATHI S");
       glFlush();
}

     void main(int argc, char **argv)
    {   printf("Enter the values of xc and yc ,that is center points of circle : ");  
        scanf("%d%d",&xc,&yc);  
        printf("Enter the radius of circle : ");  
        scanf("%d",&r);  
         glutInit(&argc,argv);
         glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
         glutInitWindowSize(500,500);
         glutInitWindowPosition(200,200);
         glutCreateWindow("Cicle Polar");
         glClearColor(1,1,0,1);
         gluOrtho2D(0,500,0,500);
         //myInit();
         glutDisplayFunc(myDisplay);
         glutMainLoop();
      
    }
