#include <iostream>
#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <Windows.h>
#include <MMSystem.h>
#define PI 3.1416

using namespace std;

GLfloat position = 0.0;
GLfloat speed = 0.8;
GLfloat position1 = 0.0;
GLfloat position2 = 0.0;
GLfloat position4 = 0.0;
GLfloat position5 = 0.0;
GLfloat position6 = 0.0;
GLfloat speed1 = 0.4;
GLfloat speed2 = 0.3;
GLfloat speed3 = 0.8;
GLfloat speed9 = 1.2;
GLfloat _rain = 0.0;
GLfloat _night = 0.0;
GLfloat _morning = 0.0;

GLfloat bird_y = 14.0f;



GLfloat rainday = false;
GLfloat night = false;

GLfloat morning_rain = false;
GLfloat day_rain = false;




void train(int value)
{
    if(position > 10.0)
        position = -20.0;
        position += speed;
        glutPostRedisplay();
        glutTimerFunc(100, train, 1);
}
void cloud1(int value)
{
    if(position1 > 25.0)
        position1 = -20.0;
        position1 += speed1;
        glutPostRedisplay();
        glutTimerFunc(100, cloud1, 1);
}
void cloud2(int value){
    if(position2 > 32.0)
        position2 = -10.0;
        position2 += speed2;
        glutPostRedisplay();
        glutTimerFunc(100, cloud2, 1);
}


void caru(int value)
{
    if(position4 > 10)
        position4 = -30.0;
        position4 += speed3;
        glutPostRedisplay();
        glutTimerFunc(100, caru, 1);
}

void card(int value)
{
    if(position5 > 30)
        position5 = -20.0;
        position5 += speed3;
        glutPostRedisplay();
        glutTimerFunc(100, card, 1);
}

void bird2(int value) {
    if (position6 > 30) {
        position6 = -9.0;
    }
    position6 += speed9;
    glutPostRedisplay();
    glutTimerFunc(100, bird2, 1);

    // compute the current time
    float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;

    // update the bird's y position
    bird_y += 0.1f * sin(time);
}



void sun(bool sunny){

        ///Conditions for sun

        if(!night && !rainday){
            glPushMatrix();
            glTranslatef(7.0f, 15.0f, 0.0f);
            GLfloat radius = 2.0f;
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3f(1.0f, 0.8f, 0.2f);
            glVertex2f(0.0f, 0.0f);
            int num_segments = 100;
                for (int i = 0; i <= num_segments; i++) {
                    GLfloat theta = i * twicePi / num_segments;
                    GLfloat x = radius * cos(theta);
                    GLfloat y = radius * sin(theta);
                    glColor3f(1.0f, 0.8f - 0.6f * y / radius, 0.2f - 0.2f * y / radius);
                    glVertex2f(x, y);
                }
            glEnd();

            glPopMatrix();
        }
}


void moon(bool moony){

///Condition for moon

    if(night && !rainday){
        glPushMatrix();
        glTranslatef(7.0f, 15.0f, 0.0f);
        GLfloat radius = 2.0f;
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(220,220,220);
        glVertex2f(0.0f, 0.0f);
        int num_segments = 100;
        for (int i = 0; i <= num_segments; i++) {
            GLfloat theta = i * twicePi / num_segments;
            GLfloat x = radius * cos(theta);
            GLfloat y = radius * sin(theta);
            glVertex2f(x, y);
        }
        glEnd();

        glPopMatrix();
    }

}
//-------------preoti



//-------------asir
void wheel(int x, int y)
{
    float theta;
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.1, 0.0);
    for(int i=0; i<360; i++)
    {
        theta = i*PI/180;
        glVertex2f(x+0.02*6*cos(theta),y+0.02*6*sin(theta));
    }
    glEnd();
}

