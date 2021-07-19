#include<windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

GLint keyl,keyr,flag=0;
float  counter=600.0, cnt=-150.0,r1=0.0,g1=1.0,b1=0.0,bc=-260.0,tt=-260.0,ms=400.0,ts=100.0,rs=100.0;
float r2=0.0,g2=1.0,b2=1.0,r=1.0,g=0.0,b=0.0;
float posX = 0.0, posY = 0.0;
int c=1,d=1;
int score = 0;
bool bottom = TRUE;
bool top = FALSE;

void  road();
void  grass();
void  grass2();
void  line1();
void  line2();
void  line3();
void  line4();
void  car();
void  truck();
void  bus();
void  sq();
void  text();
void  tc();
void  light();
void  light2();
void track1();
void man();


void *currentfont;


void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *ct;
	//displaying test
	glRasterPos3f(x,y,z);

	for(ct=string;*ct!='\0';ct++)
	{
	    glColor3f(0.0,0.0,0.0);
	    //renders a bitmap character using OpenGL.
		glutBitmapCharacter(currentfont,*ct);
	}
}

void initOpenGl()
{
    glClearColor(0.2,0.6,0.99,0); //Background Color
    //glClearColor(0.0,0.0,0.0,0); //Background Color
    glMatrixMode(GL_PROJECTION);
    //replace the current matrix with the identity matrix
    glLoadIdentity();
    //define a 2D orthographic projection matrix
    gluOrtho2D(0,700,0,500);
    //specify which matrix is the current matrix
    glMatrixMode(GL_MODELVIEW);
}

void text()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
    drawstring(160,130,0.0,"SUB BUS");
    glColor3f(1,1,1);
}

void scoreboard()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
    drawstring(360,430,0.0,"SCORE");
    glColor3f(1,1,1);
}

void credit()
{
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1,1,1);
    drawstring(5,55,0.0,"Animated Crossing The Road");
    glColor3f(1,1,1);
    drawstring(5,55,0.0,"Devoloped By: Marzia Mahjabin");
    glColor3f(1,1,1);
    drawstring(5,30,0.0,"ID: CSE06507629");
    glColor3f(1,1,1);
    drawstring(5,5,0.0,"CSE, STAMFORD UNIVERSITY BANGLADESH(SUB)");
}


void window(int w1,int w2)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(w1,160);
    glVertex2f(w1,185);
    glVertex2f(w2,185);
    glVertex2f(w2,160);
    glEnd();
}

void buswindow(int w1,int w2)
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(w1,180);
    glVertex2f(w1,205);
    glVertex2f(w2,205);
    glVertex2f(w2,180);
    glEnd();
}


void wheel(int x,int y)
{
   float th;
   glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   //circle is 360 degree
   for(int i=0;i<360;i++)
   {
       //theta in radian
       th=i*(3.1416/180);
       //drawing circle with coordinates rcosth and rsinth
       //x and y is for shifting to correct position
       glVertex2f(x+20*cos(th),y+20*sin(th));
   }

   glEnd();

}

void road()
{
    glLoadIdentity();
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(0,95);
    glVertex2f(0,260);
    glVertex2f(800,260);
    glVertex2f(800,95);
    glEnd();
}

void grass()
{
    glLoadIdentity();
    glColor3f(0.0,0.5,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,95);
    glVertex2f(800,95);
    glVertex2f(800,0);
    glEnd();
}

void grass2()
{
    glLoadIdentity();
    glColor3f(0.0,0.5,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(0,260);
    glVertex2f(0,300);
    glVertex2f(800,300);
    glVertex2f(800,260);
    glEnd();
}

void line1()
{
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0,190);
    glVertex2f(150,190);
    glEnd();

}

void line2()
{
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(200,190);
    glVertex2f(300,190);
    glEnd();

}

void line3()
{
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(350,190);
    glVertex2f(500,190);
    glEnd();

}

void line4()
{
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(550,190);
    glVertex2f(700,190);
    glEnd();

}

void man()
{
    glLoadIdentity();
    glColor3f(1.0,1.0,1.0);
    glScaled(0.4,0.4,0.4);

    //head
    wheel(380+posX,260+posY);
    //body
    glBegin(GL_POLYGON);
    glVertex2f(360+posX, 110+posY);
    glVertex2f(360+posX, 230+posY);
    glVertex2f(400+posX, 230+posY);
    glVertex2f(400+posX, 110+posY);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(370+posX,110+posY);
    glVertex2f(370+posX,80+posY);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(390+posX,110+posY);
    glVertex2f(390+posX,80+posY);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(320+posX,230+posY);
    glVertex2f(320+posX,240+posY);
    glVertex2f(440+posX,240+posY);
    glVertex2f(440+posX,230+posY);
    glEnd();
}

