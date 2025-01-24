#include<iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include<math.h>
#include "glutil.h"

using namespace std;

GLfloat _angle1 = 0.0f;
GLfloat bAngle = 0;
GLfloat _move = 0.0f;
GLfloat speed = 0.1f;
GLfloat secMove = 0.1f;
GLfloat minMove = 0.1f;
GLfloat hourMove = 0.1f;
GLfloat boat1Move = 0.4f;
GLfloat boat1Speed = 0.0003f;

GLfloat boat2Move = 0.0f;
GLfloat boat2Speed = 0.01f;

GLfloat boat3Move = 0.0f;
GLfloat boat3Speed = 0.05f;

GLfloat boat4Move = 0.0f;
GLfloat boat4Speed = 0.07f;

GLfloat boat5Move = 0.0f;
GLfloat boat5Speed = 0.03f;

GLfloat car1Move = 0.0f;
GLfloat car1Speed = 0.03f;

GLfloat car2Move = 0.0f;
GLfloat car2Speed = 0.09f;

GLfloat car3Move = 0.0f;
GLfloat car3Speed = 0.02f;

GLfloat car4Move = 0.0f;
GLfloat car4Speed = 0.07f;

GLfloat car5Move = 0.0f;
GLfloat car5Speed = 0.06f;

GLfloat car6Move = 0.0f;
GLfloat car6Speed = 0.06f;

GLfloat car7Move = 0.0f;
GLfloat car7Speed = 0.08f;

GLfloat cloud1Move = 0.0f;
GLfloat cloud1Speed = 0.005f;
GLfloat cloud2Move = 0.0f;
GLfloat cloud2Speed = 0.01f;
GLfloat cloud3Move = 0.0f;
GLfloat cloud3Speed = 0.016f;
GLfloat cloud4Move = 0.0f;
GLfloat cloud4Speed = 0.015f;

GLfloat sunMove = 0.0f;
GLfloat moonMove = 0.0f;
bool isNight = false;
int cnt = 0;


void circle(double x1, double y1, double a, int r, int g, int b)
{
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++)
    {
        glColor3ub(r,g,b);
        float pi=3.1416;
        float A=(i*2*pi)/200;
        float r=a;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+x1,y+y1);
    }
    glEnd();
}

void unfilledCircle(float cx, float cy, float radius, int numSegments, float w, int r, int g, int b)
{
    glLineWidth(w);
    glBegin(GL_LINE_LOOP);
    glColor3ub(r,g,b);
    for (int i = 0; i < numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void line(double x1, double y1, double x2, double y2, double w, int r, int g, int b)
{
    glLineWidth(w);
    glBegin(GL_LINES);
    glColor3ub(r,g,b);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void point(double x, double y, double s, int r, int g, int b)
{
    glPointSize(s);
    glBegin(GL_POINTS);
    glColor3ub(r, g, b);
    glVertex2f(x, y);
    glEnd();
}

void triangle(double x1, double y1, double x2, double y2, double x3, double y3, int r, int g, int b)
{
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glEnd();
}

void rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, int r, int g, int b)
{
    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

void spin(float a, void (*callback)(void))
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(a, 0.0f, 0.0f,1.0f);
    callback();
    glPopMatrix();
}

void spin(double x, double y, void (*callback)(double, double))
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glRotatef(_angle1, 0.0f, 0.0f,1.0f);
    glTranslatef(-x, -y, 0.0);
    callback(x, y);
    glPopMatrix();
}

void spin(float m, double x, double y, void (*callback)(void))
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, 0.0);
    glRotatef(m, 0.0f, 0.0f,1.0f);
    glTranslatef(-x, -y, 0.0);
    callback();
    glPopMatrix();
}

void moove(float m, void (*callback)(void))
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(m, 0.0f, 0.0f);
    callback();
    glPopMatrix();
}

void moove(float x, float y, void (*callback)(float, float))
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
    callback(x, y);
    glPopMatrix();
}

void shift(float x, float y, void (*callback)(void))
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, 0);
    callback();
    glPopMatrix();
}

void scale(float x, float y, float s, void (*callback)(void))
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(s, s, 1.0f);
    shift(x, y, callback);
    glPopMatrix();
}

void scale(float s, void (*callback)(void))
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(s, s, 1.0f);
    callback();
    glPopMatrix();
}


void sun()
{
    circle(-15.49106, 8.34772, 8.12, 254, 248, 119);
}



//CD001
void cloud1()
{
    circle(3.8, 12.2, 1.55, 255, 246, 241);
    circle(6, 12.5, 1.95, 255, 246, 241);
    circle(9, 12.3, 1.67, 255, 246, 241);
    circle(7.9, 14.3, 1.97, 255, 246, 241);
    circle(10.3, 13.5, 1.34, 255, 246, 241);
    circle(11.5, 12.3, 1.64, 255, 246, 241);
}

//CD002
void cloud2()
{
    circle(20.2, 15.2, 0.9, 255, 246, 241);
    circle(21.6, 15.2, 0.9, 255, 246, 241);
    circle(22.7, 15, 0.63, 255, 246, 241);
    circle(22, 15.7, 0.71, 255, 246, 241);
    circle(21.1, 16.1, 0.77, 255, 246, 241);
}

//CD003
void cloud3()
{
    circle(-4.5, 8.6, 1.09, 255, 246, 241);
    circle(-2.8, 9.2, 1.58, 255, 246, 241);
    circle(-0.9, 8.7, 1.05, 255, 246, 241);
}

//CD004
void cloud4()
{
    glPushMatrix();
    glTranslatef(-45, 0, 0);
    circle(20.2, 15.2, 0.9, 255, 246, 241);
    circle(21.6, 15.2, 0.9, 255, 246, 241);
    circle(22.7, 15, 0.63, 255, 246, 241);
    circle(22, 15.7, 0.71, 255, 246, 241);
    circle(21.1, 16.1, 0.77, 255, 246, 241);
    glPopMatrix();
}

//S001
void sky(int sr, int sg, int sb)
{
    rectangle(-27,-12, -27,18, 27,18, 27,-12, sr, sb, sg);
    triangle(21.1,-4.4, 20.4,-2.5, 21.5,-1.3, 255, 247, 240);
    circle(17.6977, -4.51887, 3.36, 255, 247, 240);
    circle(27.41256, -0.24317, 6.05, 255, 247, 240);
    circle(-29.82638, -2.11983, 8.13, 255, 247, 240);

     spin(sunMove, -20, -53, sun);
    moove(cloud1Move, cloud1);
    moove(cloud1Move, cloud2);
    moove(cloud1Move, cloud3);
    moove(cloud1Move, cloud4);
}


//R001
void river()
{
    rectangle(-27,-12, 27,-12, 27,-18, -27,-18, 0, 185, 224);
}