void myCars(float l, float r,float b, float t, int rr1, int gg1, int bb1, int rr2, int gg2, int bb2)
{

    float car_left = l;
    float car_right = r;
    float car_bottom = b;
    float car_top = t;

    glBegin(GL_POLYGON);
    glColor3ub(255, 239, 213);
    glVertex2f(car_left, car_bottom);
    glVertex2f(car_right, car_bottom);
    glVertex2f(car_right, car_top);
    glVertex2f(car_left, car_top);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0,0,139);
    glVertex2f(car_left + 0.15, car_top);
    glVertex2f(car_right - 0.15, car_top);
    glVertex2f(car_right - 0.25, car_top + 0.25);
    glVertex2f(car_left + 0.25, car_top + 0.25);
    glEnd();

    //wheels
    wheel(car_left+1.2, car_bottom);
    wheel(car_right-0.4, car_bottom);
}



/// Drawing Birds
void bird(float x, float y, bool bol, float time) {
    if(bol){

    glColor3f(0.0f, 0.0f, 0.0f);

    // compute the bird's y position based on a sine wave
    y = y - 2.5f * sin(time);

    // draw the body
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x+0.5, y+0.5);
    glVertex2f(x, y+0.20);
    glVertex2f(x-0.5, y+0.5);
    glEnd();
    }


}




