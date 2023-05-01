#include "enemyBullet.h"
#include "enemy.h"

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 480


enemyBullet::enemyBullet(float enemyX, float enemyY)
{
    //Make bullet's initial position below enemy's current
    x = enemyX - 15.0f;
    y = enemyY - 30.0f;

    //Make the bullet speed 10
    speed = 10.0f;

    //Make the bullet "shot out"
    shot = true;

}

// Function to display the bullet
void enemyBullet::display()
{
    // Display the bullet
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(x, y);
	glVertex2f(x + 3.0f, y);
	glVertex2f(x + 3.0f, y + 10.0f);
	glVertex2f(x, y + 10.0f);
	glEnd();
}

// Function to move the enemy bullet across the screen once shot
void enemyBullet::automove() {
    y = y - speed;
}

// Function to see if the bullet passes the bottom of the screen
bool enemyBullet::passBottom() {
    if (y < 0) {
        return y < 0;
    }
}

bool enemyBullet::exist(){
    return shot && y >= 0;
}

bool enemyBullet::collide(Player player)
{
    if ((x > player.x - 5.0f) && (x < player.x + player.width + 5.0f))
    {
        if ((y > player.y - 5.0f) && (y < player.y + player.height + 5.0f))
        {
            return true;
        }
    }
    return false;
}

