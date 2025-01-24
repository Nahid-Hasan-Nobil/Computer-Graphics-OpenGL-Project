#include <vector>
#include <cstdio>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>
#include<cmath>
#include <ctime>
# define PI   3.14159265358979323846
#include<MMSystem.h>

using namespace std;

float _moveA = 0.0f;
float _moveB = 0.0f;
float _moveC = 0.0f;
float _angle1 = 0.0f;
float speed = 0.02f;

GLfloat angle = 0.0f;
GLfloat truckPosition = 0.0f;
GLfloat truckSpeed = 0.05f;
GLfloat move_train = 0.0f;


void updateTruck(int value)
{
    if (truckPosition > 16)
    {
        truckPosition = -1.2f;
    }
    truckPosition += truckSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateTruck, 0);
}


GLfloat carPosition = 0.0f;
GLfloat carSpeed = 0.09f;
void updateCar(int value)
{
    if (carPosition < -9)
    {
        carPosition = 2.2f;
    }
    carPosition -= carSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateCar, 0);
}


void circleSolid(float x, float y, float radius)
{
    int triangleAmount = 100; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)), y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

//A1
void scenario()///full scenario
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-16, 9);
    glVertex2f(-16, -9);
    glVertex2f(16, -9);
    glVertex2f(16, 9);  // x, y
    glEnd();

}
//H1
void House1() ///house 1,3,4
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(234, 52, 12); // red///shade
    glVertex2f(-15.4, -4);
    glVertex2f(-15.6, -4.7);
    glVertex2f(-12.8, -4.7);
    glVertex2f(-13, -4);
    glEnd();
    glColor3ub(234, 52, 12); // red///shade
    glBegin(GL_POLYGON);
    glVertex2f(-15.4, -5.3);
    glVertex2f(-15.6, -6);
    glVertex2f(-14.8, -6);
    glVertex2f(-14.2, -5.4);
    glVertex2f(-14.2, -5.3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-14.2, -5.3);
    glVertex2f(-14.2, -5.4);
    glVertex2f(-13.6, -6);
    glVertex2f(-12.8, -6);
    glVertex2f(-13, -5.3);
    glEnd();
    glColor3ub(220, 149, 16);///shade
    glBegin(GL_POLYGON);
    glVertex2f(-15.4, -6);
    glVertex2f(-14.8, -6);
    glVertex2f(-14.7, -6.1);
    glVertex2f(-14.7, -6.7);
    glVertex2f(-15.4, -6.7);
    glEnd();
    glBegin(GL_POLYGON);///shade
    glVertex2f(-13.7, -6.1);
    glVertex2f(-13.6, -6);
    glVertex2f(-13, -6);
    glVertex2f(-13, -6.8);
    glVertex2f(-13.7, -6.7);
    glEnd();
    glColor3ub(220, 149, 16);
    glBegin(GL_QUADS);
    glVertex2f(-15.4, -4.7);
    glVertex2f(-15.4, -5.3);
    glVertex2f(-13, -5.3);
    glVertex2f(-13, -4.7);
    glEnd();
    glColor3ub(173, 176, 170);///
    glBegin(GL_QUADS);
    glVertex2f(-16, -6.7);
    glVertex2f(-16, -6.8);
    glVertex2f(-12.4, -6.8);
    glVertex2f(-12.4, -6.7);
    glEnd();

    glColor3ub(11, 251, 255);///glass
    glBegin(GL_QUADS);
    glVertex2f(-15, -4.8);
    glVertex2f(-15, -5.2);
    glVertex2f(-14.7, -5.2);
    glVertex2f(-14.7, -4.8);

    glVertex2f(-13.7, -4.8);
    glVertex2f(-13.7, -5.2);
    glVertex2f(-13.4, -5.2);
    glVertex2f(-13.4, -4.8);

    glVertex2f(-13.5, -6.2);
    glVertex2f(-13.5, -6.6);
    glVertex2f(-13.2, -6.5);
    glVertex2f(-13.2, -6.2);

    glVertex2f(-15.2, -6.2);
    glVertex2f(-15.2, -6.6);
    glVertex2f(-14.9, -6.6);
    glVertex2f(-14.9, -6.2);

    glColor3ub(93, 66, 7);///door
    glVertex2f(-14.4, -6.2);
    glVertex2f(-14, -6.2);
    glVertex2f(-14, -6.7);
    glVertex2f(-14.4, -6.7);
    glEnd();



    ///house 3 ///
    glBegin(GL_QUADS);
    glColor3ub(234, 52, 12); // red///shade
    glVertex2f(-2.8,-3.8);
    glVertex2f(-1.4,-3.8);
    glVertex2f(-0.7,-4.6);
    glVertex2f(-2.1,-4.6);
    glEnd();

    glColor3ub(131, 111, 61);///shade
    glBegin(GL_POLYGON);
    glVertex2f(-3.5,-5.5);
    glVertex2f(-3.5,-4.6);
    glVertex2f(-2.8,-3.9);
    glVertex2f(-2.2,-4.6);
    glVertex2f(-2.2,-5.5);
    glEnd();
    glColor3ub(234, 52, 12); /// red///shade
    glBegin(GL_POLYGON);
    glVertex2f(-2.8,-3.8);
    glVertex2f(-3.54,-4.55);
    glVertex2f(-3.50,-4.6);
    glVertex2f(-2.8,-3.9);
    glVertex2f(-2.2,-4.6);
    glVertex2f(-2.1,-4.6);

    glEnd();
    glBegin(GL_POLYGON);///red shade
    glVertex2f(-2.8,-4.3);
    glVertex2f(-3.4,-4.9);
    glVertex2f(-3.3,-4.9);
    glVertex2f(-2.8,-4.4);
    glVertex2f(-2.3,-5);
    glVertex2f(-2.3,-4.9);

    glEnd();


    glColor3ub(197, 157, 60);///shade
    glBegin(GL_POLYGON);
    glVertex2f(-3.3,-5.5);
    glVertex2f(-3.3,-4.9);
    glVertex2f(-2.8,-4.4);
    glVertex2f(-2.4,-4.9);
    glVertex2f(-2.4,-5.5);
    glEnd();
    glColor3ub(220, 149, 16);///shade
    glBegin(GL_POLYGON);
    glVertex2f(-15.4, -6);
    glVertex2f(-14.8, -6);
    glVertex2f(-14.7, -6.1);
    glVertex2f(-14.7, -6.7);
    glVertex2f(-15.4, -6.7);
    glEnd();

    glColor3ub(220, 149, 16);
    glBegin(GL_QUADS);
    glVertex2f(-0.8,-5.5);
    glVertex2f(-0.8,-4.6);
    glVertex2f(-2.2,-4.6);
    glVertex2f(-2.2,-5.5);
    glEnd();
    glColor3ub(173, 176, 170);/// bit
    glBegin(GL_QUADS);
    glVertex2f(-3.6,-5.5);
    glVertex2f(-3.6,-5.6);
    glVertex2f(-0.7,-5.6);
    glVertex2f(-0.7,-5.5);
    glEnd();

    glColor3ub(11, 251, 255);///glass
    glBegin(GL_QUADS);
    glVertex2f(-2,-5);
    glVertex2f(-1.7,-5);
    glVertex2f(-1.7,-5.3);
    glVertex2f(-2,-5.3);

    glVertex2f(-1.3,-5);
    glVertex2f(-1.3,-5.3);
    glVertex2f(-1,-5.3);
    glVertex2f(-1,-5);



    glColor3ub(93, 66, 7);///door
    glVertex2f(-3,-5.1);
    glVertex2f(-2.7,-5.1);
    glVertex2f(-2.7,-5.5);
    glVertex2f(-3,-5.5);
    glEnd();




    ///house 4 ///
    glBegin(GL_POLYGON);
    glColor3ub(61, 54, 51); ///
    glVertex2f(0.1,-2.7);
    glVertex2f(0.6,-2.7);
    glVertex2f(0.6,-2.8);
    glVertex2f(0.5,-2.8);
    glVertex2f(0.5,-2.9);
    glVertex2f(0.2,-2.9);
    glVertex2f(0.2,-2.8);
    glVertex2f(0.1,-2.8);
    glEnd();

    glColor3ub(164, 138, 23);///shade
    glBegin(GL_POLYGON);
    glVertex2f(0.1,-3.6);
    glVertex2f(0.1,-4.1);
    glVertex2f(2.3,-4.1);
    glVertex2f(2.3,-3.6);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.1,-4.7);
    glVertex2f(0.1,-5.3);
    glVertex2f(2.3,-5.3);
    glVertex2f(2.3,-4.7);
    glVertex2f(1.7,-4.7);
    glVertex2f(1.7,-4.8);
    glVertex2f(1.2,-4.2);
    glVertex2f(0.7,-4.8);
    glVertex2f(0.7,-4.7);



    glEnd();
    glColor3ub(255, 1, 1 );
    glBegin(GL_POLYGON);///red shade
    glVertex2f(1.2,-4.1);
    glVertex2f(1.7,-4.7);
    glVertex2f(1.7,-4.8);
    glVertex2f(1.2,-4.2);
    glVertex2f(0.7,-4.8);
    glVertex2f(0.7,-4.7);

    glEnd();



    glColor3ub(107, 21, 21);///shade-upper
    glBegin(GL_QUADS);
    glVertex2f(0,-3.6);
    glVertex2f(0.1,-2.9);
    glVertex2f(2.3,-2.9);
    glVertex2f(2.4,-3.6);
    glEnd();

    glColor3ub(107, 21, 21);
    glBegin(GL_QUADS);
    glVertex2f(0.1,-4.1);
    glVertex2f(0,-4.7);
    glVertex2f(0.7,-4.7);
    glVertex2f(1.2,-4.1);

    glVertex2f(1.2,-4.1);
    glVertex2f(2.3,-4.1);
    glVertex2f(2.4,-4.7);
    glVertex2f(1.7,-4.7);
    glEnd();
    glColor3ub(132, 127, 127);/// bit
    glBegin(GL_QUADS);
    glVertex2f(-0.4,-5.35);
    glVertex2f(-0.4,-5.4);
    glVertex2f(2.8,-5.4);
    glVertex2f(2.8,-5.35);
    glEnd();

    glColor3ub(11, 251, 255);///glass-upper
    glBegin(GL_QUADS);
    glVertex2f(0.5,-3.7);
    glVertex2f(0.8,-3.7);
    glVertex2f(0.8,-4);
    glVertex2f(0.5,-4);

    glVertex2f(1.6,-3.7);
    glVertex2f(1.9,-3.7);
    glVertex2f(1.9,-4);
    glVertex2f(1.6,-4);
    glEnd();
    glBegin(GL_QUADS);///glass -lower
    glVertex2f(0.3,-4.9);
    glVertex2f(0.6,-4.9);
    glVertex2f(0.6,-5.2);
    glVertex2f(0.3,-5.2);

    glVertex2f(1.8,-4.9);
    glVertex2f(2.1,-4.9);
    glVertex2f(2.1,-5.2);
    glVertex2f(1.8,-5.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(93, 66, 7);///door
    glVertex2f(1,-4.9);
    glVertex2f(1.4,-4.9);
    glVertex2f(1.4,-5.4);
    glVertex2f(1,-5.4);
    glEnd();
    glPopMatrix();
}
//R1
void Road()///road
{
    glBegin(GL_POLYGON);
    glColor3ub(41, 38, 34);///gray
    glVertex2f(4.6, -4.2);
    glVertex2f(5.4, -4.6);
    glVertex2f(5.5,-4.6);
    glVertex2f(5.7,-4.5);
    glVertex2f(5.7,-4.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(41, 38, 34);///gray
    glVertex2f(4.6, -4.2);
    glVertex2f(5.4, -4.6);
    glVertex2f(-12.8, -4.6);
    glVertex2f(-12.9, -4.2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-16, -4.6);
    glVertex2f(-16, -4.2);
    glVertex2f(-15.5, -4.2);
    glVertex2f(-15.6, -4.6);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(249, 247, 243);//white
    glVertex2f(-15.9, -4.4);
    glVertex2f(-15.7, -4.4);

    glVertex2f(-12.6, -4.4);
    glVertex2f(-12.4, -4.4);
    glVertex2f(-12, -4.4);
    glVertex2f(-11.8, -4.4);

    glVertex2f(-11.4, -4.4);
    glVertex2f(-11.2, -4.4);
    glVertex2f(-10.8, -4.4);
    glVertex2f(-10.6, -4.4);
    glVertex2f(-10.2, -4.4);
    glVertex2f(-10, -4.4);

    glVertex2f(-9.6, -4.4);
    glVertex2f(-9.4, -4.4);
    glVertex2f(-9, -4.4);
    glVertex2f(-8.8, -4.4);
    glVertex2f(-8.4, -4.4);
    glVertex2f(-8.2, -4.4);
    glVertex2f(-7.8, -4.4);
    glVertex2f(-7.6, -4.4);

    glVertex2f(-7.2, -4.4);
    glVertex2f(-7, -4.4);
    glVertex2f(-6.6, -4.4);
    glVertex2f(-6.4, -4.4);
    glVertex2f(-6, -4.4);
    glVertex2f(-5.8, -4.4);

    glVertex2f(-5.4, -4.4);
    glVertex2f(-5.2, -4.4);
    glVertex2f(-4.8, -4.4);
    glVertex2f(-4.6, -4.4);

    glVertex2f(-4.3, -4.4);
    glVertex2f(-4.2, -4.4);
    glVertex2f(-3.8, -4.4);
    glVertex2f(-3.6, -4.4);
    glVertex2f(-0.7, -4.4);
    glVertex2f(-0.6, -4.4);
    glVertex2f(-0.4, -4.4);
    glVertex2f(-0.3, -4.4);
    glVertex2f(-0.1, -4.4);
    glVertex2f(0, -4.4);
    glVertex2f(2.4, -4.4);
    glVertex2f(2.5, -4.4);
    glVertex2f(2.8, -4.4);
    glVertex2f(2.9, -4.4);
    glVertex2f(3.1, -4.4);
    glVertex2f(3.2, -4.4);
    glVertex2f(3.4, -4.4);
    glVertex2f(3.5, -4.4);
    glVertex2f(3.7, -4.4);
    glVertex2f(3.8, -4.4);
    glVertex2f(4, -4.4);
    glVertex2f(4.2, -4.4);
    glVertex2f(4.4, -4.4);
    glVertex2f(5, -4.4);
    glEnd();
}
//W1
void warehouse1()                     ///warehouse 1
{
    glBegin(GL_QUADS);///warehouse 1
    glColor3ub(168, 142, 128); //
    glVertex2f(14,1.5);
    glVertex2f(15.5,1.5);
    glVertex2f(15.5,0);
    glVertex2f(14,0);

    glVertex2f(13.8,1.4);
    glVertex2f(14,1.4);
    glVertex2f(14,0.5);
    glVertex2f(13.8,0.5);
    glColor3ub(131, 83, 63);
    glVertex2f(14,0.5);
    glVertex2f(13.5,0.5);
    glVertex2f(13.5,0);
    glVertex2f(14,0);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(14.5,1.5);
    glVertex2f(14.5,0);

    glVertex2f(15,1.5);
    glVertex2f(15,0);
    glVertex2f(14,1);
    glVertex2f(15.5,1);
    glVertex2f(15.5,0.5);
    glVertex2f(14,0.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(131, 83, 63);
    glVertex2f(15.5,1.4);
    glVertex2f(15.6,1.4);
    glVertex2f(15.6,1.5);
    glVertex2f(15.7,1.5);
    glVertex2f(15.7,1.3);
    glVertex2f(15.5,1.3);
    glEnd();

    glColor3ub(11, 251, 255);///glass
    glBegin(GL_QUADS);
    glVertex2f(14,1);
    glVertex2f(15.5,1);
    glVertex2f(15.5,0.5);
    glVertex2f(14,0.5);
    glEnd();

}
//W2
void warehouse2()
{


    glBegin(GL_QUADS);                             ///warehouse 2
    glColor3ub(168, 142, 128); //
    glVertex2f(13.5,-0.5);
    glVertex2f(15,-0.5);
    glVertex2f(15,-2);
    glVertex2f(13.5,-2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80, 65, 59 );
    glVertex2f(13.5,-0.7);
    glVertex2f(13.4,-0.7);
    glVertex2f(13.3,-0.6);
    glVertex2f(13.2,-0.6);
    glVertex2f(13.3,-0.8);
    glVertex2f(13.5,-0.8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(192, 146, 126);
    glVertex2f(13,-1);
    glVertex2f(13.5,-1);
    glVertex2f(13.5,-2);
    glVertex2f(13,-2);
    glEnd();

    glColor3ub(11, 251, 255);///glass
    glBegin(GL_QUADS);
    glVertex2f(13.5,-1);
    glVertex2f(15,-1);
    glVertex2f(15,-1.5);
    glVertex2f(13.5,-1.5);
    glEnd();
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(36, 16, 7 );
    glVertex2f(15,-0.5);
    glVertex2f(15,-2);
    glVertex2f(13.5,-0.5);
    glVertex2f(13.5,-2);
    glVertex2f(13.5,-1);
    glVertex2f(15,-1);
    glVertex2f(15,-1.5);
    glVertex2f(13.5,-1.5);
    glVertex2f(13.5,-0.5);
    glVertex2f(15,-0.5);
    glVertex2f(15,-2);
    glVertex2f(13.5,-2);

    glEnd();
}
//H2
void house2() ///house 2,3
{
    glBegin(GL_QUADS);
    glColor3ub(234, 52, 12); // red///shade
    glVertex2f(-9.3, -4.6);
    glVertex2f(-7.9, -4.6);
    glVertex2f(-7.2, -5.4);
    glVertex2f(-8.6, -5.4);
    glEnd();
    glColor3ub(232, 140, 23); // red///shade
    glBegin(GL_POLYGON);
    glVertex2f(-10.1, -5.4);
    glVertex2f(-10, -5.4);
    glVertex2f(-9.3, -4.7);
    glVertex2f(-8.7, -5.4);
    glVertex2f(-8.6, -5.4);
    glVertex2f(-9.3, -4.6);
    glEnd();
    glColor3ub(162, 162, 162);
    glBegin(GL_QUADS);///border
    glVertex2f(-7.2, -6.36);
    glVertex2f(-7.2, -6.40);
    glVertex2f(-10.1, -6.36);
    glVertex2f(-10.1, -6.42);
    glEnd();

    glColor3ub(234, 149, 8);
    glBegin(GL_POLYGON);///iinside 3
    glVertex2f(-10, -6.4);
    glVertex2f(-10, -5.4);
    glVertex2f(-9.3, -4.7);
    glVertex2f(-8.7, -5.4);
    glVertex2f(-8.7, -6.4);
    glEnd();

    glColor3ub(173, 176, 170);///
    glBegin(GL_QUADS);
    glVertex2f(-8.7, -6.4);
    glVertex2f(-7.3, -6.4);
    glVertex2f(-7.3, -5.4);
    glVertex2f(-8.7, -5.4);
    glEnd();

    glColor3ub(11, 251, 255);///glass
    glBegin(GL_QUADS);
    glVertex2f(-8.6, -5.8);
    glVertex2f(-8.4, -5.8);
    glVertex2f(-8.4, -6);
    glVertex2f(-8.6, -6);

    glVertex2f(-8.1, -5.8);
    glVertex2f(-7.9, -5.8);
    glVertex2f(-7.9, -6);
    glVertex2f(-8.1, -6);

    glVertex2f(-7.6, -5.8);
    glVertex2f(-7.4, -5.8);
    glVertex2f(-7.4, -6);
    glVertex2f(-7.6, -6);

    glColor3ub(93, 66, 7);///door
    glVertex2f(-9.5, -5.9);
    glVertex2f(-9.2, -5.9);
    glVertex2f(-9.2, -6.4);
    glVertex2f(-9.5, -6.4);
    glEnd();

    ////////////////////////house 3/////////////
    glBegin(GL_QUADS);
    glColor3ub(234, 52, 12); // red///shade
    glVertex2f(3.6, -6.2);
    glVertex2f(3.9, -5.7);
    glVertex2f(6.3, -5.7);
    glVertex2f(6.5, -6.2);
    glEnd();

    glColor3ub(234, 149, 8);
    glBegin(GL_QUADS);///iinside
    glVertex2f(6.20, -6.2);
    glVertex2f(6.2, -7.3);
    glVertex2f(3.9, -7.3);
    glVertex2f(3.9, -6.2);

    glEnd();

    glBegin(GL_QUADS);///iinside
    glVertex2f(3.9, -7.4);
    glVertex2f(3.9, -8.6);
    glVertex2f(6.2, -8.6);
    glVertex2f(6.2, -7.4);

    glEnd();



    glColor3ub(11, 251, 255);///glass
    glBegin(GL_QUADS);
    glVertex2f(4.1, -6.3);  ///glass 1
    glVertex2f(4.5, -6.3);
    glVertex2f(4.5, -6.8);
    glVertex2f(4.1, -6.8);

    glVertex2f(5.7, -6.3);       ///glass 2
    glVertex2f(6, -6.3);
    glVertex2f(6.1, -6.8);
    glVertex2f(5.7, -6.8);

    glVertex2f(5.7, -7.6);    ///glass 3
    glVertex2f(6.1, -7.6);
    glVertex2f(6.1, -8);
    glVertex2f(5.7, -8);

    glVertex2f(4.9, -7.6);///gllass 4
    glVertex2f(5.3, -7.6);
    glVertex2f(5.3, -8);
    glVertex2f(4.9, -8);

    glVertex2f(4.1, -7.6);
    glVertex2f(4.5, -7.6);
    glVertex2f(4.5, -8);
    glVertex2f(4.1, -8);
    glEnd();
    glColor3ub(152, 160, 164);
    glBegin(GL_QUADS);

    glVertex2f(3.85, -6.2);
    glVertex2f(3.9, -8.6);
    glVertex2f(3.9, -8.7);
    glVertex2f(3.9, -6.2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(3.9, -8.6);
    glVertex2f(3.9, -8.7);
    glVertex2f(6.3, -8.7);
    glVertex2f(6.2, -8.6);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(6.2, -8.6);
    glVertex2f(6.3, -8.7);
    glVertex2f(6.3, -6.2);
    glVertex2f(6.20, -6.2);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(3.8, -7.3);
    glVertex2f(3.8, -7.4);
    glVertex2f(6.7, -7.4);
    glVertex2f(6.7, -7.3);

    glBegin(GL_QUADS);
    glVertex2f(6.3, -6.9);
    glVertex2f(6.7, -6.9);
    glVertex2f(6.7, -7);
    glVertex2f(6.3, -7);
    glEnd();
    glLineWidth(4);
    glBegin(GL_LINES);

    glVertex2f(6.3, -7);
    glVertex2f(6.3, -7.3);
    glVertex2f(6.4, -7);
    glVertex2f(6.4, -7.3);
    glVertex2f(6.5, -7);
    glVertex2f(6.5, -7.3);
    glVertex2f(6.50, -7);
    glVertex2f(6.50, -7.3);
    glVertex2f(6.6, -7);
    glVertex2f(6.6, -7.3);

    glEnd();
}

void vehicle() //V1
{

    glPushMatrix();
    glTranslatef(truckPosition, 0.0f, 0.0f);

    //body
    glColor3ub(27, 75, 61);
    glBegin(GL_POLYGON);
    glVertex2f(-12.1, -4.1);
    glVertex2f(-12.2, -4.2);
    glVertex2f(-12.2, -4.3);
    glVertex2f(-11.6, -4.3);
    glVertex2f(-11.6, -4.2);
    glVertex2f(-11.7, -4.2);
    glVertex2f(-11.9, -4.1);
    glEnd();

    //wheels
    glColor3ub(20, 20, 120);
    circleSolid(-12.1, -4.3, 0.034);
    circleSolid(-12, -4.3, 0.034);
    glColor3ub(130, 130, 130);
    circleSolid(-11.8, -4.3, 0.02);
    circleSolid(-11.8, -4.3, 0.02);

    //window
    glColor3ub(153, 206, 250);
    glBegin(GL_QUADS);
    glVertex2f(-12.1, -4.2);
    glVertex2f(-12.10, -4.22);
    glVertex2f(-12, -4.22);
    glVertex2f(-12, -4.1);

    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-11.9, -4.1);
    glVertex2f(-11.9, -4.2);
    glVertex2f(-11.7, -4.2);
    glVertex2f(-11.8, -4.1);
    glEnd();
    glPopMatrix();
}
                                               ///train //////////////////////////////


// Variables to control smoke animation
float smokeOffset1 = 0.0f;
float smokeOffset2 = 0.2f;
float smokeOffset3 = 0.4f;
float smokeOffset4 = 0.0f;
float smokeOffset5 = 0.2f;
float smokeOffset6 = 0.4f;
float smokeOffset7 = 0.0f;
float smokeOffset8 = 0.2f;
float smokeOffset9 = 0.4f;
float smokeSpeed = 0.01f;

// Function to draw smoke
void drawSmoke(float offset, float x, float y)//DS1
{
    glColor3f(1.0, 1.0, 1.0); // White color
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(100);
        float dx = 0.1f * cosf(theta);
        float dy = 0.1f * sinf(theta);
        glVertex2f(x + dx, y + dy + offset);
    }
    glEnd();
}

// Timer function to update smoke offsets
void timer(int value)
{
    smokeOffset1 += smokeSpeed;
    smokeOffset2 += smokeSpeed;
    smokeOffset3 += smokeSpeed;
    smokeOffset4 += smokeSpeed;
    smokeOffset5 += smokeSpeed;
    smokeOffset6 += smokeSpeed;
    smokeOffset7 += smokeSpeed;
    smokeOffset8 += smokeSpeed;
    smokeOffset9 += smokeSpeed;

    if (smokeOffset1 > 1.0f) smokeOffset1 = 0.0f;
    if (smokeOffset2 > 1.0f) smokeOffset2 = 0.0f;
    if (smokeOffset3 > 1.0f) smokeOffset3 = 0.0f;
    if (smokeOffset4 > 1.0f) smokeOffset4 = 0.0f;
    if (smokeOffset5 > 1.0f) smokeOffset5 = 0.0f;
    if (smokeOffset6 > 1.0f) smokeOffset6 = 0.0f;
    if (smokeOffset7 > 1.0f) smokeOffset7 = 0.0f;
    if (smokeOffset8 > 1.0f) smokeOffset8 = 0.0f;
    if (smokeOffset9 > 1.0f) smokeOffset9 = 0.0f;
    glutPostRedisplay();
    glutTimerFunc(33, timer, 0); // Approximately 30 frames per second
}



void train()//TR1
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(move_train, 0.0f, 0.0f);
    glBegin(GL_QUADS);/// first bogi 1
    glColor3ub(199, 168, 31 );///- orange
    glVertex2f(-12.4,5);
    glVertex2f(-12.3,4.8);
    glVertex2f(-11.9,4.8);
    glVertex2f(-11.8,5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(31, 133, 199 );///blue
    glVertex2f(-12.3,4.8);
    glVertex2f(-12.3,4.3);
    glVertex2f(-11.9,4.3);
    glVertex2f(-11.9,4.8);
    glEnd();
    glBegin(GL_QUADS);///black-blue
    glColor3ub(63, 80, 91 );
    glVertex2f(-11.9,4.6);
    glVertex2f(-11.9,4.3);
    glVertex2f(-11.3,4.3);
    glVertex2f(-11.3,4.6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(89, 92, 94);
    glVertex2f(-12.3,4.3);
    glVertex2f(-12.3,4.1);
    glVertex2f(-11.2,4.1);
    glVertex2f(-11.3,4.3);
    glEnd();
    //wheels
    glColor3ub(47, 51, 54);
    circleSolid(-11.4,4.1, 0.099);
    circleSolid(-11.7, 4.1, 0.099);
    circleSolid(-12.1, 4.1, 0.099);
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-12.5,4.2);
    glVertex2f(-12.3,4.2);
    glVertex2f(-12.3,4.1);
    glVertex2f(-12.5,4.1);
    glEnd();
    glBegin(GL_QUADS);///light ///
    glColor3ub(240, 255, 0 );
    glVertex2f(-11.3,4.6);
    glVertex2f(-11.3,4.5);
    glVertex2f(-11.2,4.5);
    glVertex2f(-11.3,4.4);
    glEnd();


    glBegin(GL_POLYGON);///smoke ///
    glColor3ub(0, 0, 0 );

    glVertex2f(-11.95,5.15);
    glVertex2f(-12,5.1);
    glVertex2f(-12,5);
    glVertex2f(-12.2,5);
    glVertex2f(-12.2,5.1);
    glVertex2f(-12.25,5.15);
    glEnd();
    glColor3ub(120, 120, 118);
    circleSolid( -12.1,5.2,0.059);
    circleSolid(-12.2,5.3,0.079);
    circleSolid(-12.3,5.3,0.089);
    circleSolid(-12.4,5.4,0.099);
    circleSolid(-12.6,5.4,0.099);
    glBegin(GL_QUADS);/// first bogi 2 - orange
    glColor3ub(144, 171, 192 );
    glVertex2f(-13.3,5);
    glVertex2f(-12.5,5);
    glVertex2f(-12.5,4.8);
    glVertex2f(-13.3,4.8);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(199, 168, 31);///blue
    glVertex2f(-13.2,4.8);
    glVertex2f(-12.6,4.8);
    glVertex2f(-12.6,4.3);
    glVertex2f(-13.2,4.3);
    glEnd();
    glBegin(GL_QUADS);///glass
    glColor3ub(104, 185, 245 );
    glVertex2f(-13.1,4.7);
    glVertex2f(-12.9,4.7);
    glVertex2f(-12.9,4.5);
    glVertex2f(-13.1,4.5);

    glVertex2f(-12.8,4.7);
    glVertex2f(-12.6,4.7);
    glVertex2f(-12.6,4.5);
    glVertex2f(-12.8,4.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(89, 92, 94);
    glVertex2f(-13.3,4.3);
    glVertex2f(-13.3,4.1);
    glVertex2f(-12.5,4.1);
    glVertex2f(-12.5,4.3);
    glEnd();
    //wheels
    glColor3ub(47, 51, 54);
    circleSolid(-13.1,4.1, 0.099);
    circleSolid(-12.7, 4.1, 0.099);
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-13.5,4.2);
    glVertex2f(-13.3,4.2);
    glVertex2f(-13.3,4.1);
    glVertex2f(-13.5,4.1);
    glEnd();


    glBegin(GL_QUADS);/// first bogi 3
    glColor3ub(199, 168, 31 );///- orange
    glVertex2f(-14.4,4.9);
    glVertex2f(-14.4,4.8);
    glVertex2f(-13.5,4.8);
    glVertex2f(-13.5,4.9);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(32, 186, 174 );///b
    glVertex2f(-13.6,4.8);
    glVertex2f(-13.6,4.3);
    glVertex2f(-14.4,4.3);
    glVertex2f(-14.4,4.8);
    glEnd();
    glBegin(GL_QUADS);///glass
    glColor3ub(104, 185, 245 );
    glVertex2f(-14.2,4.7);
    glVertex2f(-14,4.7);
    glVertex2f(-14,4.5);
    glVertex2f(-14.2,4.5);

    glVertex2f(-13.8,4.7);
    glVertex2f(-13.6,4.7);
    glVertex2f(-13.6,4.5);
    glVertex2f(-13.8,4.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(89, 92, 94);
    glVertex2f(-14.4,4.3);
    glVertex2f(-14.4,4.1);
    glVertex2f(-13.5,4.1);
    glVertex2f(-13.5,4.3);
    glEnd();
    //wheels
    glColor3ub(47, 51, 54);
    circleSolid(-14.2,4.1, 0.099);
    circleSolid(-13.7, 4.1, 0.099);
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(-14.6,4.2);
    glVertex2f(-14.4,4.2);
    glVertex2f(-14.4,4.1);
    glVertex2f(-14.6,4.1);
    glEnd();

    glBegin(GL_QUADS);/// first bogi 4 - orange
    glColor3ub( 134, 51, 15  );
    glVertex2f(-15.5,5);
    glVertex2f(-15.5,4.8);
    glVertex2f(-14.5,4.8);
    glVertex2f(-14.5,5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(186, 123, 32);///blue
    glVertex2f(-15.4,4.3);
    glVertex2f(-15.4,4.8);
    glVertex2f(-14.6,4.8);
    glVertex2f(-14.6,4.3);
    glEnd();
    glBegin(GL_QUADS);///glass
    glColor3ub(104, 185, 245 );
    glVertex2f(-14.9,4.7);
    glVertex2f(-14.7,4.7);
    glVertex2f(-14.7,4.5);
    glVertex2f(-14.9,4.5);

    glVertex2f(-15.1,4.7);
    glVertex2f(-15.1,4.5);
    glVertex2f(-15.3,4.5);
    glVertex2f(-15.3,4.7);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(89, 92, 94);
    glVertex2f(-15.5,4.3);
    glVertex2f(-15.5,4.1);
    glVertex2f(-14.6,4.1);
    glVertex2f(-14.6,4.3);
    glEnd();
    //wheels
    glColor3ub(47, 51, 54);
    circleSolid(-14.8,4.1, 0.099);
    circleSolid(-15.3, 4.1, 0.099);

    glPopMatrix();

}
void trainline() //TL1
{
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(90, 90, 70);//black
    glVertex2f(-16,2);
    glVertex2f(-1.6,2);
    glVertex2f(16,2);
    glVertex2f(3.1,2);

    glVertex2f(-16,3.7);
    glVertex2f(16,3.7);
    glVertex2f(-16,3.9);
    glVertex2f(16,3.9);

    glVertex2f(-16,4);
    glVertex2f(16,4);

    glVertex2f(-15.6,3.7);///1
    glVertex2f(-15.6,2);
    glVertex2f(-15.4,3.7);
    glVertex2f(-15.4,2);

    glVertex2f(-13.8,3.7);///2
    glVertex2f(-13.8,2);
    glVertex2f(-13.6,3.7);
    glVertex2f(-13.6,2);

    glVertex2f(-11.8,3.7);///3
    glVertex2f(-11.8,2);
    glVertex2f(-11.6,3.7);
    glVertex2f(-11.6,2);

    glVertex2f(-10,3.7);///4
    glVertex2f(-10,2);
    glVertex2f(-9.8,3.7);
    glVertex2f(-9.8,2);

    glVertex2f(-8,3.7);///5
    glVertex2f(-8,2);
    glVertex2f(-7.8,3.7);
    glVertex2f(-7.8,2);

    glVertex2f(-6.2,3.7);///6
    glVertex2f(-6.2,2);
    glVertex2f(-6,3.7);
    glVertex2f(-6,2);

    glVertex2f(-3.2,3.7);///7
    glVertex2f(-3.2,2);
    glVertex2f(-3,3.7);
    glVertex2f(-3,2);

    glVertex2f(-0.4,3.7);///8
    glVertex2f(-0.4,2);
    glVertex2f(-0.2,3.7);
    glVertex2f(-0.2,2);

    glVertex2f(2.4,3.7);///9
    glVertex2f(2.4,2);
    glVertex2f(2.6,3.7);
    glVertex2f(2.6,2);

    glVertex2f(6.2,3.7);///10
    glVertex2f(6.2,2);
    glVertex2f(6.4,3.7);
    glVertex2f(6.4,2);

    glVertex2f(9,3.7);///11
    glVertex2f(9,2);
    glVertex2f(9.2,3.7);
    glVertex2f(9.2,2);

    glVertex2f(11.2,3.7);///12
    glVertex2f(11.2,2);
    glVertex2f(11.4,3.7);
    glVertex2f(11.4,2);

    glVertex2f(12.8,3.7);///13
    glVertex2f(12.8,2);
    glVertex2f(13,3.7);
    glVertex2f(13,2);

    glVertex2f(14.7,3.7);///14
    glVertex2f(14.7,2);
    glVertex2f(14.9,3.7);
    glVertex2f(14.9,2);

    glEnd();


}
void cloud() //BGC
{

    glPushMatrix();


    //
    glColor3ub(237, 249, 253);
    circleSolid(-14.6, 4.8, 1.034);
    circleSolid(-14.2, 3.7, 1.5);
    circleSolid(-13.3, 5.1, 1.5);
    circleSolid(-12.3, 4.4, 1);
    circleSolid(-12, 5.9, 1.7);
    circleSolid(-11, 5, 1);
    circleSolid(-9.5, 6.3, 0.7);
    circleSolid(-9.1, 5.6, 0.8);
    circleSolid(-6.8, 6.2, 0.8);
    circleSolid(-6.5, 5.4, 1);
    circleSolid(-5.4, 6.1, 1.2);
    circleSolid(-5.1, 5, 1);
    circleSolid(-4, 6, 0.5);
    circleSolid(-4.1, 5.3, 1);
    circleSolid(-3.2, 6.8, 0.8);
    circleSolid(-2.7, 6, 1);
    circleSolid(-2.1, 7.3, 0.7);
    circleSolid(-1.8, 6.6, 0.5);
    circleSolid(-1, 6.6, 0.8);
    circleSolid(-1.4, 5.9, 0.7);
    circleSolid(4.6, 5.8, 1.2);
    circleSolid(5.4, 5.1, 0.9);
    circleSolid(6.2, 5.1, 0.7);
    circleSolid(5.5, 4.7, 0.9);
    circleSolid(8, 5.8, 0.8);
    circleSolid(8.6, 5.2, 0.7);
    circleSolid(12.6, 6.3, 1.3);
    circleSolid(14.1, 5.4, 1);
    circleSolid(15.4, 5.6, 1.3);
    // glColor3ub(246, 233, 28);
    //  circleSolid(14.5, 8, 0.7);///sun


    ///cloud 1///
    glPushMatrix();

    glTranslatef(_moveC, 0.0f, 0.0f);
    glPushMatrix();
    glColor3d(220, 220, 218 );
    glTranslatef(-15.3,8.5, 0.1);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(220, 220, 218 );
    glTranslatef(-14.9,8.4, 0.2);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(220, 220, 218 );
    glTranslatef(-14.5, 8, 0.1);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();




    ///cloud 2///


    glPushMatrix();

    glTranslatef(_moveC, 0.0f, 0.0f);
    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(-7.7, 7.8, 0.1);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(-7.3, 8, 0.1);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(-7, 7.9, 0.1);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(-7.4, 7.8, 0.2);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();



    glPopMatrix();

    ///cloud 3///

    glPushMatrix();

    glTranslatef(_moveC, 0.0f, 0.0f);

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(5.9, 7, 0.2);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(6.4, 7.3, 0.1);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(6.8, 7, 0.1);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3d(255, 255, 255);
    glTranslatef(6.4, 6.7, 0.1);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();


    glPopMatrix();




    glPopMatrix();
}
void  car1()//C1
{
    glPushMatrix();
    glTranslatef(carPosition, 0.0f, 0.0f);
    //body
    glColor3ub(255, 255, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-6.9, -4.5);
    glVertex2f(-6.9, -4.6);
    glVertex2f(-6.5, -4.6);
    glVertex2f(-6.5, -4.5);

    glVertex2f(-6.5, -4.4);
    glVertex2f(-6.7, -4.4);
    glVertex2f(-6.8, -4.5);
    glEnd();
    //wheels
    glColor3ub(233, 0, 0);
    circleSolid(-6.8, -4.6, 0.035);
    circleSolid(-6.6, -4.6, 0.035);

    glColor3ub(29, 36, 34);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-6.7, -4.5);
    glVertex2f(-6.7, -4.5);
    glEnd();
    //window
    glColor3ub(153, 206, 250);
    glBegin(GL_QUADS);
    glVertex2f(-6.8, -4.5);
    glVertex2f(-6.7, -4.5);
    glColor3ub(100, 149, 237);
    glVertex2f(-6.7, -4.5);
    glVertex2f(-6.7, -4.4);
    glEnd();
    glColor3ub(153, 206, 250);
    glBegin(GL_QUADS);
    glVertex2f(-6.6, -4.5);
    glVertex2f(-6.6, -4.5);
    glColor3ub(100, 149, 237);
    glVertex2f(-6.5, -4.5);
    glVertex2f(-6.5, -4.5);
    glEnd();
    glPopMatrix();

}

void object2()//HT1
{

    glColor3ub(126, 90, 11);
    glBegin(GL_TRIANGLES);
    glVertex2f(-12.9, -6.7);
    glVertex2f(-12.8, -6.7);
    glVertex2f(-12.8, -6.2);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-12.6, -6.2);
    glVertex2f(-12.7, -6.7);
    glVertex2f(-12.5, -6.7);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-10.6, -6.4);
    glVertex2f(-10.4, -6.4);
    glVertex2f(-10.5, -5.7);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-10.2, -5.8);
    glVertex2f(-10.3, -6.4);
    glVertex2f(-10.1, -6.4);
    glEnd();

    glColor3ub(74, 172, 48);
    circleSolid(-10.7, -5.9, 0.091);
    circleSolid(-10.6, -6.1, 0.095);
    circleSolid(-10.5, -5.7, 0.095);
    circleSolid(-10.5, -5.9, 0.095);
    circleSolid(-10.4, -5.9, 0.095);
    circleSolid(-10.4, -6.1, 0.095);
    circleSolid(-10.2, -5.8, 0.091);
    circleSolid(-10.3, -6, 0.095);
    circleSolid(-10.1, -5.9, 0.095);

    circleSolid(-12.8, -6.1, 0.091);
    circleSolid(-12.9, -6.3, 0.095);
    circleSolid(-12.8, -6.3, 0.095);
    circleSolid(-12.8, -6.3, 0.091);
    circleSolid(-12.5, -6.4, 0.095);
    circleSolid(-12.6, -6.1, 0.095);
    circleSolid(-12.6, -6.3, 0.095);
    circleSolid(-12.6, -6.3, 0.095);
    glPopMatrix();

}
void object4()                                ///left sidewise border partition
{
    glPushMatrix();
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(147, 116, 39);
    glVertex2f(9.7, -9);
    glVertex2f(9.8, -9);
    glVertex2f(10, -8.4);
    glVertex2f(9.6, -7.9);
    glVertex2f(8.2, -7);
    glVertex2f(8.3, -7.2);
    glVertex2f(9.7, -8);
    glVertex2f(9.9, -8.5);

    glEnd();

    //polygon 2
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glVertex2f(8.3, -7.2);
    glVertex2f(8.2, -7);
    glVertex2f(6.3, -6.3);
    glVertex2f(4.9, -5.6);
    glVertex2f(4.9, -5.8);
    glVertex2f(6.5, -6.5);
    glEnd();

    //polygon 3
    glBegin(GL_POLYGON);
    glVertex2f(4.9, -5.8);
    glVertex2f(4.9, -5.6);
    glVertex2f(4.7, -5.2);
    glVertex2f(4.8, -5);
    glVertex2f(5.7, -4.6);
    glVertex2f(5.7, -4.5);
    glVertex2f(5.4, -4.6);
    glVertex2f(4.5, -5);

    glEnd();


    //polygon 4
    glBegin(GL_POLYGON);
    glVertex2f(5.7, -4.6);
    glVertex2f(5.9, -2.7);
    glVertex2f(4.4, -1.5);
    glVertex2f(4.1, -2);
    glVertex2f(5.7, -2.8);
    glVertex2f(5.7, -4.5);
    glEnd();


    //polygon 5
    glBegin(GL_POLYGON);
    glVertex2f(4.4, -1.5);
    glVertex2f(3.6, -0.7);
    glVertex2f(-0.4, -0.4);
    glVertex2f(-3.2, 0.1);
    glVertex2f(-3.4, 1.5);
    glVertex2f(-3.5, 1.5);
    glVertex2f(-3.4, 0);
    glVertex2f(-1, -0.5);
    glVertex2f(2.3, -0.7);
    glVertex2f(3.6, -0.9);
    glVertex2f(4.2, -1.4);
    glVertex2f(4.1, -2);
    glEnd();



    //polygon 6
    glBegin(GL_POLYGON);
    glVertex2f(-3.5, 1.5);
    glVertex2f(-2.8, 1.7);
    glVertex2f(-1.3, 1.8);
    glVertex2f(-1.2, 2);
    glVertex2f(0, 2);
    glVertex2f(0, 1.9);
    glVertex2f(-1.2, 1.8);
    glVertex2f(-1.3, 1.7);
    glVertex2f(-3.4, 1.5);
    glEnd();
    glBegin(GL_POLYGON);

    glVertex2f(-7.3,-7.3);
    glVertex2f(-7.3,-6.9);
    glVertex2f(-7,-6.6);
    glVertex2f(-6.5,-6.3);
    glVertex2f(-5.9,-6.1);
    glVertex2f(-6,-6.2);
    glVertex2f(-6.5,-6.4);
    glVertex2f(-7.2,-6.8);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-5.9,-6.1);
    glVertex2f(-5.3,-6.1);
    glVertex2f(-3.1,-6.1);
    glVertex2f(-0.3,-6.1);
    glVertex2f(0.8,-6.2);
    glVertex2f(1.9,-6.4);
    glVertex2f(1.8,-6.4);
    glVertex2f(0.8,-6.2);
    glVertex2f(-0.3,-6.2);
    glVertex2f(-5.3,-6.1);
    glVertex2f(-6,-6.2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(1.9,-6.4);
    glVertex2f(2.2,-6.5);
    glVertex2f(2.4,-6.8);
    glVertex2f(2.5,-7);
    glVertex2f(2.5,-7.4);

    glVertex2f(2.4,-7);
    glVertex2f(2.2,-6.6);
    glVertex2f(1.8,-6.4);

    glEnd();
    glBegin(GL_POLYGON);

    glVertex2f(12.9,-2.6);
    glVertex2f(11.9,-2.3);
    glVertex2f(10.6,-1.9);
    glVertex2f(9.1,-1.7);
    glVertex2f(8.3,-1.5);
    glVertex2f(8.4,-1.3);
    glVertex2f(8.1,-1.5);
    glVertex2f(8.4,-1.8);
    glVertex2f(9.6,-2);
    glVertex2f(11.3,-2.3);
    glVertex2f(12.2,-2.6);
    glVertex2f(12.8,-2.6);
    glEnd();
    glPopMatrix();

}

