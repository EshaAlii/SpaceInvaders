#include <GL/glut.h>

// Dimensions of the screen
const float SCREEN_WIDTH = 480.0f;
const float SCREEN_HEIGHT = 750.0f;

// Position + Size of player
float trianglePos[] = {SCREEN_WIDTH / 2.0f, 90.0f}; // position of the triangle (starts at the bottom)
float triangleSize[] = {30.0f, 30.0f}; // size of the triangle

// Display Function
void display()
{
    // Clear Screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Reset modelview matrix
    glLoadIdentity();

    // Draw our player
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(trianglePos[0], trianglePos[1]);
    glVertex2f(trianglePos[0] + triangleSize[0] / 2.0f, trianglePos[1] + triangleSize[1]);
    glVertex2f(trianglePos[0] + triangleSize[0], trianglePos[1]);
    glEnd();

    // Swap Buffers
    glutSwapBuffers();

}

// Keyboard Function
void keyboard(unsigned char key, int x, int y)
{
    // For each key on our keyboard
    switch (key)
    {
        // When the escape key is pressed
        case 27:
            // We exit the game
            exit(0);
            break;

        // When a is pressed we move the triangle to the left
        case 'a':
            if (trianglePos[0] > 0)
            {
                trianglePos[0] -= 15.0f;
            }
            break;

        // When d is pressed we move the triangle to the right
        case 'd':
            if (trianglePos[0] + triangleSize[0] < SCREEN_WIDTH)
            {
                trianglePos[0] += 15.0f;
            }
            break;
    }

    // Redraw the scene
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
    glutCreateWindow("OpenGL Example");

    // Set Display callback function
    glutDisplayFunc(display);

    // Set keyboard callback function
    glutKeyboardFunc(keyboard);

    // Switch to projection mode
    glMatrixMode(GL_PROJECTION);

    // Reset projection matrix
    glLoadIdentity();

    // Set projection matrix
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, -1, 1);

    // Switch back to modelview mode
    glMatrixMode(GL_MODELVIEW);

    // Enter main loop
    glutMainLoop();

    // End Program
    return 0;
}