void car()
{

   //Bottom Part
   glLoadIdentity();
   counter=counter-0.05;
   glColor3f(r1,g1,b1);
   glTranslated(counter,80,0.0);
   if(counter<-500.00)
   {

       c++;
       counter=700.0;
       //changing color
       if(c%2==0)
       {
           r1=1.0;
           g1=0.0;
           b1=0.0;

       }
       else if(c%3==0)
       {
           r1=0.0;
           g1=2.0+c;
           b1=1.0+c;
       }
       else if(c%5==0)
       {
           r1=1.0;
           g1=1.0;
           b1=0.0;
       }
       else
       {
           r1=0.0;
           g1=1.0;
           b1=0.0;
       }

   }
   glScaled(0.5,0.5,0.0);
   glBegin(GL_POLYGON);
   glVertex2f(100,100);
   glVertex2f(100,160);
   glVertex2f(450,160);
   glVertex2f(450,100);
   glEnd();

   //Top Part
   glBegin(GL_POLYGON);
   glVertex2f(150,160);
   glVertex2f(200,200);
   glVertex2f(400,200);
   glVertex2f(450,160);

   glEnd();


   window(200,270);
   window(280,330);
   window(340,390);
   wheel(200,100);
   wheel(380,100);


}

void sq()
{
   glBegin(GL_POLYGON);
   glColor3f(0.9,0.2,0.1);
   glVertex2f(100,120);
   glVertex2f(100,170);
   glVertex2f(470,170);
   glVertex2f(470,120);
   glEnd();
}

void bus()
{

   glLoadIdentity();
   bc=bc+0.05;
   glColor3f(1.0,1.0,1.0);
   glTranslated(bc,180,0.0);
   //restart from position -260
   if(bc>800.00)
   {
       bc=-260.0;

   }
   glScaled(0.4,0.4,0.0);
   glBegin(GL_POLYGON);
   glVertex2f(100,100);
   glVertex2f(100,220);
   glVertex2f(470,220);
   glVertex2f(470,100);
   glEnd();

   buswindow(110,160);
   buswindow(170,220);
   buswindow(230,270);
   buswindow(280,330);
   buswindow(340,390);
   buswindow(400,450);
   wheel(200,100);
   wheel(380,100);

}


void display()
{

  glClear(GL_COLOR_BUFFER_BIT);
  //starting display
  road();
  grass();
  grass2();
  line1();
  line2();
  line3();
  line4();
  car();
  //truck();
  bus();
  sq();
  text();
  man();

  glutSwapBuffers();
  glFlush();

}

void intro()
{
  //clears the window
  glClear(GL_COLOR_BUFFER_BIT);
  //developer information



  glutSwapBuffers();
  glFlush();

}

void MyTimerFunc(int value);

void showscore()
{
    char _score[10];
    itoa(score, _score, 10);
    char text[50] = "Your score: ";
    strcat(text, _score);
    MessageBox(NULL, text, "Game Over", 0);
    exit(0);
}

void checktouch()
{
    if(posY >= 220 && posY <= 370)
    {
        if(counter <= 100 && counter >= 90)
        {
            showscore();
        }
    }
    if(posY >= 440 && posY <= 564)
    {
        if(bc >= -40 && bc <= -30)
        {
            showscore();
        }
    }
}

void moveFunc(int key, int x, int y) {
    switch(key) {
    case GLUT_KEY_UP:
        if(posY <= 580)
        {
            if(posY == 580 && bottom)
            {
                top = TRUE;
                bottom = FALSE;
                score++;
            }
            posY += 2;
            checktouch();
        }
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        if(posY >= 0)
        {
            if(posY == 0 && top)
            {
                top = FALSE;
                bottom = TRUE;
                score++;
            }
            posY -= 2;
            checktouch();
        }
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        if(posX >= -340) posX -= 2;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        if(posX <= 1300)
        {
            if(posX == 1300) showscore();
            posX += 2;
        }
        glutPostRedisplay();
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Animated Crossing The Road");
    initOpenGl();
    glutDisplayFunc(intro);
    glutIdleFunc(intro);
    glutTimerFunc(1000, MyTimerFunc, 0);
    glutSpecialFunc(moveFunc);
    glutMainLoop();
    return 0;
}

void MyTimerFunc(int value)
{
   if (value == 0) // passed in in main
   {
      glutDisplayFunc(display);
      glutIdleFunc(display);

      // Change to a new display function in 25 seconds
      glutTimerFunc(300, MyTimerFunc, 0);
   }

}