void river()                              ///river
{

    glPushMatrix();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(50, 193, 231);
    glVertex2f(16, -9);
    glVertex2f(16, -7);
    glVertex2f(8.2, -7);
    glVertex2f(9.6, -7.9);
    glVertex2f(10, -8.4);
    glVertex2f(9.8, -9);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(8.2, -7);
    glVertex2f(16, -7);
    glVertex2f(16, -5.7);
    glVertex2f(4.9, -5.6);
    glVertex2f(6.3, -6.3);

    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(4.9, -5.6);
    glVertex2f(4.7, -5.2);
    glVertex2f(4.8, -5);
    glVertex2f(5.7, -4.6);
    glVertex2f(16, -4.6);
    glVertex2f(16, -5.7);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(-1.1,-8.3);
    glVertex2f(0.7,-8.2);
    glVertex2f(1.3,-8.1);
    glVertex2f(2.5,-7.4);
    glVertex2f(2.4,-7);
    glVertex2f(2.2,-6.6);
    glVertex2f(1.8,-6.4);
    glVertex2f(0.8,-6.2);
    glVertex2f(-0.3,-6.2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.3,-6.2);
    glVertex2f(-1.1,-8.3);
    glVertex2f(-2.5,-8.3);
    glVertex2f(-4.6,-8.2);
    glVertex2f(-5.9,-8.1);
    glVertex2f(-5.3,-6.1);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-5.9,-8.1);
    glVertex2f(-5.3,-6.1);
    glVertex2f(-6,-6.2);
    glVertex2f(-6.5,-6.4);
    glVertex2f(-6.7,-6.68);
    glVertex2f(-6.85,-7.17);
    glVertex2f(-6.9,-7.7);
    glVertex2f(-6.3,-8);
    glEnd();

    glBegin(GL_POLYGON);                 ///upper side
    glVertex2f(-3.4,0);
    glVertex2f(-1,-0.5);
    glVertex2f(3.6,-0.9);
    glVertex2f(6.7,0.1);
    glVertex2f(2.5,0.9);
    glVertex2f(-1.6,0.8);

    glEnd();

    glBegin(GL_POLYGON);                ///upper side
    glVertex2f(3.6,-0.9);
    glVertex2f(4.5,-1);
    glVertex2f(4.2,-1.8);
    glVertex2f(5.7,-2.8);
    glVertex2f(6.3,-2.8);
    glVertex2f(8.4,-1.3);
    glVertex2f(11,-0.6);
    glVertex2f(10.7,-0.4);
    glVertex2f(6.7,0.1);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(6.3,-2.8);
    glVertex2f(6.9,-2.8);
    glVertex2f(6.9,-3.3);

    glVertex2f(8,-3.3);
    glVertex2f(8.1,-2.5);
    glVertex2f(9,-2.5);
    glVertex2f(9.2,-3.3);
    glVertex2f(9.6,-2);
    glVertex2f(8.4,-1.8);
    glVertex2f(8.1,-1.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(9.2,-3.3);
    glVertex2f(10.3,-3.3);
    glVertex2f(10.5,-2.5);
    glVertex2f(11.4,-2.5);
    glVertex2f(11.6,-3.3);
    glVertex2f(12.7,-3.3);
    glVertex2f(12.8,-2.9);
    glVertex2f(12.2,-2.6);
    glVertex2f(11.3,-2.3);

    glVertex2f(9.6,-2);
    glEnd();
    glPopMatrix();
}


