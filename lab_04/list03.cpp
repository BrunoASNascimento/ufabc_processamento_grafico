#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
}

void triangle(void)
{
    // glBegin(GL_POLYGON);
    // glColor3f (1.0, 1.0, 1.0);
    // glVertex3f (0.0, 0.0,0.0);
    // glVertex3f (0.0, 0.0,-4.0);
    // glVertex3f (0.0, 5.0,-4.0);
    // glVertex3f(0.0, 5.0,0.0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(2.0, 4.0, -1.0);
    glVertex3f(-1.0, 3.0, 3.0);
    glVertex3f(3.0, 1.0, 1.0);
    glEnd();
    glRotatef(45.0, 1.0, 0.0, 0.0);
    glScalef(1.5, 2.0, 2.0);
    glTranslatef(-1.0, -2.0, -1.5);
    // glRotatef(-90.0, 0.0, 1.0, 0.0);
}

void lineZ(void)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0f, 0.0f, -10.0f);
    glVertex3f(0.0f, 0.0f, 10.0f);
    glEnd();
};

void lineY(void)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0f, -10.0f, 0.0f);
    glVertex3f(0.0f, 10.0f, 0.0f);
    glEnd();
};

void lineX(void)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-20.0f, 0.0f, 0.0f);
    glVertex3f(20.0f, 0.0f, 0.0f);
    glEnd();
};

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    lineZ();
    lineY();
    lineX();
    triangle();
    
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("glTranslatef(-1.0, -2.0, -1.5);");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
