#include "bullet.h"
#include "enemy.h"

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 480

Bullet::Bullet(float playerX, float playerY)
{
    // Make bullet's intial position above player's current
    x = playerX + 15.0f;
    y = playerY + 30.0f;

    // Make the bullet speed 10
    speed = 10.0f;

    // Make the bullet "shot out"
    shot = true;
}

// Function to display the bullet
void Bullet::display()
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

// Function to move the bullet across the screen once shot
void Bullet::automove()
{
    y = y + speed;
}

// Function to see if the bullet passes the top of the screen
bool Bullet::passTop()
{
    if (y > SCREEN_HEIGHT)
    {
        return y > SCREEN_HEIGHT;
    }
}

bool Bullet::collide(Enemy enemy)
{
    if ((x > enemy.x - 5.0f) && (x < enemy.x + enemy.width + 5.0f))
    {
        if ((y > enemy.y - 5.0f) && (y < enemy.y + enemy.height + 5.0f))
        {
            return true;
        }
    }
    return false;
}


bool Bullet::exist() {
    return shot && y <= SCREEN_HEIGHT;
}
