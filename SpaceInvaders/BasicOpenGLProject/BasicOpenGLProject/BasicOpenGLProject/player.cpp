#include "player.h"

#define SCREEN_WIDTH 480

// Default constructor
Player::Player()
{
    // Set the Player's position
    x = 240.0f;
    y = 90.0f;

    // Set the dimensions of how the player shows up
    width = 30.0f;
    height = 30.0f;
}

// Display function to have the player show up
void Player::display()
{
    // Represent them with a triangle
    glBegin(GL_TRIANGLES);
     glColor3f(1.0f, 0.0f, 0.0f);
     glVertex2f(x,y);
     glVertex2f(x + width / 2.0f, y + height);
     glVertex2f(x + width, y);
    glEnd();
}

// Function to move the player to the left of the screen
void Player::playerLeft(unsigned char key)
{
    // If the user presses the a key
    if (key == 'a')
    {
        // And if their current position is greater than the left edge of the screen
        if (x > 1){

            // The player will move left
            x -= 15.0f;
        }
    }

    // Redisplay player
    glutPostRedisplay();
}

// Function to move the player to the right of the screen
void Player::playerRight(unsigned char key)
{
    // If the user presses the d key
    if (key == 'd')
    {
        // And if the width of the player along with their current x position doesn't exceed the Screen Width
        if (x + width + 1 < SCREEN_WIDTH)
        {
            // The player will move right
            x += 15.0f;
        }
    }
    // Redisplay Player
    glutPostRedisplay();
}

// Our "setter function" for our player's x position
void Player::setPlayer(float x)
{
    // Point to current instance of their x position
   this->x = x;
}

// Function to have the player shoot a bullet
void Player::playerShoot()
{
    // Implement code
}

// Destructor of Player
Player::~Player()
{
    // Implement player death + 3 lives of player here (if player get's hit thrice, they die)
}

