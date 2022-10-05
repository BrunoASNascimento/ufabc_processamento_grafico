/*
 * Meu Primeiro Programa: xxx.cpp
 * <NomeCompleto>, RA <RA>, data DD/MM/AAAA
 */

#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>
#include <unistd.h> // needed to sleep

/* ASCII code for the escape key. */
#define ESCAPE 27

/* The number of our GLUT window */
int window;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
    // Executa os comandos OpenGL
    glFlush();
}
// Inicializa parâmetros de rendering
void Inicializa(void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
// Programa Principal
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Meu Primeiro Programa");
    glutDisplayFunc(Desenha);
    Inicializa();
    glutMainLoop();
    return 0;
}