void dam()//D1
{

    glPushMatrix();


    glColor3ub(97, 100, 88);
    glBegin(GL_POLYGON);
    glVertex2f(2.7,2.4);
    glVertex2f(3.1,2.3);
    glVertex2f(3.2,1.5);
    glVertex2f(2.5,0.9);
    glVertex2f(2.4,0.9);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-1.6,2.3);
    glVertex2f(-1.2,2.4);
    glVertex2f(-0.9,0.8);
    glVertex2f(-1.6,0.8);
    glVertex2f(-1.7,1.6);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-1.2,2.4);
    glVertex2f(-0.9,2.3);
    glVertex2f(-0.7,0.8);
    glVertex2f(-0.9,0.8);

    glVertex2f(2.4,0.9);
    glVertex2f(2.2,0.9);
    glVertex2f(2.34,2.26);
    glVertex2f(2.7,2.4);


    glEnd();


    glColor3ub(194, 208, 209);
    glBegin(GL_QUADS);/// piller
    glVertex2f(-0.9,2.3);
    glVertex2f(-0.8,2.3);
    glVertex2f(-0.6,0.8);
    glVertex2f(-0.7,0.8);

    glVertex2f(0,0.9);
    glVertex2f(0.1,0.9);
    glVertex2f(0,2.4);
    glVertex2f(-0.1,2.3);

    glVertex2f(0.7,2.4);
    glVertex2f(0.8,2.4);
    glVertex2f(0.9,0.9);
    glVertex2f(0.6,0.9);

    glVertex2f(1.4,0.9);
    glVertex2f(1.5,0.9);
    glVertex2f(1.6,2.4);
    glVertex2f(1.5,2.4);

    glVertex2f(2.27,2.27);
    glVertex2f(2.34,2.26);
    glVertex2f(2.21,0.90);
    glVertex2f(2.1,0.9);
    glEnd();

    glColor3ub(70, 134, 156);
    glBegin(GL_QUADS);
    glVertex2f(-0.6,0.8);
    glVertex2f(0,0.9);
    glVertex2f(-0.1,2.2);
    glVertex2f(-0.8,2.1);

    glVertex2f(0,2.2);
    glVertex2f(0.7,2.2);
    glVertex2f(0.6,0.9);
    glVertex2f(0.1,0.9);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.8,2.2);
    glVertex2f(1.5,2.2);
    glVertex2f(1.4,0.9);
    glVertex2f(0.9,0.9);

    glVertex2f(1.5,0.9);
    glVertex2f(2.1,0.9);
    glVertex2f(2.22,2.1);
    glVertex2f(1.6,2.2);
    glEnd();

