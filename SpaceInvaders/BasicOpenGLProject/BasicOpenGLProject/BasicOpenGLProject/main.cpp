#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>
#include "player.h"
#include "enemy.h"
#include "swarm.h"
#include "bullet.h"
#include "enemyBullet.h"
#include <vector>

// Dimensions of the screen
#define SCREEN_WIDTH 480
const float SCREEN_HEIGHT = 750.0f;

// Create our player
Player player;

// Enemy enemy1;
Swarm swarm(player);

// Display Function
void display()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT);

	// Load Identity Matrix
	glLoadIdentity();

	// Draw our player
	player.display();

	player.displayLife();

	// Draw our player
	// enemy1.display();

	swarm.display();
	// swarm.attack(1);

	player.displayScore();

	// update and display all active bullets
	for (int i = 0; i < player.bullets.size(); i++)
	{
		// move the bullet
		player.bullets[i].automove();

		// display the bullet
		player.bullets[i].display();
	}

	for (int i = 0; i < swarm.ebullets.size(); i++)
	{
		// move the bullet
		swarm.ebullets[i].automove();

		// display the bullet
		swarm.ebullets[i].display();
	}

	// Swap Buffers
	glutSwapBuffers();
}

void playerKeyboard(unsigned char key, int x, int y)
{
    player.playerLeft(key);
    player.playerRight(key);
    player.playerShoot(key);
    if (player.lives == 0)
    {
        player.revive(key);
    }
    glutPostRedisplay();
}

void timer(int value)
{
    // enemy1.automove();
    // swarm.attack();
    swarm.automove();
    swarm.destroy(player.bullets);
    swarm.reachesPlayer();
    if (swarm.cleared == 45)
    {
        swarm.reposition();
    }
	// swarm.collision(player);
    swarm.attack(1);
    glutTimerFunc(50, timer, 0);
}

int main(int argc, char **argv)
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

	// Add this line to main function to update enemy1 position
	glutTimerFunc(50, timer, 0);

	// Enter main loop
	glutMainLoop();

	// End Program
	return 0;
}

