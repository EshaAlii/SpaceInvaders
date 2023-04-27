#include <GL/glut.h>
#include "player.h"

#define GL_SILENCE_DEPRECATION

// Dimensions of the screen
const float SCREEN_WIDTH = 480.0f;
const float SCREEN_HEIGHT = 750.0f;

// Create our player
Player player;

// Display Function
void display()
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Load Identity Matrix
    glLoadIdentity();

    // Draw our player
    player.display();

    // Swap Buffers
    glutSwapBuffers();

}

// Keyboard Function for Player
void playerKeyboard(unsigned char key, int x, int y)
{
    player.playerLeft(key);
    player.playerRight(key);
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    // Intialize glut
    glutInit(&argc, argv);

    // Enable double buffering + set color format
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Set Window Size
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    // Create window
    glutCreateWindow("SpaceInvaders");

    // Set Display callback function
    glutDisplayFunc(display);

    // Switch to projection mode
    glMatrixMode(GL_PROJECTION);

    // Reset projection matrix
    glLoadIdentity();

    // Set projection matrix
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -1, 1);

    // Switch back to modelview mode
    glMatrixMode(GL_MODELVIEW);

    // Set keyboard callback function
    glutKeyboardFunc(playerKeyboard);

    // Enter main loop
    glutMainLoop();

    // End Program
    return 0;
}