///dam///////////////////////////

    glColor3ub(100, 101, 96);
    glBegin(GL_QUADS);
    glVertex2f(5.7,-2.8);
    glVertex2f(6.9,-2.8);
    glVertex2f(6.9,-4.6);
    glVertex2f(5.7,-4.6);


    glVertex2f(15,-2.8);
    glVertex2f(16,-2.8);
    glVertex2f(16,-4.6);
    glVertex2f(15,-4.6);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(111, 118, 111);
    glVertex2f(6.9,-3.3);
    glVertex2f(6.9,-3.6);
    glVertex2f(14.9,-3.6);
    glVertex2f(14.9,-3.3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(113, 118, 111);
    glVertex2f(8.1,-2.5);
    glVertex2f(9,-2.5);
    glVertex2f(9.2,-3.3);
    glVertex2f(8,-3.3);

    glVertex2f(10.5,-2.5);
    glVertex2f(11.4,-2.5);
    glVertex2f(11.6,-3.3);
    glVertex2f(10.3,-3.3);

    glVertex2f(12.9,-2.5);
    glVertex2f(13.8,-2.5);
    glVertex2f(14,-3.3);
    glVertex2f(12.7,-3.3);

    glEnd();
    glColor3ub(70, 134, 156);
    glBegin(GL_QUADS);
    glVertex2f(6.9,-3.6);
    glVertex2f(8.3,-3.6);
    glVertex2f(8.3,-4.6);
    glVertex2f(6.9,-4.6);

    glVertex2f(8.8,-3.6);
    glVertex2f(10.6,-3.6);
    glVertex2f(10.6,-4.6);
    glVertex2f(8.8,-4.6);

    glVertex2f(11.2,-3.6);
    glVertex2f(13,-3.6);
    glVertex2f(13,-4.6);
    glVertex2f(11.2,-4.6);

    glVertex2f(13.6,-3.6);
    glVertex2f(15,-3.6);
    glVertex2f(15,-4.6);
    glVertex2f(13.6,-4.6);

    glEnd();
    glColor3ub(100, 101, 96);
    glBegin(GL_QUADS);
    glVertex2f(8.3,-3.6);
    glVertex2f(8.8,-3.6);
    glVertex2f(8.8,-4.6);
    glVertex2f(8.3,-4.6);

    glVertex2f(10.6,-3.6);
    glVertex2f(11.2,-3.6);
    glVertex2f(11.2,-4.6);
    glVertex2f(10.6,-4.6);

    glVertex2f(13,-3.6);
    glVertex2f(13.6,-3.6);
    glVertex2f(13.6,-4.6);
    glVertex2f(13,-4.6);


    glEnd();
    glPopMatrix();
}