/// Function Morning
void Morning(int _mor){

    glClearColor (0.77, 0.95, 1.00, 1.0);
    sun(true);

    if(!night && !rainday){
        glPushMatrix();
        glTranslatef(position6, 0.0f, 0.0f);
        bird(9.0, 14.0, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird(8.8, 15.3, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird(7.7, 15.9, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird(7.5, 14.0, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird(8.3, 15.6, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird(7.2, 15.2, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird(8.5, 14.2, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        glPopMatrix();
    }

}

//-------------asir


//-------------joyayriya
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);


    /// clouds

    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);

    float theta;

    //c1
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(10+1*cos(theta),15+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(12.5+1.2*cos(theta),16+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(11+1.5*cos(theta),16+1.5*sin(theta));
    }
    glEnd();

    //c
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(18+1*cos(theta),10+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(20.5+1.2*cos(theta),11+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(19+1.5*cos(theta),11+1.5*sin(theta));
    }
    glEnd();
    glPopMatrix();

    //c1c
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(-2+1*cos(theta),15+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(0.5+1.2*cos(theta),16+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(-1+1.5*cos(theta),16+1.5*sin(theta));
    }
    glEnd();

    //c
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(14+1*cos(theta),10+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(15.5+1.8*cos(theta),11+1.2*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(15+1.2*cos(theta),11+1.5*sin(theta));
    }
    glEnd();
    //c3
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(5+1*cos(theta),10+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(6+1*cos(theta),10+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(6.5+.6*cos(theta),11+.5*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(70, 130, 180);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(6+.7*cos(theta),11+.7*sin(theta));
    }
    glEnd();

    glPopMatrix();
    //-------------joyayriya


    //-------------joyayriya

    ///Buildings
	glBegin(GL_QUADS);

    glColor3f (0, 0, 0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 5.0, 0.0);
	glVertex3f(5.0, 5.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0);

    // Back buildings
    glColor3f(0.0f, 0.5f, 0.5f); //
	glVertex3f(5.0, 3.0, 0.0);
	glVertex3f(6.0, 3.0, 0.0);
	glVertex3f(6.0, 0.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(6.0, 0.0, 0.0);
	glVertex3f(6.0, 8.0, 0.0);
	glVertex3f(11.0, 8.0, 0.0);
    glVertex3f(11.0, 0.0, 0.0);

    // Back buildings
    glColor3f(0.0f, 0.5f, 0.5f); //
	glVertex3f(11.0, 0.0, 0.0);
	glVertex3f(11.0, 4.5, 0.0);
	glVertex3f(12.0, 4.5, 0.0);
    glVertex3f(12.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(12.0, 0.0, 0.0);
	glVertex3f(12.0, 6.0, 0.0);
	glVertex3f(16.0, 6.0, 0.0);
    glVertex3f(16.0, 0.0, 0.0);

    // Back buildings
    glColor3f(0.0f, 0.5f, 0.5f); //
	glVertex3f(16.0, 0.0, 0.0);
	glVertex3f(16.0, 3.5, 0.0);
	glVertex3f(17.0, 3.5, 0.0);
    glVertex3f(17.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(17.0, 0.0, 0.0);
	glVertex3f(17.0, 7.0, 0.0);
	glVertex3f(21.0, 7.0, 0.0);
    glVertex3f(21.0, 0.0, 0.0);

    // Back buildings
    glColor3f(0.0f, 0.5f, 0.5f); //
	glVertex3f(21.0, 0.0, 0.0);
	glVertex3f(21.0, 5.75, 0.0);
	glVertex3f(24.0, 5.75, 0.0);
    glVertex3f(24.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(22.0, 0.0, 0.0);
	glVertex3f(22.0, 5.0, 0.0);
	glVertex3f(26.0, 5.0, 0.0);
    glVertex3f(26.0, 0.0, 0.0);

    // Back buildings
    glColor3f(0.0f, 0.5f, 0.5f); //
	glVertex3f(26.0, 0.0, 0.0);
	glVertex3f(26.0, 3.25, 0.0);
	glVertex3f(27.0, 3.25, 0.0);
    glVertex3f(27.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(27.0, 0.0, 0.0);
	glVertex3f(27.0, 8.0, 0.0);
	glVertex3f(31.0, 8.0, 0.0);
    glVertex3f(31.0, 0.0, 0.0);

    // Back Building
    glColor3f(0.0f, 0.5f, 0.5f);
	glVertex3f(31.0, 0.0, 0.0);
	glVertex3f(31.0, 6, 0.0);
	glVertex3f(32.0, 6, 0.0);
    glVertex3f(32.0, 0.0, 0.0);


    // Metro Pillar
    glColor3f (0.329, 0.329, 0.329);
	glVertex3f(24.5, 5.0, 0.0);
	glVertex3f(24.5, 7.0, 0.0);
	glVertex3f(25.5, 7.0, 0.0);
    glVertex3f(25.5, 5.0, 0.0);

    glVertex3f(24, 7.0, 0.0);
	glVertex3f(24, 8.0, 0.0);
	glVertex3f(26, 8.0, 0.0);
    glVertex3f(26, 7.0, 0.0);

    glVertex3f(26, 7.0, 0.0);
	glVertex3f(26, 8.0, 0.0);
	glVertex3f(27, 9.0, 0.0);
    glVertex3f(28, 9.0, 0.0);

    glVertex3f(24, 7.0, 0.0);
	glVertex3f(24, 8.0, 0.0);
	glVertex3f(23, 9.0, 0.0);
    glVertex3f(22, 9.0, 0.0);

    glVertex3f(3.5, 5.0, 0.0);
	glVertex3f(3.5, 7.0, 0.0);
	glVertex3f(4.5, 7.0, 0.0);
    glVertex3f(4.5, 5.0, 0.0);

    glVertex3f(3, 7.0, 0.0);
	glVertex3f(3, 8.0, 0.0);
	glVertex3f(5, 8.0, 0.0);
    glVertex3f(5, 7.0, 0.0);

    glVertex3f(5, 7.0, 0.0);
	glVertex3f(5, 8.0, 0.0);
	glVertex3f(6, 9.0, 0.0);
    glVertex3f(7, 9.0, 0.0);

    glVertex3f(3, 7.0, 0.0);
	glVertex3f(3, 8.0, 0.0);
	glVertex3f(2, 9.0, 0.0);
    glVertex3f(1, 9.0, 0.0);

    glVertex3f(0, 9.0, 0.0);
	glVertex3f(0, 9.25, 0.0);
	glVertex3f(32, 9.25, 0.0);
    glVertex3f(32, 9.0, 0.0);

    glVertex3f(0, 11.75, 0.0);
	glVertex3f(0, 11.85, 0.0);
	glVertex3f(32, 11.85, 0.0);
    glVertex3f(32, 11.75, 0.0);



    glEnd();
    // buildings end

    //-------------joyayriya


    //-------------syed

    /// Metro Rail
    glPushMatrix();
    glTranslatef(-position,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(11.5, 9.25, 0.0);
	glVertex3f(20, 9.25, 0.0);
	glVertex3f(20, 11, 0.0);
    glVertex3f(11.75, 11, 0.0);

    glColor3f (1, 0, 0);
	glVertex3f(14, 9.25, 0.0);
	glVertex3f(16, 9.25, 0.0);
	glVertex3f(16, 11, 0.0);
    glVertex3f(14.75, 11, 0.0);

    glVertex3f(11.5, 9.25, 0.0);
	glVertex3f(11, 9.5, 0.0);
	glVertex3f(11,10.25 , 0.0);
    glVertex3f(11.75, 11, 0.0);

    glVertex3f(20, 9.25, 0.0);
	glVertex3f(20.25, 9.5, 0.0);
	glVertex3f(20.25,10.75 , 0.0);
    glVertex3f(20, 11, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(11.25, 9.5, 0.0);
	glVertex3f(12.75, 9.5, 0.0);
	glVertex3f(12.75, 9.75, 0.0);
    glVertex3f(11.25, 9.75, 0.0);

    glVertex3f(11.25, 10, 0.0);
	glVertex3f(11.75, 10, 0.0);
	glVertex3f(11.75, 10.75, 0.0);
    glVertex3f(11.25, 10.25, 0.0);

    glVertex3f(12, 10, 0.0);
	glVertex3f(12.75, 10, 0.0);
	glVertex3f(12.75, 10.75, 0.0);
    glVertex3f(12, 10.75, 0.0);

    glVertex3f(13, 9.25, 0.0);
	glVertex3f(13.5, 9.25, 0.0);
	glVertex3f(13.5, 10.5, 0.0);
    glVertex3f(13, 10.5, 0.0);

    glVertex3f(13.75, 9.75, 0.0);
	glVertex3f(14, 9.75, 0.0);
	glVertex3f(14, 10.75, 0.0);
    glVertex3f(13.75, 10.75, 0.0);

    glVertex3f(14.25, 9.75, 0.0);
	glVertex3f(14.5, 9.75, 0.0);
	glVertex3f(14.5, 10.75, 0.0);
    glVertex3f(14.25, 10.75, 0.0);

    glVertex3f(14.75, 9.25, 0.0);
	glVertex3f(15.25, 9.25, 0.0);
	glVertex3f(15.25, 10.5, 0.0);
    glVertex3f(14.75, 10.5, 0.0);

    glVertex3f(15.5, 9.75, 0.0);
	glVertex3f(15.75, 9.75, 0.0);
	glVertex3f(15.75, 10.75, 0.0);
    glVertex3f(15.5, 10.75, 0.0);

    glVertex3f(16, 9.75, 0.0);
	glVertex3f(16.25, 9.75, 0.0);
	glVertex3f(16.25, 10.75, 0.0);
    glVertex3f(16, 10.75, 0.0);

    glVertex3f(16.5, 9.25, 0.0);
	glVertex3f(17, 9.25, 0.0);
	glVertex3f(17, 10.5, 0.0);
    glVertex3f(16.5, 10.5, 0.0);

    glVertex3f(17.25, 9.75, 0.0);
	glVertex3f(17.5, 9.75, 0.0);
	glVertex3f(17.5, 10.75, 0.0);
    glVertex3f(17.25, 10.75, 0.0);

    glVertex3f(17.75, 9.75, 0.0);
	glVertex3f(18, 9.75, 0.0);
	glVertex3f(18, 10.75, 0.0);
    glVertex3f(17.75, 10.75, 0.0);

    glVertex3f(18.25, 9.25, 0.0);
	glVertex3f(18.75, 9.25, 0.0);
	glVertex3f(18.75, 10.5, 0.0);
    glVertex3f(18.25, 10.5, 0.0);

    glVertex3f(19, 9.75, 0.0);
	glVertex3f(19.25, 9.75, 0.0);
	glVertex3f(19.25, 10.75, 0.0);
    glVertex3f(19, 10.75, 0.0);

    glVertex3f(19.5, 9.5, 0.0);
	glVertex3f(19.75, 9.5, 0.0);
	glVertex3f(19.75, 10.75, 0.0);
    glVertex3f(19.5, 10.75, 0.0);

    glVertex3f(19.75, 9.5, 0.0);
	glVertex3f(20, 9.5, 0.0);
	glVertex3f(20, 10.5, 0.0);
    glVertex3f(19.75, 10.75, 0.0);

    glEnd();


	/// Metro Rail border
	glBegin(GL_LINES);
    glColor3f (0, 0, 0);
    glVertex3f(11.5, 9.25, 0.0);
	glVertex3f(11, 9.5, 0.0);

	glVertex3f(11, 9.5, 0.0);
	glVertex3f(11,10.25 , 0.0);

	glVertex3f(11,10.25 , 0.0);
    glVertex3f(11.75, 11, 0.0);

    glVertex3f(11.75, 11, 0.0);
    glVertex3f(20, 11, 0.0);

    glVertex3f(20, 9.25, 0.0);
	glVertex3f(20.25, 9.5, 0.0);

	glVertex3f(20.25, 9.5, 0.0);
	glVertex3f(20.25,10.75 , 0.0);

	glVertex3f(20.25,10.75 , 0.0);
    glVertex3f(20, 11, 0.0);

    glVertex3f(14.25,11 , 0.0);
    glVertex3f(15, 11.25, 0.0);

    glVertex3f(14.5, 11.25 , 0.0);
    glVertex3f(16.75,11.25, 0.0);

    glVertex3f(14.5,11.25 , 0.0);
    glVertex3f(14.25, 11.5, 0.0);

    glVertex3f(14.25,11.5 , 0.0);
    glVertex3f(14.25, 11.75, 0.0);

    glVertex3f(15.5,11 , 0.0);
    glVertex3f(15.75, 11.25, 0.0);

    glVertex3f(15.5,11 , 0.0);
    glVertex3f(15.5, 11.25, 0.0);

    glVertex3f(15.75,11 , 0.0);
    glVertex3f(15.75, 11.25, 0.0);

    glVertex3f(16.25,11.25 , 0.0);
    glVertex3f(17, 11, 0.0);

    glVertex3f(16.75,11.25 , 0.0);
    glVertex3f(17, 11.5, 0.0);

    glVertex3f(17,11.5 , 0.0);
    glVertex3f(17, 11.75, 0.0);

	glEnd();
	glPopMatrix();
	//-------------syed



    //-------------asir

    /// Metro Rail Railing
    glColor4f(0.41, 0.91, 1.00, 0.7);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 9.2);
    glVertex2f(32.0, 9.2);
    glVertex2f(32.0, 10.5);
    glVertex2f(0.0, 10.5);
    glEnd();
    glColor4f(0.35, 0.18, 0.13, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(32.0, 10.5);
    glVertex2f(0.0, 10.5);
    glVertex2f(0.0, 10.6);
    glVertex2f(32.0, 10.6);
    glEnd();


	/// Road
	glBegin(GL_QUADS);
    glColor3f (0.29, 0.29, 0.29);
	glVertex2f(0.0, 0.0);
	glVertex2f(32.0, 0.0);
	glVertex2f(32.0, 1.8);
	glVertex2f(0.0, 1.8);
	glEnd();
	/// Road divider lines
    glBegin(GL_LINES);
    glColor3f(1.0, 0.93, 0.0);
    for (int i = 1; i < 32; i+=2) {
        glVertex2f(i, 0.9);
        glVertex2f(i+1, 0.9);
    }
    glEnd();

    /// Footpath
    glBegin(GL_QUADS);
    glColor3f (0.48, 0.34, 0.26);
    glVertex2f(0.0, 1.8);
    glVertex2f(32.0, 1.8);
    glVertex2f(32.0, 2.2);
    glVertex2f(0.0, 2.2);
    glEnd();


    /// Cars

    glPushMatrix();
    glTranslatef(-position4, 0.0f, 0.0f);

    myCars(4.8, 6.3, 1.0, 1.3, 13, 93, 88, 0, 111, 248);
    myCars(8.8, 10.3, 1.0, 1.3, 93, 13, 40, 55, 139, 90);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(position5, 0.0f, 0.0f);

    myCars(2.8, 4.6, 0.05, 0.3, 13, 93, 88, 0, 111, 248);
    myCars(6.8, 8.6, 0.05, 0.3, 93, 13, 40, 55, 139, 90);

    glPopMatrix();
    ///------------------------------------///

    //-------------asir


    /// Birds

    Morning(_morning);


glFlush ();
}




//-------------joyayriya
/// Function Night
void Night(int _nt){
if(night){

    moon(true);

    glClearColor(0.00, 0.11, 0.36, 1.0);
    glutTimerFunc(8, Night, 0);
    glFlush();
}
}

//-------------syed
/// Function for Rainy weather
void Rain(int rainy){

if(rainday){

    sun(false);

    _rain += 0.001f;



    glBegin(GL_POINTS);
    for(int i=1;i<=70;i++)
    {
        if(day_rain == true){
            glClearColor (0.259, 0.569, 0.8, 0.82);
        }

        if(morning_rain == true ){
            glClearColor (0.839, 0.596, 0.42, 0.82);
        }

        int x=rand(),y=rand();
        x%=32; y%=18;
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glVertex2d(x,y);
        glVertex2d(x+.25,y+.55);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();
}
}





//-------------joyayriya


void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
        case 's':
        speed = 0.0f;
        break;

        case 'a':
        speed += 0.1f;
        break;

        case 'r':
        rainday = true;
        Rain(_rain);
        break;

        case 't':
        rainday = false;
        Rain(false);
        break;

        case 'n':
        day_rain=false;
        morning_rain=false;
        night = true;
        Night(_night);
        break;

        case 'd':
        day_rain = true;
        morning_rain= false;
        night = false;
        sun(true);
        glClearColor (0.77, 0.95, 1.00, 1.0);
        break;


	}
}
//-------------joyayriya




//-------------preoti
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed3 += 1.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}
if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed3 -= 0.3f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}
//-------------preoti


void init (void)
{
    glClearColor (0.77, 0.95, 1.00, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 32.0, 0.0, 18.0, -10.0, 10.0);

}

int main(int argc, char** argv)
{

    //-------------preoti

    cout << endl << "----------DHAKA METRO RAIL----------" << endl << endl;

    cout << "Press S : To Stop the Train" << endl << endl;
    cout << "Press A : To Speed-up the Train" << endl << endl;

    cout << "Press R : For Rain " << endl << endl;
    cout << "Press T : For Stopping Rain" << endl << endl;

    cout << "Press N : For Night " << endl << endl;
    cout << "Press D : For Day" << endl << endl;




    cout << "Press LEFT Button on Mouse : For Increase Car Speed" << endl << endl;
    cout << "Press RIGHT Button on Mouse : For Decrease Car Speed" << endl << endl;

//-------------preoti


    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 720);
    glutInitWindowPosition (600, 100);
    glutCreateWindow ("Mass rapid transit system Dhaka Metro Rail");

    // Enable alpha blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    init ();
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(100, train, 0);
    glutTimerFunc(100, cloud1, 0);
    glutTimerFunc(100, cloud2, 0);
    glutTimerFunc(100, caru, 0);
    glutTimerFunc(100, card, 0);
    glutTimerFunc(100, bird2, 0);

    glutMainLoop();
    return 0;
}

