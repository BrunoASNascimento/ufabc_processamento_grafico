// A simple introductory program; its main window contains a static picture
// of a triangle, whose three vertices are red, green and blue.  The program
// illustrates viewing with default viewing parameters only.

#include <GL/glut.h> // Header File For The GLUT Library
#include <GL/gl.h>   // Header File For The OpenGL32 Library
#include <GL/glu.h>  // Header File For The GLu32 Library

// Clears the current window and draws a triangle.
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glVertex3f(2.0f, 2.0f, 3.0f);
  glVertex3f(2.0f, 4.0f, 3.0f);
  glVertex3f(6.0f, 2.0f, 0.0f);
  glVertex3f(6.0f, 4.0f, 0.0f);
  glEnd();

  // Flush drawing command buffer to make drawing happen as soon as possible.
  glFlush();
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// enters the main event loop.
int main(int argc, char **argv)
{

  // Use a single buffered window in RGB mode (as opposed to a double-buffered
  // window or color-index mode).
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Position window at (80,80)-(480,380) and give it a title.
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Task 03");

  gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  gluPerspective(30.0, 10.0 / 10.0, 1.0, 20.0);

  // Tell GLUT that whenever the main window needs to be repainted that it
  // should call the function display().
  glutDisplayFunc(display);

  // Tell GLUT to start reading and processing events.  This function
  // never returns; the program only exits when the user closes the main
  // window or kills the process.
  glutMainLoop();
}