void land()                                  ///land
{

    glPushMatrix();

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(36, 96, 16);
    glVertex2f(-16, -9);
    glVertex2f(-16, -4.6);
    glVertex2f(5.4, -4.6);
    glVertex2f(4.5, -5);
    glVertex2f(4.9, -5.8);
    glVertex2f(6.5, -6.5);
    glVertex2f(8.3, -7.2);
    glVertex2f(9.7, -8);
    glVertex2f(9.9, -8.5);
    glVertex2f(9.7, -9);

    glEnd();

    glBegin(GL_POLYGON);///upper land

    glVertex2f(-16, 15);
    glVertex2f(-16, -4.2);
    glVertex2f(4.6, -4.2);
    glVertex2f(5.4, -4.6);
    glVertex2f(5.7, -4.5);
    glVertex2f(5.7, -2.8);
    glVertex2f(4.1, -2);
    glVertex2f(4.2, -1.4);
    glVertex2f(3.6, -0.9);
    glVertex2f(2.3, -0.7);
    glVertex2f(-1, -0.5);
    glVertex2f(3.4, 0);
    glVertex2f(-3.5, 1.5);
    glEnd();

    glBegin(GL_POLYGON);///upper land

    glVertex2f(2.5,0.9);
    glVertex2f(3.7,2);
    glVertex2f(16,2);
    glVertex2f(11.1,-0.5);
    glVertex2f(10.8,-0.3);
    glVertex2f(6.9,0.2);
    glVertex2f(6.7,0.1);
    glEnd();

    glBegin(GL_POLYGON);/// dam side land
    glVertex2f(16,2);
    glVertex2f(10.8,-0.3);
    glVertex2f(11.1,-0.5);
    glVertex2f(11.1,-0.6);
    glVertex2f(8.4,-1.3);
    glVertex2f(8.3,-1.5);
    glVertex2f(9.1,-1.7);
    glVertex2f(10.6,-1.9);
    glVertex2f(11.9,-2.3);
    glVertex2f(12.9,-2.6);
    glVertex2f(12.9,-2.5);
    glVertex2f(13.8,-2.5);
    glVertex2f(14,-3.3);
    glVertex2f(14.9,-3.3);
    glVertex2f(15,-2.8);
    glVertex2f(16,-2.8);
    glEnd();
    glBegin(GL_TRIANGLES);/// dam side land
    glVertex2f(3.1,2);
    glVertex2f(3.7,2);
    glVertex2f(3.2,1.5);
    glEnd();
    glPopMatrix();
}

