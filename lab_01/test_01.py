import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *
import sys


verticies = (
    (1, -1, -1),
    (1, 1, -1),
    (-1, 1, -1),
    (-1, -1, -1),
    (1, -1, 1),
    (1, 1, 1),
    (-1, -1, 1),
    (-1, 1, 1)
)

edges = (
    (0, 1),
    (0, 3),
    (0, 4),
    (2, 1),
    (2, 3),
    (2, 7),
    (6, 3),
    (6, 4),
    (6, 7),
    (5, 1),
    (5, 4),
    (5, 7)
)


def code_opengl():
    glBegin(GL_POINTS)

    glVertex3d(2, 3, -3)

    glEnd()


def main():
    pygame.init()
    display = (600, 600)
    screen = pygame.display.set_mode(display, DOUBLEBUF | OPENGL)

    glOrtho(-10, 10, -5, 5, -5, 5)
    gluPerspective(45, 40/30, 1.0, 50.0)

    # glTranslatef(0.0, 0.0, -5)

    glRotatef(0, 0, 0, 0)

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
                # pygame.quit()
                # quit()
                running = False

        # glRotatef(1, 3, 1, 1)
        glClear(GL_COLOR_BUFFER_BIT)
        code_opengl()
        pygame.display.flip()
        pygame.time.wait(10)


main()
