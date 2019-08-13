#include "Playground.h"

void Playground::drawField()
{
    glPushMatrix();
        glTranslatef(0, -200.0, 0);
        glRotatef(-70, 1, 0, 0);
        drawGrass();
        drawLines();
        drawGoals();
    glPopMatrix();
}

void Playground::drawGrass() 
{
    const float xCor = 800.0, yCor = 350.0, zCor = 0;
    glPushMatrix();
        glColor3f(0, 1, 0);
        glBegin(GL_POLYGON);
            glVertex3f(-xCor, -yCor, zCor);
            glVertex3f(xCor, -yCor, zCor);
            glVertex3f(xCor, yCor, zCor);
            glVertex3f(-xCor, yCor, zCor);
        glEnd();
    glPopMatrix();
}

void Playground::drawLines() 
{
    const float xCor = 600.0, yCor = 260.0, zCor = 0.5;
    const float xCor16 = 400.0, yCor16 = 190.0;
    glPushMatrix();
        glColor3f(1, 1, 1);
        glLineWidth(8);

        glBegin(GL_LINES);
        //lines of the end of the pitch
            glVertex3f(-xCor, -yCor, zCor);
            glVertex3f(xCor, -yCor, zCor);

            glVertex3f(xCor, -yCor, zCor);
            glVertex3f(xCor, yCor, zCor);

            glVertex3f(xCor, yCor, zCor);
            glVertex3f(-xCor, yCor, zCor);

            glVertex3f(-xCor, yCor, zCor);
            glVertex3f(-xCor, -yCor, zCor);
        //center line 
            glVertex3f(0, yCor, zCor);
            glVertex3f(0, -yCor, zCor);
        //"16m" lines left side
            glVertex3f(-xCor, -yCor16, zCor);
            glVertex3f(-xCor16, -yCor16, zCor);

            glVertex3f(-xCor16, -yCor16, zCor);
            glVertex3f(-xCor16, yCor16, zCor);

            glVertex3f(-xCor16, yCor16, zCor);
            glVertex3f(-xCor, yCor16, zCor);
        //"16m" lines right side
            glVertex3f(xCor, -yCor16, zCor);
            glVertex3f(xCor16, -yCor16, zCor);

            glVertex3f(xCor16, -yCor16, zCor);
            glVertex3f(xCor16, yCor16, zCor);

            glVertex3f(xCor16, yCor16, zCor);
            glVertex3f(xCor, yCor16, zCor);
        glEnd();

        //center circle
        float r = 100.0, cx = 0, cy = 0;
        float theta, xHelp, yHelp;
        glBegin(GL_LINE_LOOP);
        for (int ii = 0; ii < 100; ii++) {
            theta = 2.0f * 3.1415926f * float(ii) / float(100);
            xHelp = r * cosf(theta);
            yHelp = r * sinf(theta);
            glVertex3f(xHelp + cx, yHelp + cy, zCor);
        }
        glEnd();
        //left "16m" circle
        glPushMatrix();
        glTranslatef(-xCor16, 0, 0);
        glRotatef(-90, 0, 0, 1);
        r = 100.0, cx = 0, cy = 0;
        glBegin(GL_LINE_LOOP);
        for (int ii = 0; ii < 100; ii++) {
            theta = 2.0f * (3.1415926f/2) * float(ii) / float(100);
            xHelp = r * cosf(theta);
            yHelp = r * sinf(theta);
            glVertex3f(xHelp + cx, yHelp + cy, zCor);
        }
        glEnd();
        glPopMatrix();
        //right "16m" circle
        glPushMatrix();
        glTranslatef(xCor16, 0, 0);
        glRotatef(90, 0, 0, 1);
        r = 100.0, cx = 0, cy = 0;
        glBegin(GL_LINE_LOOP);
        for (int ii = 0; ii < 100; ii++) {
            theta = 2.0f * (3.1415926f / 2) * float(ii) / float(100);
            xHelp = r * cosf(theta);
            yHelp = r * sinf(theta);
            glVertex3f(xHelp + cx, yHelp + cy, zCor);
        }
        glEnd();
        glPopMatrix();

    glPopMatrix();
}

void Playground::drawGoals() 
{
    float cylinderWidth = 8;
    //left goal
    glPushMatrix();

    glTranslatef(-600, 0, 0);
        glPushMatrix();
        glRotatef(90, 0, 0, 1);
        glPushMatrix();
            glTranslatef(-100, 0, 0);
            glColor3f(1, 1, 1);
            GLUquadric* quad = gluNewQuadric();
            gluCylinder(quad, cylinderWidth, cylinderWidth, 300, 50, 50);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(100, 0, 0);
            glColor3f(1, 1, 1);
            quad = gluNewQuadric();
            gluCylinder(quad, cylinderWidth, cylinderWidth, 300, 50, 50);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-100, 0, 300);
            glRotatef(90, 0, 1, 0);
            glColor3f(1, 1, 1);
            quad = gluNewQuadric();
            gluCylinder(quad, cylinderWidth, cylinderWidth, 200, 50, 50);
        glPopMatrix();
        glPopMatrix();

    glPopMatrix();

    //right goal
    glPushMatrix();

    glTranslatef(600, 0, 0);
    glPushMatrix();
        glRotatef(90, 0, 0, 1);
        glPushMatrix();
            glTranslatef(-100, 0, 0);
            glColor3f(1, 1, 1);
            //GLUquadric* quad = gluNewQuadric();
            gluCylinder(quad, cylinderWidth, cylinderWidth, 300, 50, 50);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(100, 0, 0);
            glColor3f(1, 1, 1);
            quad = gluNewQuadric();
            gluCylinder(quad, cylinderWidth, cylinderWidth, 300, 50, 50);
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-100, 0, 300);
            glRotatef(90, 0, 1, 0);
            glColor3f(1, 1, 1);
            quad = gluNewQuadric();
            gluCylinder(quad, cylinderWidth, cylinderWidth, 200, 50, 50);
        glPopMatrix();
    glPopMatrix();

    glPopMatrix();
}