void school()//SCL12
{

    glPushMatrix();

    glBegin(GL_QUADS);// Draw a Red 1x1 Square centered at origin
    glColor3ub(85, 62, 23);
    glVertex2f(-15.8, -1.1);
    glVertex2f(-13.5, -1.1);
    glVertex2f(-13.5, -1.4);
    glVertex2f(-16, -1.4);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-13.6, -0.4);
    glVertex2f(-13.8, -0.8);
    glVertex2f(-10.5, -0.8);
    glVertex2f(-10.5, -0.4);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-8.9, -0.4);
    glVertex2f(-8.9, -0.9);
    glVertex2f(-5.6, -0.8);
    glVertex2f(-5.8, -0.4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-5.8, -1.1);
    glVertex2f(-5.9, -1.3);
    glVertex2f(-5.9, -1.4);
    glVertex2f(-5.7, -1.4);
    glVertex2f(-3.1, -1.4);
    glVertex2f(-3.2, -1);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(-9.7, 1.6);
    glVertex2f(-10.7, 0.4);
    glVertex2f(-8.7, 0.4);
    glEnd();
    glColor3ub(241, 193, 114);///middle building
    glBegin(GL_POLYGON);
    glVertex2f(-10.5, 0.4);
    glVertex2f(-8.9, 0.4);
    glVertex2f(-8.9, -3.7);
    glVertex2f(-10.5, -3.7);
    glVertex2f(-10.5, -2.2);
    glVertex2f(-10.5, -2.1);
    glVertex2f(-10.5, 0.4);

    glEnd();
    glColor3ub(193, 172, 97);
    glBegin(GL_POLYGON);///building 2
    glVertex2f(-10.5, -0.8);
    glVertex2f(-10.5, -2.1);
    glVertex2f(-10.5, -2.2);
    glVertex2f(-10.5, -3.7);
    glVertex2f(-13.8, -3.7);
    glVertex2f(-13.7, -3.7);
    glVertex2f(-13.7, -2.1);
    glVertex2f(-13.5, -2.1);
    glVertex2f(-13.5, -0.8);
    glEnd();
    glBegin(GL_POLYGON);///building 3
    glVertex2f(-8.9, -0.9);
    glVertex2f(-8.9, -3.7);
    glVertex2f(-5.6, -3.7);
    glVertex2f(-5.7, -2.2);
    glVertex2f(-5.6, -2.2);
    glVertex2f(-5.6, -2.1);
    glVertex2f(-5.9, -2.1);
    glVertex2f(-5.9, -0.8);

    glEnd();
    glColor3ub(164, 129, 7);///building 1
    glBegin(GL_POLYGON);

    glVertex2f(-15.7, -1.4);
    glVertex2f(-15.8, -3.7);
    glVertex2f(-13.7, -3.7);
    glVertex2f(-13.7, -2.1);
    glVertex2f(-13.5, -2.1);
    glVertex2f(-13.5, -1.4);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-5.7, -1.4);
    glVertex2f(-5.7, -2.1);
    glVertex2f(-5.6, -2.1);
    glVertex2f(-5.6, -2.2);
    glVertex2f(-5.7, -2.2);
    glVertex2f(-5.7, -3.7);
    glVertex2f(-3.3, -3.7);
    glVertex2f(-3.3, -1.4);
    glEnd();



    glColor3ub(1, 65, 58);
    glRasterPos2i(-10.99, -1.2);


    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'S');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'C');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'H');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'O');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'O');
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'L');


    glColor3ub(6, 47, 75);////////////////////
    glBegin(GL_QUADS);
    glVertex2f(-10.5, -2.1);
    glVertex2f(-10.5, -2.2);
    glVertex2f(-13.7, -2.2);
    glVertex2f(-13.7, -2.1);
    glVertex2f(-8.9, -2.1);
    glVertex2f(-8.9, -2.2);
    glVertex2f(-5.6, -2.2);
    glVertex2f(-5.6, -2.1);

    glEnd();

    glColor3ub(11, 251, 255);///glass/////////////////
    glBegin(GL_QUADS);
    glVertex2f(-5.4, -1.6);
    glVertex2f(-5, -1.6);
    glVertex2f(-5, -1.8);
    glVertex2f(-5.4, -1.8);

    glVertex2f(-5, -1.6);
    glVertex2f(-5, -1.8);
    glVertex2f(-4.6, -1.8);
    glVertex2f(-4.6, -1.6);

    glVertex2f(-4.6, -1.8);
    glVertex2f(-4.6, -1.6);
    glVertex2f(-4.2, -1.6);
    glVertex2f(-4.2, -1.8);

    glVertex2f(-4.2, -1.6);
    glVertex2f(-4.2, -1.8);
    glVertex2f(-3.8, -1.8);
    glVertex2f(-3.8, -1.6);

    glVertex2f(-3.8, -1.8);
    glVertex2f(-3.8, -1.6);
    glVertex2f(-3.5, -1.6);
    glVertex2f(-3.5, -1.8);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-5.4, -2.2);
    glVertex2f(-5.4, -2.4);
    glVertex2f(-3.5, -2.4);
    glVertex2f(-3.5, -2.2);

    glVertex2f(-3.5, -2.6);
    glVertex2f(-3.5, -2.8);
    glVertex2f(-5.4, -2.8);
    glVertex2f(-5.4, -2.6);


    glVertex2f(-3.5, -3.1);
    glVertex2f(-3.5, -3.4);
    glVertex2f(-5.4, -3.4);
    glVertex2f(-5.4, -3.1);

    glVertex2f(-11, -2.4);///2///lower
    glVertex2f(-11, -2.7);
    glVertex2f(-13.4, -2.7);
    glVertex2f(-13.4, -2.4);

    glVertex2f(-11, -3.1);///2///lower
    glVertex2f(-11, -3.4);
    glVertex2f(-13.4, -3.4);
    glVertex2f(-13.4, -3.1);

    glVertex2f(-8.6, -1);///3///upper
    glVertex2f(-8.6, -1.2);
    glVertex2f(-6.2, -1.2);
    glVertex2f(-6.2, -1);


    glVertex2f(-8.6, -1.6);///3///upper
    glVertex2f(-6.2, -1.6);
    glVertex2f(-6.2, -1.8);
    glVertex2f(-8.6, -1.8);

    glVertex2f(-6, -2.4);///3
    glVertex2f(-6, -2.7);
    glVertex2f(-8.4, -2.7);
    glVertex2f(-8.4, -2.4);

    glVertex2f(-6, -3.1);///3
    glVertex2f(-6, -3.4);
    glVertex2f(-8.4, -3.4);
    glVertex2f(-8.4, -3.1);

    glVertex2f(-10.8, -1);///2///upper
    glVertex2f(-10.8, -1.2);
    glVertex2f(-13.2, -1.2);
    glVertex2f(-13.2, -1);

    glVertex2f(-10.8, -1.6);///2///upper
    glVertex2f(-10.8, -1.8);
    glVertex2f(-13.2, -1.8);
    glVertex2f(-13.2, -1.6);


    glVertex2f(-15.5, -1.6);///1///
    glVertex2f(-15.5, -1.8);
    glVertex2f(-14, -1.8);
    glVertex2f(-14, -1.6);
    glVertex2f(-15.5, -2.2);
    glVertex2f(-15.5, -2.4);
    glVertex2f(-14, -2.4);
    glVertex2f(-14, -2.2);
    glVertex2f(-15.5, -2.6);
    glVertex2f(-15.5, -2.8);
    glVertex2f(-14, -2.8);
    glVertex2f(-14, -2.6);
    glVertex2f(-15.5, -3.1);
    glVertex2f(-14, -3.1);
    glVertex2f(-14, -3.4);
    glVertex2f(-15.5, -3.4);

    glVertex2f(-10.3, -1.6);
    glVertex2f(-10.3, -2);
    glVertex2f(-9, -2);
    glVertex2f(-9, -1.6);
    glColor3ub(70, 47, 12);///door
    glVertex2f(-10.2, -2.9);
    glVertex2f(-10.2, -3.7);
    glVertex2f(-9.2, -3.7);
    glVertex2f(-9.2, -2.9);

    glEnd();
    glColor3ub(11, 9, 4);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(-5, -1.6);
    glVertex2f(-5, -1.8);
    glVertex2f(-4.6, -1.8);
    glVertex2f(-4.6, -1.6);
    glVertex2f(-4.2, -1.6);
    glVertex2f(-4.2, -1.8);
    glVertex2f(-3.8, -1.8);
    glVertex2f(-3.8, -1.6);
    glVertex2f(-5, -3.1);
    glVertex2f(-5, -3.4);
    glVertex2f(-4.6, -3.1);
    glVertex2f(-4.6, -3.4);

    glVertex2f(-4.2, -3.1);
    glVertex2f(-4.2, -3.4);
    glVertex2f(-3.8, -3.1);
    glVertex2f(-3.8, -3.4);


    glVertex2f(-5, -2.6);
    glVertex2f(-5, -2.8);
    glVertex2f(-4.6, -2.6);
    glVertex2f(-4.6, -2.8);


    glVertex2f(-4.2, -2.6);
    glVertex2f(-4.2, -2.8);
    glVertex2f(-3.8, -2.6);
    glVertex2f(-3.8, -2.8);
    glVertex2f(-3.8, -2.2);
    glVertex2f(-3.8, -2.4);
    glVertex2f(-4.2, -2.4);
    glVertex2f(-4.2, -2.2);


    glVertex2f(-4.6, -2.4);
    glVertex2f(-4.6, -2.2);
    glVertex2f(-5, -2.4);
    glVertex2f(-5, -2.2);


    glVertex2f(-7.8, -2.4);
    glVertex2f(-7.8, -2.7);
    glVertex2f(-7.2, -2.4);
    glVertex2f(-7.2, -2.7);

    glVertex2f(-6.6, -2.4);
    glVertex2f(-6.6, -2.7);
    glVertex2f(-6.6, -3.1);
    glVertex2f(-6.6, -3.4);

    glVertex2f(-7.2, -3.1);
    glVertex2f(-7.2, -3.4);
    glVertex2f(-7.8, -3.1);
    glVertex2f(-7.8, -3.4);
    glVertex2f(-12.8, -2.4);
    glVertex2f(-12.8, -2.7);
    glVertex2f(-12.2, -2.4);
    glVertex2f(-12.2, -2.7);
    glVertex2f(-11.6, -2.4);
    glVertex2f(-11.6, -2.7);
    glVertex2f(-11.6, -3.1);
    glVertex2f(-11.6, -3.4);
    glVertex2f(-12.2, -3.1);
    glVertex2f(-12.2, -3.4);
    glVertex2f(-12.8, -3.1);
    glVertex2f(-12.8, -3.4);

    glVertex2f(-6.8, -1);
    glVertex2f(-6.8, -1.2);
    glVertex2f(-7.4, -1);
    glVertex2f(-7.4, -1.2);
    glVertex2f(-8, -1);
    glVertex2f(-8, -1.2);
    glVertex2f(-8, -1.6);
    glVertex2f(-8, -1.8);
    glVertex2f(-7.4, -1.6);
    glVertex2f(-7.4, -1.8);
    glVertex2f(-6.8, -1.8);
    glVertex2f(-6.8, -1.6);

    glVertex2f(-12.6, -1);
    glVertex2f(-12.6, -1.2);
    glVertex2f(-12, -1);
    glVertex2f(-12, -1.2);
    glVertex2f(-11.4, -1);
    glVertex2f(-11.4, -1.2);
    glVertex2f(-12.6, -1.6);
    glVertex2f(-12.6, -1.8);
    glVertex2f(-12, -1.6);
    glVertex2f(-12, -1.8);
    glVertex2f(-11.4, -1.6);
    glVertex2f(-11.4, -1.8);

    glVertex2f(-15.2, -3.1);
    glVertex2f(-15.2, -3.4);
    glVertex2f(-14.8, -3.1);
    glVertex2f(-14.8, -3.4);
    glVertex2f(-14.4, -3.1);
    glVertex2f(-14.4, -3.4);
    glVertex2f(-15.2, -2.6);
    glVertex2f(-15.2, -2.8);
    glVertex2f(-14.8, -2.6);
    glVertex2f(-14.8, -2.8);
    glVertex2f(-14.4, -2.6);
    glVertex2f(-14.4, -2.8);
    glVertex2f(-15.2, -2.2);
    glVertex2f(-15.2, -2.4);
    glVertex2f(-14.8, -2.2);
    glVertex2f(-14.8, -2.4);
    glVertex2f(-14.4, -2.2);
    glVertex2f(-14.4, -2.4);
    glVertex2f(-15.2, -1.6);
    glVertex2f(-15.2, -1.8);
    glVertex2f(-14.8, -1.6);
    glVertex2f(-14.8, -1.8);
    glVertex2f(-14.4, -1.6);
    glVertex2f(-14.4, -1.8);

    glEnd();

    glPopMatrix();
}