//B001
void boat1()
{
    rectangle(-1.8,-9.7, -1.60013, -8.1705, 1.57141, -8.13807, 1.8,-9.8, 224, 228, 254);
    rectangle(-1.2,-9.6, -1.17022, -8.41385, 1.12242, -8.42784, 1.1,-9.6, 0, 113, 189);
    line(0.05,-4, 0.05, -7.4, 3, 51,51, 51);
    line(0.05,-6.7, 0.05, -7.4, 3, 226, 230, 255);
    line(-1.34342, -7.82903, -1.3, -8.1, 4, 41, 27, 34);
    line(1.34342, -7.82903, 1.3, -8.1, 4, 41, 27, 34);
    rectangle(-0.2,-7.9, -0.2,-7.3, 0.2, -7.3, 0.2, -7.9, 128, 128, 128);

    //rectangle(-1.86178, -9.4142, -1.6, -9.4, -1.6, -9.5, -1.9,-9.5, 65, 40, 51);


    triangle(-1.3,-8.2, 0,-7.9, 1.3, -8.2, 244, 228, 254);
    line(-1.8, -8.17051, -0.00219, -7.86228, 2, 0,0,0);
    line(1.8, -8.17051, -0.00219, -7.86228, 2, 0,0,0);


    glBegin(GL_POLYGON);
    glColor3ub(41, 28, 35);
    glVertex2f (-2.3, -12);
    glVertex2f (-2.5, -11.7);
    glVertex2f (-2.6, -10.9);
    glVertex2f(-2.6, -10.1);
    glVertex2f (-2, -9.8);
    glVertex2f (-1.8, -9.7);
    glVertex2f(-1.6, -9.7);
    glVertex2f(-1.2, -9.6);
    glVertex2f(-0.1, -9.3);

    glVertex2f(0.1, -9.3);
    glVertex2f(1.1, -9.6);
    glVertex2f(1.6, -9.7);
    glVertex2f(1.8, -9.7);
    glVertex2f(2, -9.8);
    glVertex2f(2.6, -10.1);
    glVertex2f(2.6, -10.9);
    glVertex2f(2.5, -11.7);
    glVertex2f(2.3, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(228, 228, 228);
    glVertex2f (-2.3, -12);
    glVertex2f (-2.5, -11.7);
    glVertex2f (-2.6, -10.9);
    glVertex2f(-2.2, -10.7);
    glVertex2f (-1.7, -10.4);
    glVertex2f (-0.4, -10);

    glVertex2f(0, -9.9);

    glVertex2f(0.4, -10);
    glVertex2f(1.7, -10.4);
    glVertex2f(2.2, -10.7);
    glVertex2f(2.6, -10.9);
    glVertex2f(2.5, -11.7);
    glVertex2f(2.3, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(237, 27, 36);
    glVertex2f (-2.3, -12);
    glVertex2f (-2.5, -11.7);
    glVertex2f (-2.3, -11.4);
    glVertex2f (-2.1, -11.2);
    glVertex2f(-1.5, -11);

    glVertex2f (0, -10.6);

    glVertex2f(1.5, -11);
    glVertex2f(2.1, -11.2);
    glVertex2f(2.3, -11.4);
    glVertex2f(2.5, -11.7);
    glVertex2f(2.3, -12);
    glEnd();

    line(0,-9.3, 0,-12, 5, 153, 153, 153);

}

//B001I
void broken_boat1()
{
    glBegin(GL_POLYGON);
    glColor3ub(41, 28, 35);
    glVertex2f (-2.3, -12);
    glVertex2f (-2.5, -11.7);
    glVertex2f (-2.6, -10.9);
    glVertex2f(-2.6, -10.1);
    glVertex2f (-2, -9.8);
    glVertex2f (-1.8, -9.7);
    glVertex2f(-1.6, -9.7);
    glVertex2f(-1.2, -9.6);
    glVertex2f(-0.1, -9.3);

    glVertex2f(0.1, -9.3);
    glVertex2f(1.1, -9.6);
    glVertex2f(1.6, -9.7);
    glVertex2f(1.8, -9.7);
    glVertex2f(2, -9.8);
    glVertex2f(2.6, -10.1);
    glVertex2f(2.6, -10.9);
    glVertex2f(2.5, -11.7);
    glVertex2f(2.3, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(228, 228, 228);
    glVertex2f (-2.3, -12);
    glVertex2f (-2.5, -11.7);
    glVertex2f (-2.6, -10.9);
    glVertex2f(-2.2, -10.7);
    glVertex2f (-1.7, -10.4);
    glVertex2f (-0.4, -10);

    glVertex2f(0, -9.9);

    glVertex2f(0.4, -10);
    glVertex2f(1.7, -10.4);
    glVertex2f(2.2, -10.7);
    glVertex2f(2.6, -10.9);
    glVertex2f(2.5, -11.7);
    glVertex2f(2.3, -12);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(237, 27, 36);
    glVertex2f (-2.3, -12);
    glVertex2f (-2.5, -11.7);
    glVertex2f (-2.3, -11.4);
    glVertex2f (-2.1, -11.2);
    glVertex2f(-1.5, -11);

    glVertex2f (0, -10.6);

    glVertex2f(1.5, -11);
    glVertex2f(2.1, -11.2);
    glVertex2f(2.3, -11.4);
    glVertex2f(2.5, -11.7);
    glVertex2f(2.3, -12);
    glEnd();

    line(0,-9.3, 0,-12, 5, 153, 153, 153);
}




//B002
void boat2()
{
    glBegin(GL_POLYGON);
    glColor3ub(116, 49, 33);
    glVertex2f(-13.3, -13.1);
    glVertex2f(-13.3, -12.5);
    glVertex2f(-8.1, -12.1);
    glVertex2f(-8.5, -12.5);
    glVertex2f(-9.4, -13.1);
    glEnd();

    triangle(-13.3, -12.5, -8.1, -12.1, -8.5, -12.5, 249, 164, 48);
    rectangle(-11.7, -12.4, -11.7, -11.1, -10.6,-11.1, -10.1,-12.3, 254, 255, 255);
    rectangle(-11.3, -11.9, -11.3, -11.1, -10.8, -11.1, -10.4, -11.9, 119, 188, 253);
    line(-12,-11.15, -10.3, -11.15, 4, 122, 46, 39);
}

//B003
void boat3()
{
    rectangle(-23.1, -15.2, -22.9, -14.7, -19.3, -14.4, -18.9, -15.1, 254, 252, 253);
    line(-23.3, -14.7, -19.1, -14.4, 4, 121, 49, 37);

    line(-18.7, -15.2, -18.7, -9.7, 4, 108, 52, 45);
    triangle(-23.8, -13.4, -18.9,-9, -18.9, -13.9, 255, 255, 255);
    triangle(-18.5, -14.5, -18.5,-9.7, -15.9, -14.5, 255, 255, 255);

    glBegin(GL_POLYGON);
    glColor3ub(121, 49, 37);
    glVertex2f(-23.3, -15.9);
    glVertex2f(-23.5, -15.5);
    glVertex2f(-23.8, -15.2);
    glVertex2f(-16, -15);
    glVertex2f(-16.7, -15.3);
    glVertex2f(-18.2, -15.9);
    glEnd();

    rectangle(-23.3, -15.9, -23.6, -15.5, -16.7, -15.3, -18.2, -15.9, 253, 164, 43);
    circle(-22.4, -14.92, 0.16, 142, 153, 160);
    circle(-22.4, -14.92, 0.12, 180, 218, 246);

    circle(-21.5, -14.9, 0.16, 142, 153, 160);
    circle(-21.5, -14.9, 0.12, 180, 218, 246);

    circle(-20.6, -14.85, 0.16, 142, 153, 160);
    circle(-20.6, -14.85, 0.12, 180, 218, 246);

    circle(-19.7, -14.8, 0.16, 142, 153, 160);
    circle(-19.7, -14.8, 0.12, 180, 218, 246);

}

//B004
void boat4()
{
    line(11.4, -5.3, 11.4, -13.5, 3, 109, 142, 133);
    line(8.5, -12.7, 11.4, -12.7, 3, 109, 142, 133);
    line(11.4, -12.8, 14, -13.6, 3, 109, 142, 133);

    triangle(8.6, -12.5, 11.3, -5.4, 11.3, -12.5, 241, 243, 242);
    triangle(12, -11.55, 12, -7.4, 14, -12.15, 241, 243, 242);
    triangle(11.5, -12.8, 11.5, -7.7, 13.8, -13.5, 241, 243, 242);

    line(11.5, -5.9, 14.6, -13.5, 1, 109, 142, 133);

    line(9.5, -13.5, 13.2, -13.5, 5, 223, 190, 117);





    glBegin(GL_POLYGON);
    glColor3ub(196, 41, 35);
    glVertex2f(7.2, -14.6);
    glVertex2f(7.2, -13.6);
    glVertex2f(14.6, -13.5);
    glVertex2f(14.1, -14.4);
    glVertex2f(13.5, -14.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(242, 225, 171);
    glVertex2f(7.2, -14.4);
    glVertex2f(7.2, -13.6);
    glVertex2f(14.6, -13.5);
    glVertex2f(14.1, -14.4);
    glEnd();
}

//B005
void boat5()
{
    glBegin(GL_POLYGON);
    glColor3ub(196, 41, 35);
    glVertex2f(18.1, -15.4);
    glVertex2f(17.3, -14.8);
    glVertex2f(17.1, -14.8);
    glVertex2f(16.7, -14.3);
    glVertex2f(21.5, -14.3);
    glVertex2f(21.9, -14.8);
    glVertex2f(22.5, -14.8);
    glVertex2f(22.9, -15.4);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(188, 247, 255);
    glVertex2f(18.1, -15.4);
    glVertex2f(17.1, -14.8);
    glVertex2f(20.4, -14.9);
    glVertex2f(21.5, -15.1);
    glVertex2f(22.1, -15.2);
    glVertex2f(22.7, -15.4);
    glEnd();

    rectangle(19.2, -14.3, 20.2, -13.7, 21.6, -13.7, 21.4, -14.3, 197, 212, 217);
    rectangle(20.6, -14.3, 20.6, -13.8, 21.4, -13.8, 20.8, -14.3, 13, 218, 255);
    rectangle(19.4, -14.3, 20.2, -13.8, 20.5, -13.8, 20.5, -14.3, 13, 218, 255);
}

void lineOfRound()
{
    line(7.1,-2.7, 23.9,2.9, 5, 0, 154, 179);
}

void ball()
{
    circle(5.68139, 3.98279, 0.447, 0, 154, 179);
    line(5.68139,3.98279, 6.3,3.7, 6, 0, 154, 179);
}

void ballNight()
{
    circle(5.68139, 3.98279, 0.447, 0, 154, 179);
    line(5.68139,3.98279, 6.3,3.7, 6, 0, 154, 179);
    circle(5.68139, 3.98279, 0.35, 247, 247, 0);

}



//M001
void merigoRound()
{
    unfilledCircle(15.48417, 0.11819, 9.84, 1000, 6, 0, 154, 179);
    unfilledCircle(15.48417, 0.11819, 8.866, 1000, 6, 0, 154, 179);
    unfilledCircle(15.48417, 0.11819, 7.88, 1000, 2, 0, 154, 179);
    unfilledCircle(15.48417, 0.11819, 7.46, 1000, 2, 0, 154, 179);
    circle(15.48417, 0.11819, 1.3, 0, 154, 179);

        for(int i = 0; i<180; i=i+9)
    {
        spin(i, 15.48417, 0.11819, lineOfRound);
    }

    for(int j = 0; j<360; j=j+24)
    {
        spin(j, 15.48417, 0.11819, ball);
    }
}



//E001
void londonEye()
{
    line(9.2,-12, 15.48417,0.11819, 15, 0, 154, 179);
    line(21.7,-12, 15.5,0.4, 15, 0, 154, 179);
    merigoRound();
}



//BG001
void rightBackgroudBuilding()
{
    rectangle(21.1,-5.2, 21.1,-0.8, 24.2,-0.8, 24.2,-5.2, 0, 192, 214);
    rectangle(21.1,-4.4, 21.1,-0.8, 24.5,-0.8, 24.5,-4.4, 0, 192, 214);
    rectangle(21.4,-0.8, 21.8,0.7, 23.8,0.7, 24.2,-0.8, 0, 192, 214);
    rectangle(21.6,0.7, 21.6,1, 24,1, 24,0.7, 0, 192, 214);
    line(21.68512, 0.71022, 23.9, 0.71022, 6, 0, 192, 214);
    rectangle(21.9,1, 21.9,1.5, 23.7,1.5, 23.7,1, 0, 192, 214);
    triangle(21.9,1, 22.78709, 3.54282, 23.7,1, 0, 192, 214);
    line(22.78709, 3.2, 22.78709, 4.3, 2, 0, 192, 214);
    line(22.46854, 3.3, 23.08177, 3.3, 6, 0, 192, 214);

    rectangle(14.5,-12, 14.5,-5.8, 24.2,-5.8, 24.2,-12, 0, 154, 179);
    rectangle(17.4,-5.8, 17.4,-5.1, 19.4,-5.1, 19.4,-5.8, 0, 154, 179);
    rectangle(19.6,-5.8, 19.6,-4.3, 21.6,-4.3, 21.6,-5.8, 0, 154, 179);
    rectangle(20.3,-5.8, 20.3,-3.9, 21.6,-3.9, 21.6,-5.8, 0, 154, 179);
    rectangle(21.6,-5.8, 21.6,-4.6, 22.2,-4.6, 22.2,-5.8, 0, 154, 179);
    rectangle(22.2,-5.8, 22.2,-5.2, 24.2,-5.2, 24.2,-5.8, 0, 154, 179);
    //rectangle(24.2,-5.2, 27,-5.2, 27,-12, 24,-12, 0, 154, 179);

    rectangle(16.6,-5.8, 16.6,-4.1, 18.9,-4.1, 18.9,-5.8, 86, 229, 247);
    rectangle(16.8,-4.1, 17.1,-2.4, 18.3,-2.4, 18.7,-4.1, 86, 229, 247);
    triangle(17.1,-2.4, 17.7,-0.8, 18.3,-2.4, 86, 229, 247);

    rectangle(10.1997, -8.0806, 10.19855, -3.88161, 10.70984, -3.89297, 10.74027, -8.0806, 0, 191, 214);
    triangle(10.2,-4.4, 9.9,-4.3, 10.2,-4.1, 0, 191, 214);
    triangle(10.7,-4.4, 11,-4.3, 10.7,-4.1, 0, 191, 214);
    triangle(10.2,-4.1, 10,-4, 10.2,-3.9, 0, 191, 214);
    triangle(10.7,-4.1, 10.9,-4, 10.7,-3.9, 0, 191, 214);
    triangle(10.2,-3.9, 10.45382,-3.79569, 10.7,-3.9, 0, 191, 214);
    line(10.45382, -3.79569, 10.43586, -3.44453, 3, 0, 191, 214);

    glBegin(GL_POLYGON);
    glColor3ub(0, 191, 214);
    glVertex2f(10.74027, -8.0806);
    glVertex2f(10.63902, -6.44957);
    glVertex2f(10.78164, -6.26974);
    glVertex2f(10.77544, -6.0031);
    glVertex2f(11, -5.8);
    glVertex2f(11.04828, -5.51943);
    glVertex2f(11.25291, -5.51943);
    glVertex2f(11.58776, -8.08041);
    glEnd();
}



//BG003
void leftBackgroudBuilding()
{
    circle(-16.47983, 7.93994, 1.04, 0, 193, 214);

    glBegin(GL_POLYGON);
    glColor3ub(0, 193, 214);
    glVertex2f(-20, -18);
    glVertex2f(-19.9, 1.5);
    glVertex2f(-19.73595, 2.9853);
    glVertex2f(-19.1, 4.7);
    glVertex2f(-18.6, 5.9);
    glVertex2f(-18.2, 6.9);
    glVertex2f(-17.4, 8.5);
    glVertex2f(-15.5,8.3);
    glVertex2f(-15.13436, 7.57328);
    glVertex2f(-14.67748, 6.67221);
    glVertex2f(-14.24598, 5.69499);
    glVertex2f(-13.80262, 4.65039);
    glVertex2f(-13.2, -12);
    glEnd();

    rectangle(-27, -1, -27,-0.5, -24.2, -0.5, -24.2, -1, 0, 155, 180);
    rectangle(-27.3, -0.5, -26.9,0.9, -24.9, 0.9, -24.4, -0.6, 0, 155, 180);
    rectangle(-27, -0.9, -27,1.2, -24.7, 1.2, -24.7, 1, 0, 155, 180);
    rectangle(-26.8, 1.2, -26.8,1.8, -25, 1.8, -25, 1.2, 0, 155, 180);
    triangle(-26.8,1.8, -25.9,3.8, -25, 1.8, 0, 155, 180);
    line(-25.9, 3.7, -25.9, 4.7, 2, 0, 155, 180);
    line(-26.2, 3.7, -25.6, 3.7, 6, 0, 155, 180);

    rectangle(-27,-18, -27, -6.8, -14.6, -6.8, -14.4137, -17.25873, 0, 155, 180);
    rectangle(-16.3,-6.8, -16.3, -4.2, -15.7, -4.2, -15.7, -6.8, 0, 155, 180);

    glBegin(GL_POLYGON);
    glColor3ub(0, 155, 180);
    glVertex2f(-16.3, -4.2);
    glVertex2f(-16.5, -4);
    glVertex2f(-16.3, -3.8);
    glVertex2f(-15.7, -3.8);
    glVertex2f(-15.5, -4);
    glVertex2f(-15.7, -4.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 155, 180);
    glVertex2f(-16.3, -3.8);
    glVertex2f(-16.5, -3.6);
    glVertex2f(-16.1, -3.4);
    glVertex2f(-15.9, -3.4);
    glVertex2f(-15.5, -3.6);
    glVertex2f(-15.7, -3.8);
    glEnd();

    rectangle(-16.1, -3.4, -16.05, -3, -15.95, -3, -15.9, -3.4, 0, 155, 180);
    rectangle(-9, -12, -9, 0.3, -11.1, 0.3, -13.2, -12, 0, 193, 214);
    line(-10.7, 0.3, -9.6, 0.3, 10, 0, 193, 214);
}



void marking()
{
    line(-22.4,7.6, -22.2,7.6, 2, 0,0,0);
}

void secHand()
{
    line(-21.4,7.6, -21.4,8.5, 1.5, 0,0,0);
}
void minHand()
{
    line(-21.4,7.6, -21.4,8.3, 1.5, 0,0,0);
}
void hourHand()
{
    line(-21.4,7.6, -21.4,8.2, 1.5, 0,0,0);
}

//CLK001
void clock1()
{
    rectangle(-23.1,5.9, -23.1,9.5, -19.7,9.5, -19.7,5.9, 206,169,0);
    rectangle(-23.2,5.9, -23.2,9.5, -19.6,9.5, -19.6,5.9, 247, 206, 17);

    circle(-21.4,7.6, 1.26, 255,255,255);
    for(int j = 0; j<360; j=j+30)
    {
        spin(j, -21.4,7.6, marking);
    }

    spin(secMove, -21.4,7.6, secHand);
    spin(minMove, -21.4,7.6, minHand);
    spin(hourMove, -21.4,7.6, hourHand);
}

void top()
{
    rectangle(-23.1, 9.4, -23.1, 10.5, -19.7, 10.5, -19.7, 9.4, 224, 194, 129);
    rectangle(-23.2, 10.5, -23.2, 10.7, -19.6, 10.7, -19.6, 10.5, 110, 81, 31);

      for(float i=0; i<3; i+=0.51)
    {
        line(-22.7+i,10.3, -22.7+i,9.5, 5, 72, 49, 40);

    }


    rectangle(-23.2, 10.72, -22.3, 13.1, -20.5, 13.1, -19.6, 10.72, 65, 46, 43);
    rectangle(-22.3, 13.1, -22.3, 14.4, -20.5, 14.4, -20.5, 13.1, 221, 184, 117);
    rectangle(-22.3, 14.4, -22.3, 14.7, -20.5, 14.7, -20.5, 14.4, 113, 81, 40);
    triangle(-22.3, 14.7, -21.4, 17.2, -20.5, 14.7, 67, 47, 44);

    circle(-21.4, 17.2, 0.15, 67, 47, 44);
    circle(-21.4, 17.3, 0.12, 246, 209, 29);
    line(-21.4, 17.3, -21.4, 18, 2, 246, 209, 29);

    line(-21.9, 13.2, -21.9, 14.2, 5, 67, 48, 37);
    line(-20.9, 13.2, -20.9, 14.2, 5, 67, 48, 37);
    line(-21.4, 13.2, -21.4, 14.2, 5, 67, 48, 37);
}

//BB001
void bigBen()
{
    top();
    rectangle(-23.4,-8.1, -23.4,5, -19.4,5, -19.4,-8.1, 202, 165, 94);

    for(float i=0 ; i<10; i=i+2.4)
    {
        rectangle(-23.4,-8.1+i, -23.4,-7.5+i, -19.4,-7.5+i, -19.4,-8.1+i, 192, 158, 92);
        line(-23.4,-7.5+i, -19.4,-7.5+i, 3, 145, 112, 54);
        line(-23.4,-8.1+i, -19.4,-8.1+i, 3, 145, 112, 54);
    }

    for(float i=-2.4 ; i<8; i=i+2.4)
    {
        line(-22.9,-5.25+i, -22.9,-5.55+i, 3, 145, 112, 54);
        line(-22.4,-5.25+i, -22.4,-5.55+i, 3, 145, 112, 54);
        line(-21.9,-5.25+i, -21.9,-5.55+i, 3, 145, 112, 54);

        line(-20.9,-5.25+i, -20.9,-5.55+i, 3, 145, 112, 54);
        line(-20.4,-5.25+i, -20.4,-5.55+i, 3, 145, 112, 54);
        line(-19.9,-5.25+i, -19.9,-5.55+i, 3, 145, 112, 54);
    }

    for(float i=0 ; i<8; i=i+2.4)
    {
        line(-22.4,-5.95+i, -22.4,-6.55+i, 3, 145, 112, 54);
        line(-22.4,-6.7+i, -22.4,-7.3+i, 3, 145, 112, 54);
        line(-21.9,-5.95+i, -21.9,-6.55+i, 3, 145, 112, 54);
        line(-21.9,-6.7+i, -21.9,-7.3+i, 3, 145, 112, 54);

        line(-20.9,-5.95+i, -20.9,-6.55+i, 3, 145, 112, 54);
        line(-20.9,-6.7+i, -20.9,-7.3+i, 3, 145, 112, 54);
        line(-20.4,-5.95+i, -20.4,-6.55+i, 3, 145, 112, 54);
        line(-20.4,-6.7+i, -20.4,-7.3+i, 3, 145, 112, 54);
    }

    line(-22.4,4.4, -22.4,3.55, 3, 145, 112, 54);
    line(-22.4,3.35, -22.4,2.5, 3, 145, 112, 54);
    line(-21.9,4.4, -21.9,3.55, 3, 145, 112, 54);
    line(-21.9,3.35, -21.9,2.5, 3, 145, 112, 54);

    line(-20.9,4.4, -20.9,3.55, 3, 145, 112, 54);
    line(-20.9,3.35, -20.9,2.5, 3, 145, 112, 54);
    line(-20.4,4.4, -20.4,3.55, 3, 145, 112, 54);
    line(-20.4,3.35, -20.4,2.5, 3, 145, 112, 54);


    line(-23.35,-8.1, -23.35,5, 3, 145, 112, 54);
    line(-19.45,-8.1, -19.45,5, 3, 145, 112, 54);

    rectangle(-23.5,5, -23.5,9.5, -19.3,9.5, -19.3,5, 225, 194, 127);
    rectangle(-23.5,5, -23.5,5.4, -19.3,5.4, -19.3,5, 203, 159, 93);
    rectangle(-23.5,5, -23.5,4.6, -19.3,4.6, -19.3,5, 78, 57, 61);

    clock1();

    rectangle(-27,-0.8, -23.4,-0.8, -23.4,-8.15, -27, -8.15, 50, 33, 29);
    rectangle(-25,-2, -23.4,-2, -23.4,-8.15, -25, -8.15, 219, 186, 113);
    rectangle(-25-2.3,-2, -23.4-2.3,-2, -23.4-2.3,-8.15, -25-2.3, -8.15, 219, 186, 113);

    rectangle(-25.7, -8.15, -25.7, -1.5, -25, -1.5, -25, -8.15, 151, 115, 57);
    rectangle(-25.9, -1.5, -25.9, -1.15, -24.8, -1.15, -24.8, -1.5, 151, 115, 57);

    triangle(-25.7, -1.2, -25.35,-0.1, -25,-1.2, 151, 115, 57);
    line(-25.35, -0.2, -25.35, 0.8, 1, 151, 115, 57);
    circle(-25.35, -0.1, 0.15, 151, 115, 57);
    circle(-24.2, -2.2, 0.8, 219, 186, 113);
    circle(-24.2-2.3, -2.2, 0.8, 219, 186, 113);

    rectangle(-24.6, -1.2, -23.8,-1.2, -23.8,-1.6, -24.6,-1.6, 219, 186, 113);
    triangle(-24.4, -1.2,-24.21655, -0.99789, -24,-1.2,  219, 186, 113);

    rectangle(-24.6-2.3, -1.2, -23.8-2.3,-1.2, -23.8-2.3,-1.6, -24.6-2.3,-1.6, 219, 186, 113);
    triangle(-24.4-2.3, -1.2,-24.21655-2.3, -0.99789, -24-2.3,-1.2,  219, 186, 113);


    for(float yinc = 0; yinc < 5; yinc += 1.1)
    {
        rectangle(-24.8, -2.8 - yinc, -24.6, -2.8-yinc, -24.6, -3.3-yinc, -24.8, -3.3-yinc, 75, 50, 34);
    }

    for(float yinc = 0; yinc < 5; yinc += 1.1)
    {
        rectangle(-24.3, -2.8 - yinc, -24.1, -2.8-yinc, -24.1, -3.3-yinc, -24.3, -3.3-yinc, 75, 50, 34);
    }

    for(float yinc = 0; yinc < 5; yinc += 1.1)
    {
        rectangle(-23.8, -2.8 - yinc, -23.6, -2.8-yinc, -23.6, -3.3-yinc, -23.8, -3.3-yinc, 75, 50, 34);
    }

    for(float yinc = 0; yinc < 5; yinc += 1.1)
    {
        rectangle(-27.1, -2.8 - yinc, -26.9, -2.8-yinc, -26.9, -3.3-yinc, -27.1, -3.3-yinc, 75, 50, 34);
    }

    for(float yinc = 0; yinc < 5; yinc += 1.1)
    {
        rectangle(-26.6, -2.8 - yinc, -26.4, -2.8-yinc, -26.4, -3.3-yinc, -26.6, -3.3-yinc, 75, 50, 34);
    }

    for(float yinc = 0; yinc < 5; yinc += 1.1)
    {
        rectangle(-26.1, -2.8 - yinc, -25.9, -2.8-yinc, -25.9, -3.3-yinc, -26.1, -3.3-yinc, 75, 50, 34);
    }

    line(-23.5, 5.9, -23.5, 10, 3, 67, 48, 37);
    circle(-23.5, 9.6, 0.2, 70, 51, 45);

    line(-19.3, 5.9, -19.3, 10, 3, 67, 48, 37);
    circle(-19.3, 9.6, 0.2, 70, 51, 45);

    line(-23.5, 5.9, -23.5, 10, 3, 67, 48, 37);
    circle(-23.5, 9.6, 0.2, 70, 51, 45);

    line(-23.12, 10.8, -23.12, 11.9, 3, 67, 48, 37);
    circle(-23.1, 11.5, 0.2, 70, 51, 45);

    line(-19.7, 10.8, -19.7, 11.9, 3, 67, 48, 37);
    circle(-19.7, 11.5, 0.2, 70, 51, 45);
}



//R001
void road()
{
    rectangle(-27,-8.1, -16.7,-8.1, -16.7,-9, -27,-9,0, 95, 144);
    rectangle(27,-8.1, 16.6,-8.1, 16.6,-9, 27,-9,0, 95, 144);
}

void mainPillar()
{
    rectangle(-16.7,-8.1, -9.8,-8.1, -9.8,-12, -16.7,-12, 204, 140, 71);
    rectangle(-13.4,-8.6, -13,-8.6, -13,-9, -13.4,-9, 158, 97, 36);
    circle(-13.2, -12, 2.6, 158, 97, 39);

    rectangle(-15,-8.1, -15,4.5, -11.5,4.5, -11.5,-8.1, 189, 129, 65);
    rectangle(-15.4,-7.2, -15.4,3.2, -14.6,3.2, -14.6,-7.2, 158, 97, 39);
    rectangle(-11.9,-7.2, -11.9,3.2, -11.1,3.2, -11.1,-7.2, 158, 97, 39);

    circle(-13.2399, -7.42833, 0.33, 158, 97, 37);
    rectangle(-13.6,-8.1, -13.6,-7.4, -12.9,-7.4, -12.9,-8.1, 158, 97, 37);

    rectangle(-15.8, 0.83, -15.8, 1.59, -10.65, 1.59, -10.65, 0.83, 255, 207, 131);
    rectangle(-15.8, -2.05, -15.8, -1.3, -10.65, -1.3, -10.65, -2.05014, 255, 207, 131);
    rectangle(-15.8,-5.20352, -15.8, -4.45352, -10.65,-4.45352255, -10.65,-5.20366, 255, 207, 131);

    rectangle(-15.82,3.2, -15.82,3.6, -14.15,3.6, -14.15,3.2, 158, 97, 39);
    rectangle(-12.34, 3.2, -12.34,3.6, -10.67,3.6, -10.67,3.2, 158, 97, 39);

    triangle(-15.6,3.6, -15,6, -14.4,3.6, 239, 188, 119);
    triangle(-14,4.5, -13.23,7.6, -12.5,4.5, 0, 81, 53);
    triangle(-12.1,3.6, -11.5,6, -10.9,3.6, 239, 188, 119);

    rectangle(-16.7, -12, -9.8, -12, -9.8, -18, -16.7, -18, 0, 185, 224);

    for(float j = 0; j<=8; j+=3)
    {
        for(float i = 0.0f; i<=2; i+=0.8)
        {
            rectangle(-14.2+i, -5.5+j, -13.8+i,-5.5+j, -13.8+i, -6.9+j, -14.2+i, -6.9+j, 158, 97, 39);
        }
    }

    rectangle(-14, 1.7, -14, 4.4, -12.5, 4.4, -12.5, 1.7, 239, 188, 119);
    rectangle(-13.8, 3.4, -13.8, 4.2, -12.7, 4.2, -12.7, 3.4, 158, 97, 39);
    rectangle(-13.8, 2.6, -13.8, 3.2, -13.35, 3.2, -13.35, 2.6, 158, 97, 39);
    rectangle(-13.15, 2.6, -13.15, 3.2, -12.7, 3.2, -12.7, 2.6, 158, 97, 39);
    rectangle(-13.8, 1.9, -13.8, 2.4, -13.4, 2.4, -13.4, 1.9, 158, 97, 39);
    rectangle(-13.15, 1.9, -13.15, 2.4, -12.7, 2.4, -12.7, 1.9, 158, 97, 39);
}


void leftBridge()
{
    circle(-9.99813, -9.45523, 1.34, 0, 95, 144);
    rectangle(-10,-8.1, 0,-8.1, 0,-9, -9.8,-10.8, 0, 95, 144);
    triangle(-9.8,-10.8, -9.8,-9, 0,-9, 0, 95, 144);
    triangle(-9.8,-10.2, -9.8,-9, 0,-9, 0, 80, 120);

    line(-11.3,-9, -9.8,-10.8, 3, 255,255,255);
    line(-8.7,-9, -9.8,-10.8, 3, 255,255,255);
    line(-8.7,-9, -7.6,-10.4, 3, 255,255,255);
    line(-6.7,-9, -7.6,-10.4, 3, 255,255,255);
    line(-6.7,-9, -5.4,-10, 3, 255,255,255);
    line(-4.7,-9, -5.4,-10, 3, 255,255,255);
    line(-4.7,-9, -3.2,-9.6, 3, 255,255,255);
    line(-2.7,-9, -3.2,-9.6, 3, 255,255,255);
}

void rightBridge()
{
    circle(9.99813, -9.45523, 1.34, 0, 95, 144);
    rectangle(10,-8.1, 0,-8.1, 0,-9, 9.8,-10.8, 0, 95, 144);
    triangle(9.8,-10.8, 9.8,-9, 0,-9, 0, 95, 144);
    triangle(9.8,-10.2, 9.8,-9, 0,-9, 0, 80, 120);

    line(11.3,-9, 9.8,-10.8, 3, 255,255,255);
    line(8.7,-9, 9.8,-10.8, 3, 255,255,255);
    line(8.7,-9, 7.6,-10.4, 3, 255,255,255);
    line(6.7,-9, 7.6,-10.4, 3, 255,255,255);
    line(6.7,-9, 5.4,-10, 3, 255,255,255);
    line(4.7,-9, 5.4,-10, 3, 255,255,255);
    line(4.7,-9, 3.2,-9.6, 3, 255,255,255);
    line(2.7,-9, 3.2,-9.6, 3, 255,255,255);
}

void topBridge()
{
    //rectangle(-11.9,-2.1, -11.9,0.3, 11.9,0.3, 11.9,-2.1, 0, 95, 144);
    rectangle(-11.8,0.85, -11.9,3.4, 11.9,3.4, 11.8,0.85, 0, 95, 144);
    rectangle(-11.3,1.3, -11.3,2.3, 11.3,2.3, 11.3,1.3, 0, 74, 114);
    line(-11.3,1.2, 11.3,1.2, 5, 0, 80, 120);

    line(-11.3,3.4, -10.4,2.3, 3, 255, 255, 255);
    line(-9.7,3.4, -10.4,2.3, 3, 255, 255, 255);
    line(-9.7,3.4, -9,2.3, 3, 255, 255, 255);
    line(-8.2,3.4, -9,2.3, 3, 255, 255, 255);
    line(-8.2,3.4, -7.5,2.3, 3, 255, 255, 255);
    line(-6.7,3.4, -7.5,2.3, 3, 255, 255, 255);
    line(-6.7,3.4, -6,2.3, 3, 255, 255, 255);
    line(-5.2,3.4, -6,2.3, 3, 255, 255, 255);
    line(-5.2,3.4, -4.5,2.3, 3, 255, 255, 255);
    line(-3.7,3.4, -4.5,2.3, 3, 255, 255, 255);
    line(-3.7,3.4, -3,2.3, 3, 255, 255, 255);
    line(-2.3,3.4, -3,2.3, 3, 255, 255, 255);
    line(-2.3,3.4, -1.5,2.3, 3, 255, 255, 255);
    line(-0.8,3.4, -1.5,2.3, 3, 255, 255, 255);

    line(-11.3,2.3, -10.4,3.4, 3, 255, 255, 255);
    line(-9.7,2.3, -10.4,3.4, 3, 255, 255, 255);
    line(-9.7,2.3, -9,3.4, 3, 255, 255, 255);
    line(-8.2,2.3, -9,3.4, 3, 255, 255, 255);
    line(-8.2,2.3, -7.5,3.4, 3, 255, 255, 255);
    line(-6.7,2.3, -7.5,3.4, 3, 255, 255, 255);
    line(-6.7,2.3, -6,3.4, 3, 255, 255, 255);
    line(-5.2,2.3, -6,3.4, 3, 255, 255, 255);
    line(-5.2,2.3, -4.5,3.4, 3, 255, 255, 255);
    line(-3.7,2.3, -4.5,3.4, 3, 255, 255, 255);
    line(-3.7,2.3, -3,3.4, 3, 255, 255, 255);
    line(-2.3,2.3, -3,3.4, 3, 255, 255, 255);
    line(-2.3,2.3, -1.5,3.4, 3, 255, 255, 255);
    line(-0.8,2.3, -1.5,3.4, 3, 255, 255, 255);


    line(11.3,3.4, 10.4,2.3, 3, 255, 255, 255);
    line(9.7,3.4, 10.4,2.3, 3, 255, 255, 255);
    line(9.7,3.4, 9,2.3, 3, 255, 255, 255);
    line(8.2,3.4, 9,2.3, 3, 255, 255, 255);
    line(8.2,3.4, 7.5,2.3, 3, 255, 255, 255);
    line(6.7,3.4, 7.5,2.3, 3, 255, 255, 255);
    line(6.7,3.4, 6,2.3, 3, 255, 255, 255);
    line(5.2,3.4, 6,2.3, 3, 255, 255, 255);
    line(5.2,3.4, 4.5,2.3, 3, 255, 255, 255);
    line(3.7,3.4, 4.5,2.3, 3, 255, 255, 255);
    line(3.7,3.4, 3,2.3, 3, 255, 255, 255);
    line(2.3,3.4, 3,2.3, 3, 255, 255, 255);
    line(2.3,3.4, 1.5,2.3, 3, 255, 255, 255);
    line(0.8,3.4, 1.5,2.3, 3, 255, 255, 255);

    line(11.3,2.3, 10.4,3.4, 3, 255, 255, 255);
    line(9.7,2.3, 10.4,3.4, 3, 255, 255, 255);
    line(9.7,2.3, 9,3.4, 3, 255, 255, 255);
    line(8.2,2.3, 9,3.4, 3, 255, 255, 255);
    line(8.2,2.3, 7.5,3.4, 3, 255, 255, 255);
    line(6.7,2.3, 7.5,3.4, 3, 255, 255, 255);
    line(6.7,2.3, 6,3.4, 3, 255, 255, 255);
    line(5.2,2.3, 6,3.4, 3, 255, 255, 255);
    line(5.2,2.3, 4.5,3.4, 3, 255, 255, 255);
    line(3.7,2.3, 4.5,3.4, 3, 255, 255, 255);
    line(3.7,2.3, 3,3.4, 3, 255, 255, 255);
    line(2.3,2.3, 3,3.4, 3, 255, 255, 255);
    line(2.3,2.3, 1.5,3.4, 3, 255, 255, 255);
    line(0.8,2.3, 1.5,3.4, 3, 255, 255, 255);

    rectangle(-0.9,2.3, -0.9,3.95, 0.9,3.95, 0.9,2.3, 223, 178, 110);
}



//bridge
void bridge()
{

    topBridge();
    spin(bAngle, -9.99813, -9.45523, leftBridge);
    spin(-bAngle, 9.99813, -9.45523, rightBridge);
    mainPillar();
    shift(26.4, 0, mainPillar);
}


void wheel(double x, double y)
{
    circle(x, y, 1.38, 0, 0, 0);
    circle(x, y, 1, 110, 0, 0);
    line(x-1.2,y, x+1.2,y, 15, 0, 0, 0);
    line(x,y-1.2, x,y+1.2, 15, 0, 0, 0);
    line(x-1,y-0.8, x+1,y+0.8, 15, 0, 0, 0);
    line(x-1,y+0.8, x+1,y-0.8, 15, 0, 0, 0);
    circle(x, y, 0.25, 110, 110, 0);
    circle(x, y, 0.25, 90, 90, 90);
    circle(x, y, 0.2, 0, 0, 0);
}

//C001
void car1()
{
    glPushMatrix();
    glTranslatef(0, -7.9, 0.0f);
    glScalef(0.1f, 0.1f, 1.0f);

    //body
    glBegin(GL_POLYGON);
    glColor3ub(255, 0, 0);
    glVertex2f(-6.75775, -3.302);
    glVertex2f(-7.14067, -2.64386);
    glVertex2f(-7.28426, -2.04556);
    glVertex2f(-6.8537, -1.12561);
    glVertex2f(-6, -0.5);
    glVertex2f(-4, -0.4);
    glVertex2f(-1, 2);
    glVertex2f(4, 2);
    glVertex2f(6, -0.2);
    glVertex2f(6.98642, -0.30021);
    glVertex2f(7.60863, -0.81423);
    glVertex2f(7.65438, -1.87294);
    glVertex2f(7.61746, -2.93692);
    glVertex2f(7.2, -3.3);
    glEnd();

    //outline
    line(-6.75775, -3.302, -7.14067, -2.64386, 2, 0,0,0);
    line(-7.14067, -2.64386, -7.28426, -2.04556, 2, 0,0,0);
    line(-7.28426, -2.04556, -6.8537, -1.12561, 2, 0,0,0);
    line(-6.8537, -1.12561, -6, -0.5, 2, 0,0,0);
    line(-6, -0.5, -4, -0.4, 2, 0,0,0);
    line(-4, -0.4, -1, 2, 2, 0,0,0);
    line(-1, 2, 4, 2, 2, 0,0,0);
    line(4, 2, 6, -0.2, 2, 0,0,0);
    line(6, -0.2, 6.98642, -0.30021, 2, 0,0,0);
    line(6.98642, -0.30021, 7.60863, -0.81423, 2, 0,0,0);
    line(7.60863, -0.81423, 7.65438, -1.87294, 2, 0,0,0);
    line(7.65438, -1.87294, 7.61746, -2.93692, 2, 0,0,0);
    line(7.61746, -2.93692, 7.2, -3.3, 2, 0,0,0);
    line(-6.75775, -3.302, 7.2, -3.3, 2, 0,0,0);

    //front window
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(-2.7, -0.4);
    glVertex2f(-2.7, 0.4);
    glVertex2f(-0.9, 1.8);
    glVertex2f(1, 1.8);
    glVertex2f(1, -0.35);
    glEnd();

    //back window
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(1.2, -0.35);
    glVertex2f(1.2, 1.8);
    glVertex2f(3.9, 1.8);
    glVertex2f(5, 0.5);
    glVertex2f(5, -0.3);
    glEnd();

    //front peak
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(-3.675, -0.4);
    glVertex2f(-2.9, 0.2);
    glVertex2f(-2.9, -0.4);
    glEnd();
    line(-3.675, -0.4, -2.9, 0.2, 2, 0,0,0);
    line(-2.9, 0.2, -2.9, -0.4, 2, 0,0,0);
    line(-2.9, -0.4, -3.675, -0.4, 2, 0,0,0);

    //back peak
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(5.17714, -0.3);
    glVertex2f(5.17714, 0.37767);
    glVertex2f(5.7, -0.2);
    glEnd();
    line(5.17714, -0.3, 5.17714, 0.37767, 2, 0,0,0);
    line(5.17714, 0.37767, 5.7, -0.2, 2, 0,0,0);
    line(5.7, -0.2, 5.17714, -0.3, 2, 0,0,0);

    //door handle
    line(0.2, -0.8, 0.8, -0.8, 5, 255,100,100);
    line(4.1, -0.8, 4.7, -0.8, 5, 255,100,100);

    //front light
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(-6.8537, -1.12561);
    glVertex2f(-6, -0.5);
    glVertex2f(-6.01266, -0.89623);
    glEnd();
    line(-6.8537, -1.12561, -6, -0.5, 2, 0,0,0);
    line(-6, -0.5, -6.01266, -0.89623, 2, 0,0,0);
    line(-6.01266, -0.89623, -6.8537, -1.12561, 2, 0,0,0);

    //back light
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(7.65438, -1.87294);
    glVertex2f(7.44385, -1.61155);
    glVertex2f(7.4, -0.9);
    glVertex2f(7.60863, -0.81423);
    glEnd();
    line(7.65438, -1.87294, 7.44385, -1.61155, 2, 0,0,0);
    line(7.44385, -1.61155, 7.4, -0.9, 2, 0,0,0);
    line(7.4, -0.9, 7.60863, -0.81423, 2, 0,0,0);
    line(7.60863, -0.81423, 7.65438, -1.87294, 2, 0,0,0);

    //front door
    line(-2.7,-3.3, -2.7,0.4, 2, 0,0,0);
    line(-0.9, 1.8, -2.7,0.4, 2, 0,0,0);
    line(-0.9, 1.8, 1, 1.8, 2, 0,0,0);
    line(1, -3.3, 1, 1.8, 2, 0,0,0);
    line(-2.7, -0.4, 1, -0.35, 2, 0,0,0);

    //back door
    line(1.2, -3.3, 1.2, 1.8, 2, 0,0,0);
    line(3.9, 1.8, 1.2, 1.8, 2, 0,0,0);
    line(3.9, 1.8, 5, 0.5, 2, 0,0,0);
    line(5.0042, -1.46109, 5, 0.5, 2, 0,0,0);
    line(5.0042, -1.46109, 4.70153, -1.48233, 2, 0,0,0);
    line(4.3, -1.6, 4.70153, -1.48233, 2, 0,0,0);
    line(4.3, -1.6, 4, -1.8, 2, 0,0,0);
    line(3.74307, -2.10049, 4, -1.8, 2, 0,0,0);
    line(3.74307, -2.10049, 3.5, -2.5, 2, 0,0,0);
    line(3.43362, -3.05421, 3.5, -2.5, 2, 0,0,0);
    line(3.43362, -3.05421, 3.5, -3.3, 2, 0,0,0);
    line(1.2, -0.35, 5, -0.3, 2, 0,0,0);

    // spin(-4.8, -3, wheel);
    // spin(5, -3, wheel);

    glPopMatrix();
}

//C002
void car2()
{
    glPushMatrix();
    glTranslatef(0, -7.9, 0.0f);
    glScalef(0.1f, 0.1f, 1.0f);

    //body
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 255);
    glVertex2f(-6.75775, -3.302);
    glVertex2f(-7.14067, -2.64386);
    glVertex2f(-7.28426, -2.04556);
    glVertex2f(-6.8537, -1.12561);
    glVertex2f(-6, -0.5);
    glVertex2f(-4, -0.4);
    glVertex2f(-1, 2);
    glVertex2f(4, 2);
    glVertex2f(6, -0.2);
    glVertex2f(6.98642, -0.30021);
    glVertex2f(7.60863, -0.81423);
    glVertex2f(7.65438, -1.87294);
    glVertex2f(7.61746, -2.93692);
    glVertex2f(7.2, -3.3);
    glEnd();

    //outline
    line(-6.75775, -3.302, -7.14067, -2.64386, 2, 0,0,0);
    line(-7.14067, -2.64386, -7.28426, -2.04556, 2, 0,0,0);
    line(-7.28426, -2.04556, -6.8537, -1.12561, 2, 0,0,0);
    line(-6.8537, -1.12561, -6, -0.5, 2, 0,0,0);
    line(-6, -0.5, -4, -0.4, 2, 0,0,0);
    line(-4, -0.4, -1, 2, 2, 0,0,0);
    line(-1, 2, 4, 2, 2, 0,0,0);
    line(4, 2, 6, -0.2, 2, 0,0,0);
    line(6, -0.2, 6.98642, -0.30021, 2, 0,0,0);
    line(6.98642, -0.30021, 7.60863, -0.81423, 2, 0,0,0);
    line(7.60863, -0.81423, 7.65438, -1.87294, 2, 0,0,0);
    line(7.65438, -1.87294, 7.61746, -2.93692, 2, 0,0,0);
    line(7.61746, -2.93692, 7.2, -3.3, 2, 0,0,0);
    line(-6.75775, -3.302, 7.2, -3.3, 2, 0,0,0);

    //front window
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(-2.7, -0.4);
    glVertex2f(-2.7, 0.4);
    glVertex2f(-0.9, 1.8);
    glVertex2f(1, 1.8);
    glVertex2f(1, -0.35);
    glEnd();

    //back window
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(1.2, -0.35);
    glVertex2f(1.2, 1.8);
    glVertex2f(3.9, 1.8);
    glVertex2f(5, 0.5);
    glVertex2f(5, -0.3);
    glEnd();

    //front peak
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(-3.675, -0.4);
    glVertex2f(-2.9, 0.2);
    glVertex2f(-2.9, -0.4);
    glEnd();
    line(-3.675, -0.4, -2.9, 0.2, 2, 0,0,0);
    line(-2.9, 0.2, -2.9, -0.4, 2, 0,0,0);
    line(-2.9, -0.4, -3.675, -0.4, 2, 0,0,0);

    //back peak
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(5.17714, -0.3);
    glVertex2f(5.17714, 0.37767);
    glVertex2f(5.7, -0.2);
    glEnd();
    line(5.17714, -0.3, 5.17714, 0.37767, 2, 0,0,0);
    line(5.17714, 0.37767, 5.7, -0.2, 2, 0,0,0);
    line(5.7, -0.2, 5.17714, -0.3, 2, 0,0,0);

    //door handle
    line(0.2, -0.8, 0.8, -0.8, 5, 255,100,100);
    line(4.1, -0.8, 4.7, -0.8, 5, 255,100,100);

    //front light
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(-6.8537, -1.12561);
    glVertex2f(-6, -0.5);
    glVertex2f(-6.01266, -0.89623);
    glEnd();
    line(-6.8537, -1.12561, -6, -0.5, 2, 0,0,0);
    line(-6, -0.5, -6.01266, -0.89623, 2, 0,0,0);
    line(-6.01266, -0.89623, -6.8537, -1.12561, 2, 0,0,0);

    //back light
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(7.65438, -1.87294);
    glVertex2f(7.44385, -1.61155);
    glVertex2f(7.4, -0.9);
    glVertex2f(7.60863, -0.81423);
    glEnd();
    line(7.65438, -1.87294, 7.44385, -1.61155, 2, 0,0,0);
    line(7.44385, -1.61155, 7.4, -0.9, 2, 0,0,0);
    line(7.4, -0.9, 7.60863, -0.81423, 2, 0,0,0);
    line(7.60863, -0.81423, 7.65438, -1.87294, 2, 0,0,0);

    //front door
    line(-2.7,-3.3, -2.7,0.4, 2, 0,0,0);
    line(-0.9, 1.8, -2.7,0.4, 2, 0,0,0);
    line(-0.9, 1.8, 1, 1.8, 2, 0,0,0);
    line(1, -3.3, 1, 1.8, 2, 0,0,0);
    line(-2.7, -0.4, 1, -0.35, 2, 0,0,0);

    //back door
    line(1.2, -3.3, 1.2, 1.8, 2, 0,0,0);
    line(3.9, 1.8, 1.2, 1.8, 2, 0,0,0);
    line(3.9, 1.8, 5, 0.5, 2, 0,0,0);
    line(5.0042, -1.46109, 5, 0.5, 2, 0,0,0);
    line(5.0042, -1.46109, 4.70153, -1.48233, 2, 0,0,0);
    line(4.3, -1.6, 4.70153, -1.48233, 2, 0,0,0);
    line(4.3, -1.6, 4, -1.8, 2, 0,0,0);
    line(3.74307, -2.10049, 4, -1.8, 2, 0,0,0);
    line(3.74307, -2.10049, 3.5, -2.5, 2, 0,0,0);
    line(3.43362, -3.05421, 3.5, -2.5, 2, 0,0,0);
    line(3.43362, -3.05421, 3.5, -3.3, 2, 0,0,0);
    line(1.2, -0.35, 5, -0.3, 2, 0,0,0);

    // spin(-4.8, -3, wheel);
    // spin(5, -3, wheel);

    glPopMatrix();
}

//C003
void car3()
{
    glPushMatrix();
    glTranslatef(0, -7.9, 0.0f);
    glScalef(0.1f, 0.1f, 1.0f);

    //body
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 100);
    glVertex2f(-6.75775, -3.302);
    glVertex2f(-7.14067, -2.64386);
    glVertex2f(-7.28426, -2.04556);
    glVertex2f(-6.8537, -1.12561);
    glVertex2f(-6, -0.5);
    glVertex2f(-4, -0.4);
    glVertex2f(-1, 2);
    glVertex2f(4, 2);
    glVertex2f(6, -0.2);
    glVertex2f(6.98642, -0.30021);
    glVertex2f(7.60863, -0.81423);
    glVertex2f(7.65438, -1.87294);
    glVertex2f(7.61746, -2.93692);
    glVertex2f(7.2, -3.3);
    glEnd();

    //outline
    line(-6.75775, -3.302, -7.14067, -2.64386, 2, 0,0,0);
    line(-7.14067, -2.64386, -7.28426, -2.04556, 2, 0,0,0);
    line(-7.28426, -2.04556, -6.8537, -1.12561, 2, 0,0,0);
    line(-6.8537, -1.12561, -6, -0.5, 2, 0,0,0);
    line(-6, -0.5, -4, -0.4, 2, 0,0,0);
    line(-4, -0.4, -1, 2, 2, 0,0,0);
    line(-1, 2, 4, 2, 2, 0,0,0);
    line(4, 2, 6, -0.2, 2, 0,0,0);
    line(6, -0.2, 6.98642, -0.30021, 2, 0,0,0);
    line(6.98642, -0.30021, 7.60863, -0.81423, 2, 0,0,0);
    line(7.60863, -0.81423, 7.65438, -1.87294, 2, 0,0,0);
    line(7.65438, -1.87294, 7.61746, -2.93692, 2, 0,0,0);
    line(7.61746, -2.93692, 7.2, -3.3, 2, 0,0,0);
    line(-6.75775, -3.302, 7.2, -3.3, 2, 0,0,0);

    //front window
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(-2.7, -0.4);
    glVertex2f(-2.7, 0.4);
    glVertex2f(-0.9, 1.8);
    glVertex2f(1, 1.8);
    glVertex2f(1, -0.35);
    glEnd();

    //back window
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(1.2, -0.35);
    glVertex2f(1.2, 1.8);
    glVertex2f(3.9, 1.8);
    glVertex2f(5, 0.5);
    glVertex2f(5, -0.3);
    glEnd();

    //front peak
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(-3.675, -0.4);
    glVertex2f(-2.9, 0.2);
    glVertex2f(-2.9, -0.4);
    glEnd();
    line(-3.675, -0.4, -2.9, 0.2, 2, 0,0,0);
    line(-2.9, 0.2, -2.9, -0.4, 2, 0,0,0);
    line(-2.9, -0.4, -3.675, -0.4, 2, 0,0,0);

    //back peak
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(5.17714, -0.3);
    glVertex2f(5.17714, 0.37767);
    glVertex2f(5.7, -0.2);
    glEnd();
    line(5.17714, -0.3, 5.17714, 0.37767, 2, 0,0,0);
    line(5.17714, 0.37767, 5.7, -0.2, 2, 0,0,0);
    line(5.7, -0.2, 5.17714, -0.3, 2, 0,0,0);

    //door handle
    line(0.2, -0.8, 0.8, -0.8, 5, 255,100,100);
    line(4.1, -0.8, 4.7, -0.8, 5, 255,100,100);

    //front light
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(-6.8537, -1.12561);
    glVertex2f(-6, -0.5);
    glVertex2f(-6.01266, -0.89623);
    glEnd();
    line(-6.8537, -1.12561, -6, -0.5, 2, 0,0,0);
    line(-6, -0.5, -6.01266, -0.89623, 2, 0,0,0);
    line(-6.01266, -0.89623, -6.8537, -1.12561, 2, 0,0,0);

    //back light
    glBegin(GL_POLYGON);
    glColor3ub(0, 255, 255);
    glVertex2f(7.65438, -1.87294);
    glVertex2f(7.44385, -1.61155);
    glVertex2f(7.4, -0.9);
    glVertex2f(7.60863, -0.81423);
    glEnd();
    line(7.65438, -1.87294, 7.44385, -1.61155, 2, 0,0,0);
    line(7.44385, -1.61155, 7.4, -0.9, 2, 0,0,0);
    line(7.4, -0.9, 7.60863, -0.81423, 2, 0,0,0);
    line(7.60863, -0.81423, 7.65438, -1.87294, 2, 0,0,0);

    //front door
    line(-2.7,-3.3, -2.7,0.4, 2, 0,0,0);
    line(-0.9, 1.8, -2.7,0.4, 2, 0,0,0);
    line(-0.9, 1.8, 1, 1.8, 2, 0,0,0);
    line(1, -3.3, 1, 1.8, 2, 0,0,0);
    line(-2.7, -0.4, 1, -0.35, 2, 0,0,0);

    //back door
    line(1.2, -3.3, 1.2, 1.8, 2, 0,0,0);
    line(3.9, 1.8, 1.2, 1.8, 2, 0,0,0);
    line(3.9, 1.8, 5, 0.5, 2, 0,0,0);
    line(5.0042, -1.46109, 5, 0.5, 2, 0,0,0);
    line(5.0042, -1.46109, 4.70153, -1.48233, 2, 0,0,0);
    line(4.3, -1.6, 4.70153, -1.48233, 2, 0,0,0);
    line(4.3, -1.6, 4, -1.8, 2, 0,0,0);
    line(3.74307, -2.10049, 4, -1.8, 2, 0,0,0);
    line(3.74307, -2.10049, 3.5, -2.5, 2, 0,0,0);
    line(3.43362, -3.05421, 3.5, -2.5, 2, 0,0,0);
    line(3.43362, -3.05421, 3.5, -3.3, 2, 0,0,0);
    line(1.2, -0.35, 5, -0.3, 2, 0,0,0);

    glPopMatrix();
}

//C004
void car4()
{
    glPushMatrix();
    glTranslatef(20, -9.9, 0.0f);
    glScalef(0.45f, 0.45f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3ub(229, 231, 209);
    glVertex2f(-5.1, 7.2);
    glVertex2f(-4.7, 7.3);
    glVertex2f(-3.6, 7.4);
    glVertex2f(-2.7, 7.4);
    glVertex2f(-1.4, 7.4);
    glVertex2f(-0.5, 7.36);
    glVertex2f(2, 7.3);
    glVertex2f(6.6, 7.3);
    glVertex2f(6.8, 7);
    glVertex2f(6.9, 6.6);
    glVertex2f(6.9, 4.9);
    glVertex2f(6.9, 4);
    glVertex2f(6.85, 3.8);
    glVertex2f(6.8, 3.7);
    glVertex2f(6.4, 3.6);
    glVertex2f(6.4, 3.6);
    glVertex2f(5.3, 3.4);
    glVertex2f(3.7, 3.4);
    glVertex2f(-4.8, 3.5);
    glVertex2f(-5.8, 3.6);
    glVertex2f(-5.9, 3.55);
    glVertex2f(-6, 3.7);
    glVertex2f(-6.09, 3.8);
    glVertex2f(-6.1, 3.9);
    glVertex2f(-6.06, 4.7);
    glVertex2f(-6.06, 5);
    glVertex2f(-6, 5);
    glVertex2f(-5.9, 6.2);
    glVertex2f(-5.8, 6.6);
    glVertex2f(-5.6, 6.9);
    glVertex2f(-5.5, 7);
    glVertex2f(-5.1, 7.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-5.4, 7);
    glVertex2f(6.2, 7);
    glVertex2f(6.27, 6.6);
    glVertex2f(6.3, 6.3);
    glVertex2f(6.29, 6);
    glVertex2f(6.2, 5.8);
    glVertex2f(5.9, 5.6);
    glVertex2f(-4.2, 5.6);
    glVertex2f(-4.3, 5.5);
    glVertex2f(-4.5, 5.3);
    glVertex2f(-4.7, 5);
    glVertex2f(-4.9, 4.7);
    glVertex2f(-5, 4.5);
    glVertex2f(-5.1, 4.44);
    glVertex2f(-5.4, 4.39);
    glVertex2f(-5.7, 4.4);
    glVertex2f(-5.7, 4.5);
    glVertex2f(-5.73, 4.66);
    glVertex2f(-5.8, 4.72);
    glVertex2f(-6.1, 4.7);
    glVertex2f(-6.06, 5);
    glVertex2f(-6, 5.6);
    glVertex2f(-5.9, 6.2);
    glVertex2f(-5.8, 6.6);
    glVertex2f(-5.6, 6.9);
    glVertex2f(-5.4, 7);
    glEnd();

    line(-5.65, 4.4, -5.7, 4, 1, 0,0,0);
    line(-5.7, 3.8, -5.7, 4, 1, 0,0,0);
    line(-5.7, 3.8, -5.6, 3.7, 1, 0,0,0);
    line(-5.5, 3.6, -5.6, 3.7, 1, 0,0,0);
    line(-4.8, 4.8, -4.8, 3.6, 1, 0,0,0);

    circle(-3.2, 3.7, 0.55, 0,0,0);
    circle(-3.2, 3.7, 0.35, 0,0,0);

    circle(3, 3.7, 0.55, 0,0,0);
    circle(3, 3.7, 0.35, 0,0,0);
    glPopMatrix();
}

//C005
void car5()
{
    glPushMatrix();
    glTranslatef(-20, -9.9, 0.0f);
    glScalef(0.45f, 0.45f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3ub(147, 239, 147);
    glVertex2f(5.1, 7.2);
    glVertex2f(4.7, 7.3);
    glVertex2f(3.6, 7.4);
    glVertex2f(2.7, 7.4);
    glVertex2f(1.4, 7.4);
    glVertex2f(0.5, 7.36);
    glVertex2f(-2, 7.3);
    glVertex2f(-6.6, 7.3);
    glVertex2f(-6.8, 7);
    glVertex2f(-6.9, 6.6);
    glVertex2f(-6.9, 4.9);
    glVertex2f(-6.9, 4);
    glVertex2f(-6.85, 3.8);
    glVertex2f(-6.8, 3.7);
    glVertex2f(-6.4, 3.6);
    glVertex2f(-6.4, 3.6);
    glVertex2f(-5.3, 3.4);
    glVertex2f(-3.7, 3.4);
    glVertex2f(4.8, 3.5);
    glVertex2f(5.8, 3.6);
    glVertex2f(5.9, 3.55);
    glVertex2f(6, 3.7);
    glVertex2f(6.09, 3.8);
    glVertex2f(6.1, 3.9);
    glVertex2f(6.06, 4.7);
    glVertex2f(6.06, 5);
    glVertex2f(6, 5);
    glVertex2f(5.9, 6.2);
    glVertex2f(5.8, 6.6);
    glVertex2f(5.6, 6.9);
    glVertex2f(5.5, 7);
    glVertex2f(5.1, 7.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(5.4, 7);
    glVertex2f(-6.2, 7);
    glVertex2f(-6.27, 6.6);
    glVertex2f(-6.3, 6.3);
    glVertex2f(-6.29, 6);
    glVertex2f(-6.2, 5.8);
    glVertex2f(-5.9, 5.6);
    glVertex2f(4.2, 5.6);
    glVertex2f(4.3, 5.5);
    glVertex2f(4.5, 5.3);
    glVertex2f(4.7, 5);
    glVertex2f(4.9, 4.7);
    glVertex2f(5, 4.5);
    glVertex2f(5.1, 4.44);
    glVertex2f(5.4, 4.39);
    glVertex2f(5.7, 4.4);
    glVertex2f(5.7, 4.5);
    glVertex2f(5.73, 4.66);
    glVertex2f(5.8, 4.72);
    glVertex2f(6.1, 4.7);
    glVertex2f(6.06, 5);
    glVertex2f(6, 5.6);
    glVertex2f(5.9, 6.2);
    glVertex2f(5.8, 6.6);
    glVertex2f(5.6, 6.9);
    glVertex2f(5.4, 7);
    glEnd();

    line(5.65, 4.4, 5.7, 4, 1, 0,0,0);
    line(5.7, 3.8, 5.7, 4, 1, 0,0,0);
    line(5.7, 3.8, 5.6, 3.7, 1, 0,0,0);
    line(5.5, 3.6, 5.6, 3.7, 1, 0,0,0);
    line(4.8, 4.8, 4.8, 3.6, 1, 0,0,0);

    circle(3.2, 3.7, 0.55, 0,0,0);
    circle(3.2, 3.7, 0.35, 0,0,0);

    circle(-3, 3.7, 0.55, 0,0,0);
    circle(-3, 3.7, 0.35, 0,0,0);
    glPopMatrix();
}

//C006
void car6()
{
    glTranslatef(25, -9.9, 0.0f);
    glScalef(0.1f, 0.1f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3ub(174, 174, 174);
    glVertex2f(-8.6, 16.7);
    glVertex2f(-9.2, 18);
    glVertex2f(-9, 18.6);
    glVertex2f(-8.7, 19.2);
    glVertex2f(-8.4, 19.6);
    glVertex2f(-8.1, 19.8);
    glVertex2f(-7.8, 20);
    glVertex2f(-6.6, 20.2);
    glVertex2f(-4.7, 20.5);
    glVertex2f(-4.4, 20.7);
    glVertex2f(-3.49, 20.9);
    glVertex2f(-3, 21.4);
    glVertex2f(-1.7, 22.1);
    glVertex2f(-1.1, 22.4);
    glVertex2f(-0.4, 22.5);
    glVertex2f(0, 22.6);
    glVertex2f(0.4, 22.7);
    glVertex2f(2.1, 22.7);
    glVertex2f(4.4, 22.6);
    glVertex2f(5.4, 22.5);
    glVertex2f(6.4, 22.4);
    glVertex2f(7.9, 22.1);
    glVertex2f(7.7, 22);
    glVertex2f(7.6, 21.9);
    glVertex2f(7.6, 21.8);
    glVertex2f(7.9, 21.6);
    glVertex2f(8.6, 20.6);
    glVertex2f(8.8, 20.3);
    glVertex2f(8.9, 20.1);
    glVertex2f(8.9, 19.8);
    glVertex2f(8.8, 19.4);
    glVertex2f(8.8, 19.2);
    glVertex2f(9, 18.9);
    glVertex2f(9.2, 18.5);
    glVertex2f(9.1, 18);
    glVertex2f(9, 17.4);
    glVertex2f(8.7, 17.3);
    glVertex2f(8.4, 17.3);
    glVertex2f(8.1, 17.1);
    glVertex2f(4.5, 17);
    glVertex2f(-3.8, 16.9);
    glVertex2f(-7.1, 16.8);
    glVertex2f(-8.6, 16.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(3, 3, 3);
    glVertex2f(-3, 20.6);
    glVertex2f(-3.6, 20.8);
    glVertex2f(-2.2, 21.5);
    glVertex2f(-1, 22);
    glVertex2f(-0.3, 22.2);
    glVertex2f(-0.3, 22.3);
    glVertex2f(1.9, 22.3);
    glVertex2f(1.8, 20.9);
    glVertex2f(-3, 20.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(3, 3, 3);
    glVertex2f(1.8, 20.9);
    glVertex2f(1.9, 22.3);
    glVertex2f(3.2, 22.3);
    glVertex2f(4.2, 22.2);
    glVertex2f(5, 22);
    glVertex2f(5.9, 21.3);
    glVertex2f(6.1, 21);
    glVertex2f(5.9, 20.8);
    glVertex2f(1.8, 20.9);
    glEnd();

    line(-3.6, 20.8, -3.6, 19.5, 1, 0,0,0);
    line(-3.3, 18.7, -3.6, 19.5, 1, 0,0,0);
    line(-3.3, 18.7, -2.8, 17.4, 1, 0,0,0);
    line(1.8, 20.9, 2.1, 20.1, 1, 0,0,0);
    line(2.2, 19.8, 2.1, 20.1, 1, 0,0,0);
    line(2.2, 19.8, 2, 19, 1, 0,0,0);
    line(1.7, 17.9, 2, 19, 1, 0,0,0);
    line(1.7, 17.9, 1.7, 17.5, 1, 0,0,0);
    line(5.9, 20.8, 6.2, 20.1, 1, 0,0,0);
    line(6.2, 19.8, 6.2, 20.1, 1, 0,0,0);
    line(6.2, 19.8, 6, 19.3, 1, 0,0,0);
    line(1, 20, 1.6, 20, 2, 0,0,0);
    line(5, 20, 5.6, 20, 2, 0,0,0);


    circle(-5.43605, 17.5095, 1.6, 0,0,0);
    circle(6.33868, 17.49617, 1.6, 0,0,0);
    circle(-8.61748, 18.91857, 0.5, 255,255,0);
    glPopMatrix();
}

//C007
void car7()
{
    glTranslatef(-25, -9.9, 0.0f);
    glScalef(0.1f, 0.1f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3ub(0, 98, 170);
    glVertex2f(8.6, 16.7);
    glVertex2f(9.2, 18);
    glVertex2f(9, 18.6);
    glVertex2f(8.7, 19.2);
    glVertex2f(8.4, 19.6);
    glVertex2f(8.1, 19.8);
    glVertex2f(7.8, 20);
    glVertex2f(6.6, 20.2);
    glVertex2f(4.7, 20.5);
    glVertex2f(4.4, 20.7);
    glVertex2f(3.49, 20.9);
    glVertex2f(3, 21.4);
    glVertex2f(1.7, 22.1);
    glVertex2f(1.1, 22.4);
    glVertex2f(0.4, 22.5);
    glVertex2f(-0, 22.6);
    glVertex2f(-0.4, 22.7);
    glVertex2f(-2.1, 22.7);
    glVertex2f(-4.4, 22.6);
    glVertex2f(-5.4, 22.5);
    glVertex2f(-6.4, 22.4);
    glVertex2f(-7.9, 22.1);
    glVertex2f(-7.7, 22);
    glVertex2f(-7.6, 21.9);
    glVertex2f(-7.6, 21.8);
    glVertex2f(-7.9, 21.6);
    glVertex2f(-8.6, 20.6);
    glVertex2f(-8.8, 20.3);
    glVertex2f(-8.9, 20.1);
    glVertex2f(-8.9, 19.8);
    glVertex2f(-8.8, 19.4);
    glVertex2f(-8.8, 19.2);
    glVertex2f(-9, 18.9);
    glVertex2f(-9.2, 18.5);
    glVertex2f(-9.1, 18);
    glVertex2f(-9, 17.4);
    glVertex2f(-8.7, 17.3);
    glVertex2f(-8.4, 17.3);
    glVertex2f(-8.1, 17.1);
    glVertex2f(-4.5, 17);
    glVertex2f(3.8, 16.9);
    glVertex2f(7.1, 16.8);
    glVertex2f(8.6, 16.7);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(3, 3, 3);
    glVertex2f(3, 20.6);
    glVertex2f(3.6, 20.8);
    glVertex2f(2.2, 21.5);
    glVertex2f(1, 22);
    glVertex2f(0.3, 22.2);
    glVertex2f(0.3, 22.3);
    glVertex2f(-1.9, 22.3);
    glVertex2f(-1.8, 20.9);
    glVertex2f(3, 20.6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(3, 3, 3);
    glVertex2f(-1.8, 20.9);
    glVertex2f(-1.9, 22.3);
    glVertex2f(-3.2, 22.3);
    glVertex2f(-4.2, 22.2);
    glVertex2f(-5, 22);
    glVertex2f(-5.9, 21.3);
    glVertex2f(-6.1, 21);
    glVertex2f(-5.9, 20.8);
    glVertex2f(-1.8, 20.9);
    glEnd();

    line(3.6, 20.8, 3.6, 19.5, 1, 0,0,0);
    line(3.3, 18.7, 3.6, 19.5, 1, 0,0,0);
    line(3.3, 18.7, 2.8, 17.4, 1, 0,0,0);
    line(-1.8, 20.9, -2.1, 20.1, 1, 0,0,0);
    line(-2.2, 19.8, -2.1, 20.1, 1, 0,0,0);
    line(-2.2, 19.8, -2, 19, 1, 0,0,0);
    line(-1.7, 17.9, -2, 19, 1, 0,0,0);
    line(-1.7, 17.9, -1.7, 17.5, 1, 0,0,0);
    line(-5.9, 20.8, -6.2, 20.1, 1, 0,0,0);
    line(-6.2, 19.8, -6.2, 20.1, 1, 0,0,0);
    line(-6.2, 19.8, -6, 19.3, 1, 0,0,0);
    line(-1, 20, -1.6, 20, 2, 0,0,0);
    line(-5, 20, -5.6, 20, 2, 0,0,0);


    circle(5.43605, 17.5095, 1.6, 0,0,0);
    circle(-6.33868, 17.49617, 1.6, 0,0,0);
    circle(8.61748, 18.91857, 0.5, 255,255,0);
    glPopMatrix();
}

float up = 0;
float upSpd = 0.009;
bool isBroken = false;
void boatMove(float s, void (*callback)(void))
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    //cout<<up<<endl;
    if(up >= 21 && up< 22)
    {
        if(bAngle >= 40)
        {
            upSpd = 0.003;
            glTranslatef(0.0f,up, 0.0);
            glScalef(s, s, 1.0f);
            shift(0, -18, callback);
        }
        else
        {
            upSpd = 0.003;
            glTranslatef(0.0f,up, 0.0);
            glScalef(s, s, 1.0f);
            shift(0, -18, broken_boat1);
            isBroken = true;
        }
    }
    else
    {
        if(!isBroken)
        {
            glTranslatef(0.0f,up, 0.0);
            glScalef(s, s, 1.0f);
            shift(0, -18, callback);
        }
        else
        {
            glTranslatef(0.0f,up, 0.0);
            glScalef(s, s, 1.0f);
            shift(0, -18, broken_boat1);
        }

    }
    glPopMatrix();
}



int sr=135, sg=233, sb=240;
void displayDay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    sky(sr, sg, sb);
    rightBackgroudBuilding();
    leftBackgroudBuilding();
    londonEye();
    bigBen();
    river();
  boatMove(boat1Move, boat1);
     moove(car4Move, car4);
    moove(car1Move, car1);
    moove(car2Move, car2);
    moove(car3Move, car3);
    moove(car5Move, car5);
    moove(car6Move, car6);
    moove(car7Move, car7);
     road();
    bridge();
   moove(boat2Move, boat2);
    moove(boat4Move, boat4);
    moove(boat5Move, boat5);
    moove(boat3Move, boat3);
    glFlush();
}


void display()
{
 displayDay();
}

float move1 = 0;
void update(int value)
{
    _angle1 = _angle1+speed;

    boat1Move = boat1Move + boat1Speed;
    up = up + upSpd;
    if(boat1Move <-18)
    {
        boat1Move = 0;
    }

    _move += .03;
    if(_move > 5)
    {
        _move = -5;
    }

    if(bAngle == 0)
    {
        car1Move = car1Move - car1Speed;
    }
    else
    {
        if(car1Move >= 0)
        {
            if(car1Move > 11)
            {
                if(car1Move > 11.5)
                {
                    car1Move = car1Move - car1Speed;
                }
            }
            else
            {
                car1Move = car1Move + (0.06*2);
            }
        }
        else
        {
            if(car1Move < -11)
            {
                car1Move = car1Move - car1Speed;
            }
            else
            {
                car1Move = car1Move - (0.06*2);
            }
        }
    }
    if(car1Move < -30)
    {
        car1Move = 27;
    }

    if(bAngle == 0)
    {
        car2Move = car2Move - car2Speed;
    }
    else
    {
        if(car2Move >= 0)
        {
            if(car2Move > 11)
            {
                if(car2Move > 11.5)
                {
                    car2Move = car2Move - car2Speed;
                }
            }
            else
            {
                car2Move = car2Move + (0.06*2);
            }
        }
        else
        {
            if(car2Move < -11)
            {
                car2Move = car2Move - car2Speed;
            }
            else
            {
                car2Move = car2Move - (car2Speed*2);
            }
        }
    }
    if(car2Move < -30)
    {
        car2Move = 27;
    }

    if(bAngle == 0)
    {
        car3Move = car3Move - car3Speed;
    }
    else
    {
        if(car3Move >= 0)
        {
            if(car3Move > 11)
            {
                if(car3Move > 11.5)
                {
                    car3Move = car3Move - car3Speed;
                }
            }
            else
            {
                car3Move = car3Move + (0.06*2);
            }
        }
        else
        {
            if(car3Move < -11)
            {
                car3Move = car3Move - car3Speed;
            }
            else
            {
                car3Move = car3Move - (0.06*2);
            }
        }
    }
    if(car3Move < -30)
    {
        car3Move = 27;
    }

    if(bAngle == 0)
    {
        car4Move = car4Move - car4Speed;
    }
    else
    {
        if(car4Move >= -20)
        {
            if(car4Move > -6.5)
            {
                if(car4Move > -6)
                {
                    car4Move = car4Move - car4Speed;
                }
            }
            else
            {
                car4Move = car4Move + (0.06*2);
            }
        }
        else
        {
            if(car4Move < -40)
            {
                car4Move = car4Move - car4Speed;
            }
            else
            {
                car4Move = car4Move - (0.06*2);
            }
        }
    }
    if(car4Move < -50)
    {
        car4Move = 27;
    }

    if(bAngle == 0)
    {
        car5Move = car5Move + car5Speed;
    }
    else
    {
        if(car5Move <= 20)
        {
            if(car5Move < 6.5)
            {
                if(car5Move < 6)
                {
                    car5Move = car5Move + car5Speed;
                }
            }
            else
            {
                car5Move = car5Move - (0.06*2);
            }
        }
        else
        {
            if(car5Move > 40)
            {
                car5Move = car5Move + car5Speed;
            }
            else
            {
                car5Move = car5Move + (0.06*2);
            }
        }
    }
    if(car5Move > 50)
    {
        car5Move = -27;
    }

    if(bAngle == 0)
    {
        car6Move = car6Move - car6Speed;
    }
    else
    {
        if(car6Move >= -25)
        {
            if(car6Move > -13.5)
            {
                if(car6Move > -13)
                {
                    car6Move = car6Move - car6Speed;
                }
            }
            else
            {
                car6Move = car6Move + (0.06*2);
            }
        }
        else
        {
            if(car6Move < -35)
            {
                car6Move = car6Move - car6Speed;
            }
            else
            {
                car6Move = car6Move - (0.06*2);
            }
        }
    }
    if(car6Move < -55)
    {
        car6Move = 27;
    }

    //cout<<car4Move<<endl;
    if(bAngle == 0)
    {
        car7Move = car7Move + car7Speed;
    }
    else
    {
        if(car7Move <= 25)
        {
            if(car7Move < 13.5)
            {
                if(car7Move < 13)
                {
                    car7Move = car7Move + car7Speed;
                }
            }
            else
            {
                car7Move = car7Move - (0.06*2);
            }
        }
        else
        {
            if(car7Move > 35)
            {
                car7Move = car7Move + car7Speed;
            }
            else
            {
                car7Move = car7Move + (0.06*2);
            }
        }
    }
    if(car7Move > 55)
    {
        car7Move = -27;
    }

    boat2Move = boat2Move+boat2Speed;
    if(boat2Move > 45)
    {
        boat2Move = -45;
    }

    boat3Move = boat3Move+boat3Speed;
    if(boat3Move > 50)
    {
        boat3Move = -50;
    }

    boat4Move = boat4Move+boat4Speed;
    if(boat4Move > 45)
    {
        boat4Move = -45;
    }

    boat5Move = boat5Move-boat5Speed;
    if(boat5Move < -45)
    {
        boat5Move = 45;
    }

    cloud1Move = cloud1Move+cloud1Speed;
    if(cloud1Move > 27)
    {
        cloud1Move = -27;
    }

    cloud2Move = cloud2Move+cloud2Speed;
    if(cloud2Move > 27)
    {
        cloud2Move = -27;
    }

    cloud3Move = cloud3Move+cloud3Speed;
    if(cloud3Move > 27)
    {
        cloud3Move = -27;
    }

    cloud4Move = cloud4Move+cloud4Speed;
    if(cloud1Move > 27)
    {
        cloud4Move = -27;
    }
    secMove -= 10;
    minMove -= 00.167;
    hourMove -= 00.00278;

    sunMove -=0.05;
    moonMove -=0.05;
    //cout<< sunMove<<endl;

    cnt ++;
    cout<< move1<<endl;
    if(cnt >= 1200)
    {
        cnt = 0;
        if(!isNight)
        {
            isNight = true;
            moonMove = -50;
        }
        else
        {
            isNight = false;
            sunMove = 15;
        }
    }

    //135, 223, 240
    if(sunMove >700)
    {
        move1+=0.1;

        if(move1>1 && move1<=2)
        {
            sr=135;
            sg=233;
            sb=240;
        }
        else if(move1>2 && move1<=3)
        {
            sr=125;
            sg=223;
            sb=230;
        }
        else if(move1>3 && move1<=4)
        {
            sr=115;
            sg=213;
            sb=220;
        }
        else if(move1>4 && move1<=5)
        {
            sr=105;
            sg=203;
            sb=210;
        }
        else if(move1>5 && move1<=6)
        {
            sr=95;
            sg=193;
            sb=200;
        }
        else if(move1>6 && move1<=7)
        {
            sr=85;
            sg=183;
            sb=190;
        }
        else if(move1>7 && move1<=8)
        {
            sr=75;
            sg=173;
            sb=180;
        }
        else if(move1>8 && move1<=9)
        {
            sr=65;
            sg=163;
            sb=170;
        }
        else if(move1>9 && move1<=10)
        {
            sr=55;
            sg=153;
            sb=160;
        }
    }
    else
    {
        sr=135;
        sg=223;
        sb=240;
    }

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

void handleKeyPress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        if(bAngle < 40)
        {
            bAngle += 0.5;
        }
        break;
    case 's':
        if(bAngle > 0)
        {
            bAngle -= 0.5;
        }
        break;

        glutPostRedisplay();
    }
}




int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1620, 1080);
    glutCreateWindow("London Bridge");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-27.0, 27.0, -18.0, 18.0);

    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyPress);
    glutTimerFunc(10, update, 0);
    glutMainLoop();

    return 0;
}
