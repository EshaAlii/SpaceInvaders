#include </Users/eshkebab/Desktop/SpaceInvaders/BasicOpenGLProject/freeglut/include/GL/glut.h> // for GLUT functions and types
#include </Users/eshkebab/Desktop/SpaceInvaders/BasicOpenGLProject/freeglut/include/GL/freeglut_ext.h>
#include </Users/eshkebab/Desktop/SpaceInvaders/BasicOpenGLProject/freeglut/include/GL/freeglut.h>
#include </Users/eshkebab/Desktop/SpaceInvaders/BasicOpenGLProject/freeglut/include/GL/freeglut_std.h>
// #include <freeglut/GL/gl.h>   // for OpenGL functions and types
#include <iostream>

using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set up a basic 2D view
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw a square
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(100, 100);
    glVertex2i(200, 100);
    glVertex2i(200, 200);
    glVertex2i(100, 200);
    glEnd();

    glutSwapBuffers(); // double-buffering
}


int main( int argc, char** argv )
{
    glutInit( &argc, argv );
    glutInitWindowPosition( 100, 100 );
    glutInitWindowSize( 800, 600 );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    glutCreateWindow( "Basic OpenGL Project" );
    glutDisplayFunc( display );
    glutMainLoop();
    return EXIT_SUCCESS;
}