void boat() //BT
{


                   ///boat-1 motion left to right
    glPushMatrix();
    //glColor3d(218, 142, 11);
    glTranslatef(_moveA, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(70, 47, 12);
    glVertex2f(10.8, -8.6);
    glVertex2f(11, -8.8);
    glVertex2f(11.8, -8.8);
    glVertex2f(12, -8.6);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(193, 218, 11);
    glVertex2f(11.2, -8.4);
    glVertex2f(11.4, -8.6);
    glVertex2f(11.8, -8.6);
    glVertex2f(11.6, -8.4);
    glEnd();
    glColor3ub(218, 142, 11);
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(11, -8.6);
    glVertex2f(11.2, -8.6);
    glVertex2f(11.2, -8.4);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(11.2, -8.6);
    glVertex2f(11.2, -8.4);
    glVertex2f(11.4, -8.6);

    glEnd();

                                 ///boat-2 motion left to right
    // glPushMatrix();

    glTranslatef(_moveA, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(52, 38, 15);
    glVertex2f(9.6, -7.2);
    glVertex2f(10, -7.4);
    glVertex2f(11.2, -7.4);
    glVertex2f(11.6, -7.2);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(245, 178, 62);
    glVertex2f(10.2, -7);
    glVertex2f(11, -7);
    glVertex2f(11.2, -7.2);
    glVertex2f(10.4, -7.2);
    glEnd();
    glColor3ub(239, 245, 62);
    glBegin(GL_TRIANGLES);

    glVertex2f(10.2, -7);
    glVertex2f(10.4, -7.2);
    glVertex2f(10, -7.2);


    glEnd();


    glPopMatrix();
}


void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    //  glLoadIdentity();
    // gluOrtho2D(-16, 16, -9, 9);
    glMatrixMode(GL_MODELVIEW);
}


float CLOCK_RADIUS = 200.0f;
const float HOUR_HAND_LENGTH = 0.5f * CLOCK_RADIUS;
const float MINUTE_HAND_LENGTH = 0.8f * CLOCK_RADIUS;
const float SECOND_HAND_LENGTH = 0.9f * CLOCK_RADIUS;

// Function to draw a solid circle
void circlesolid(float cx, float cy, float r)
{
    int num_segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++)
    {
        float theta = 2.0f * M_PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

// Function to draw clock hands
void drawClockHands(float cx, float cy, int hours, int minutes, int seconds)
{
    // Calculate angles for each hand
    float hourAngle = 2.5 * M_PI - hours * (360.0f / 12.0f) * M_PI / 180.0f;
    float minuteAngle = 2.5 * M_PI - minutes * (360.0f / 60.0f) * M_PI / 180.0f;
    float secondAngle = 2.5 * M_PI - seconds * (360.0f / 60.0f) * M_PI / 180.0f;

    // Draw hour hand
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(cx, cy);
    glVertex2f(cx + HOUR_HAND_LENGTH * cos(hourAngle), cy + HOUR_HAND_LENGTH * sin(hourAngle));
    glEnd();

    // Draw minute hand
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    glLineWidth(2.5f);
    glBegin(GL_LINES);
    glVertex2f(cx, cy);
    glVertex2f(cx + MINUTE_HAND_LENGTH * cos(minuteAngle), cy + MINUTE_HAND_LENGTH * sin(minuteAngle));
    glEnd();

    // Draw second hand
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2f(cx, cy);
    glVertex2f(cx + SECOND_HAND_LENGTH * cos(secondAngle), cy + SECOND_HAND_LENGTH * sin(secondAngle));
    glEnd();
}

void _clock()//CLK
{
    // Get current time
    time_t rawTime;
    struct tm* timeInfo;
    time(&rawTime);
    timeInfo = localtime(&rawTime);

    // Adjust for Dhaka time (UTC+6 BST)
    int hours = (timeInfo->tm_hour + 6) % 24;
    int minutes = timeInfo->tm_min;
    int seconds = timeInfo->tm_sec;

    // Draw clock face
    glPushMatrix();
    glTranslatef(-9.7, -0.2, 0);
    glScalef(0.002, 0.002, 0.002);
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    circlesolid(-9.7, -0.2, 0.4); // Draw a solid circle at the center
    circlesolid(0, 0, CLOCK_RADIUS); // Draw clock circle

    // Draw clock hands
    drawClockHands(0, 0, hours, minutes, seconds);
    glPopMatrix();
}

///hill/////////////////
void hill ()//HL1
{
    glBegin(GL_TRIANGLES);
    glColor3ub(10, 90, 12);
    glVertex2f(12.5,2.2);
    glVertex2f(13,1.5);
    glVertex2f(12.4,1.5);
    glEnd();
    glBegin(GL_TRIANGLES);
    glVertex2f(13,1.5);
    glVertex2f(13.5,2.8);
    glVertex2f(14.2,1.5);

    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(14.1,1.5);
    glVertex2f(13.8,2.21);
    glVertex2f(14.3,3);
    glVertex2f(14.8,1.5);

    glVertex2f(12.6,2);
    glVertex2f(12.9,2.7);
    glVertex2f(13.4,2.3);
    glVertex2f(13,1.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(14.3,2.8);
    glVertex2f(14.8,3.2);
    glVertex2f(16,2.8);
    glVertex2f(16,2);
    glVertex2f(14.8,1.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(14.1,2.9);
    glVertex2f(15,2.4);
    glVertex2f(15,1.7);
    glVertex2f(13.1,1.5);
    glVertex2f(13.5,2.5);

    glEnd();
                                        ///hill 2
    glBegin(GL_POLYGON);
    glVertex2f(-6,1);
    glVertex2f(-5.4,3.4);
    glVertex2f(-4.5,2);
    glVertex2f(-3.8,3.3);
    glVertex2f(-3.2,1);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-3.2,1);
    glVertex2f(-3.7,2.6);
    glVertex2f(-3.1,3.5);
    glVertex2f(-2.4,2.5);
    glVertex2f(-2,3);
    glVertex2f(-1.6,2);
    glVertex2f(-1.6,1);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-5,2.7);
    glVertex2f(-4.5,3.5);
    glVertex2f(-4.1,2.8);
    glVertex2f(-4.5,2);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(2.5,0.9);
    glVertex2f(3.1,2.3);
    glVertex2f(3.8,3.1);
    glVertex2f(4.2,2.6);
    glVertex2f(4.4,2.9);
    glVertex2f(5.1,2.5);
    glVertex2f(5.3,2.8);
    glVertex2f(5.9,2.4);
    glVertex2f(6,2.7);
    glVertex2f(7.1,0.9);
    glEnd();
}



void updateTrain(int value)
{
    move_train += 0.03f; // Move the train horizontally (adjust speed as needed)
    if (move_train > 27.2)
    {
        move_train = -10.0f; // Reset the position if it goes beyond a certain point
    }

    glutPostRedisplay(); // Trigger display refresh
    glutTimerFunc(30, updateTrain, 0); // Call the update function again after interval
}



                        ///sun///Moon//////////////////////

int start_flag=0;



//bool isItNight = false;
void night(int value);
GLfloat sunPosition = 0.0f;
GLfloat sunSpeed = 0.016f;
void updateMoon(int value);

void updateSun(int value)
{
    if(sunPosition <-5.65 )
    {
        sunPosition = -5.65;
        //isItNight = true;
    }

    sunPosition -= sunSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateSun, 0);
}

GLfloat moonPosition = -5.8f;
GLfloat moonSpeed = 0.001f;


void updateMoon(int value)
{
    moonPosition += moonSpeed;
    if(moonPosition > 0.5)
    {
        moonPosition = 0.5;
    }
    moonPosition += moonSpeed;

    glutPostRedisplay();

    glutTimerFunc(100, updateMoon, 0);
}


void sky(int value )///sky
{

    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(135, 206, 250);
    glVertex2f(-16, 2);
    glVertex2f(16, 2);
    glVertex2f(16, 9);
    glVertex2f(-16, 9);

    glEnd();
    glutPostRedisplay();
    glutTimerFunc(5, sky, 0);


}
void night(int value)//CL
{
    glBegin(GL_POLYGON); //Sky
    glColor3ub(22, 78, 104);
    glVertex2f(-16, 2);
    glVertex2f(16, 2);
    glVertex2f(16, 9);
    glVertex2f(-16, 9);
    glEnd();


    glColor3ub(59, 76, 59);
    glBegin(GL_POLYGON);///upper land

    glVertex2f(2.5,0.9);
    glVertex2f(3.7,2);
    glVertex2f(16,2);
    glVertex2f(11.1,-0.5);
    glVertex2f(10.8,-0.3);
    glVertex2f(6.9,0.2);
    glVertex2f(6.7,0.1);
    glEnd();

    glBegin(GL_POLYGON);/// dam side land
    glVertex2f(16,2);
    glVertex2f(10.8,-0.3);
    glVertex2f(11.1,-0.5);
    glVertex2f(11.1,-0.6);
    glVertex2f(8.4,-1.3);
    glVertex2f(8.3,-1.5);
    glVertex2f(9.1,-1.7);
    glVertex2f(10.6,-1.9);
    glVertex2f(11.9,-2.3);
    glVertex2f(12.9,-2.6);
    glVertex2f(12.9,-2.5);
    glVertex2f(13.8,-2.5);
    glVertex2f(14,-3.3);
    glVertex2f(14.9,-3.3);
    glVertex2f(15,-2.8);
    glVertex2f(16,-2.8);
    glEnd();
    glBegin(GL_TRIANGLES);/// dam side land
    glVertex2f(3.1,2);
    glVertex2f(3.7,2);
    glVertex2f(3.2,1.5);
    glEnd();
    glPointSize(2.0);///stars //////////////////
    glColor3ub(255,255,255);

    glBegin(GL_POINTS);

    glVertex2f(-13.4,6.9);
    glVertex2f(-13,7.7);
    glVertex2f(-12.3,7.6);
    glVertex2f(-11.8,8.5);
    glVertex2f(-10.9,8.2);
    glVertex2f(-9.1,8.7);
    glVertex2f(-8.2,8.6);
    glVertex2f(-5.5,8);
    glVertex2f(-4.5,8.5);
    glVertex2f(-3.2,8.1);
    glVertex2f(-2.6,8.6);
    glVertex2f(1.2,8.1);
    glVertex2f(5.1,-8.8);
    glVertex2f(2.9,7.5);
    glVertex2f(-0.4,4.6);
    glVertex2f(3,4);
    glVertex2f(10.5,7.9);
    glVertex2f(10.3,6.3);
    glVertex2f(8.6,4.1);
    glVertex2f(11,4.2);
    glVertex2f(12.8,3.9);
    glEnd();

    ///cloud 1///
    glPushMatrix();

    glTranslatef(_moveC, 0.0f, 0.0f);
    glPushMatrix();
    glColor3ub(96, 106, 107 );
    glTranslatef(-15.3,8.5, 0.1);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(96, 106, 107 );
    glTranslatef(-14.9,8.4, 0.2);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(96, 106, 107 );
    glTranslatef(-14.5, 8, 0.1);
    glutSolidSphere(0.7, 250, 250);
    glPopMatrix();




    ///cloud 2///


    glPushMatrix();

    glTranslatef(_moveC, 0.0f, 0.0f);
    glPushMatrix();
    glColor3ub(96, 106, 107 );
    glTranslatef(-7.7, 7.8, 0.1);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(96, 106, 107 );
    glTranslatef(-7.3, 8, 0.1);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(96, 106, 107 );
    glTranslatef(-7, 7.9, 0.1);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(96, 106, 107 );
    glTranslatef(-7.4, 7.8, 0.2);
    glutSolidSphere(0.8, 250, 250);
    glPopMatrix();



    glPopMatrix();

    ///cloud 3///

    glPushMatrix();

    glTranslatef(_moveC, 0.0f, 0.0f);

    glPushMatrix();
    glColor3ub(96, 106, 107 );
    glTranslatef(5.9, 7, 0.2);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(96, 106, 107 );
    glTranslatef(6.4, 7.3, 0.1);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(96, 106, 107 );
    glTranslatef(6.8, 7, 0.1);
    glutSolidSphere(0.75, 250, 250);
    glPopMatrix();

    glPushMatrix();
    glColor3ub(96, 106, 107 );
    glTranslatef(6.4, 6.7, 0.1);
    glutSolidSphere(0.75, 250, 250);

    glPopMatrix();


    glPopMatrix();



    glPopMatrix();

    glutPostRedisplay();
    glutTimerFunc(100, updateMoon, 0);
}
void sun()//S11
{
    glPushMatrix();
    glTranslatef(0.0f,sunPosition, 0.0f);

    float x1,y1,x2,y2;
    float a;
    double radius=0.7;

    x1=14.5, y1= 8;

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(239,255,0);
    for (a = 0.0f ; a < 360.0f ; a+=0.2)
    {
        x2 = x1+sin(a)*radius;
        y2 = y1+cos(a)*radius;
        glVertex2f(x2,y2);
    }

    glEnd();

    glPopMatrix();
}



void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);

    scenario();
    land();
    Road();
    car1();
    vehicle();
    House1();
    object2();
    school();
    _clock();
    object4();



    if(start_flag == 0)
    {
        sky(1);

        if(sunPosition < -5.75)
        {
            night(1);
        }


        river();
        warehouse1();
        warehouse2();
        sun();
        house2();
        boat();
        cloud();
        trainline();
        train();
        dam();
        hill();


        drawSmoke(smokeOffset1, 0.3f, -2.6f);
        drawSmoke(smokeOffset2, 0.3f, -2.6f);
        drawSmoke(smokeOffset3, 0.3f, -2.6f);

        // Second set of offsets
        drawSmoke(smokeOffset4, 15.6f, 1.6f);
        drawSmoke(smokeOffset5, 15.6f, 1.6f);
        drawSmoke(smokeOffset6, 15.6f, 1.6f);
        drawSmoke(smokeOffset7, 13.30f, -0.11f);
        drawSmoke(smokeOffset8, 13.30f, -0.11f);
        drawSmoke(smokeOffset9, 13.30f, -0.11f);


        glutSwapBuffers();
        glFlush();

        //glutSwapBuffers(); // Render now
    }



}

void update1(int value)//UpdateBoat
{

    _moveA += speed;
    if (_moveA > 4)
    {
        _moveA = -1;
    }
    //Notify GLUT that the display has changed

    //_moveA += 0.11;

    glutTimerFunc(20, update1, 0); //Notify GLUT to call update again in 25 milliseconds
    glutPostRedisplay();
}

void update4(int value)
{


    if (_moveC > +36)
    {
        _moveC = -38;
    }


    _moveC += 0.013;

    glutTimerFunc(20, update4, 0); //Notify GLUT to call update again in 25 milliseconds
    glutPostRedisplay();
}


void myKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 'a'://press a to slow truck
        truckSpeed -= 0.03f;
        break;

    case 'b'://press b to fast truck
        truckSpeed += 0.05f;
        break;

    case 'c'://press c to slow car
        carSpeed -= 0.03f;
        break;

    case 'd'://press d to fast car
        carSpeed += 0.05f;
        break;

    case 'e'://press e to slow car
        move_train-= 0.03f;
        break;

    case 'f'://press f to fast car
        move_train += 0.05f;
        break;

    default:
        break;

        glutPostRedisplay();

    }

}



int main(int argc, char** argv)
{
    glutInitWindowSize(1620, 1080);
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("Sky mountain city"); // Create a window with the given title
    gluOrtho2D(-16, 16, -9, 9);  // Set the window's initial width & height
    glutDisplayFunc(display);

    glutKeyboardFunc(myKeyboard);
    glutTimerFunc(100, updateCar, 0);
    glutTimerFunc(100, updateTruck, 0);
    glutReshapeFunc(reshape);

    // glutKeyboardFunc(handleKeypress);
    glutTimerFunc(20, update1, 0); //Add a timer
    // glutTimerFunc(20, update2, 0); //Add a timer
    glutTimerFunc(1000, updateSun, 0);
    glutTimerFunc(0, updateTrain, 0);
    glutTimerFunc(20, update4, 0);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
