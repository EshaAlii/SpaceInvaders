#include "player.h"
#include <string>
// #include "stb_image.h"

#define STB_IMAGE_IMPLEMENTATION
#define SCREEN_WIDTH 480

// Default constructor
Player::Player()
{
    // Set the Player's positions
    x = 240.0f;
    y = 90.0f;

    // Set the dimensions of how the player shows up
    width = 30.0f;
    height = 30.0f;

    // Give our player three lives
    lives = 3;

    score = 0;

    mag = 2;

    reviveCheck = false;
}

// Function to display the player
void Player::display()
{
    // Represent them with a triangle
    if (lives != 0)
    {
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(x, y);
        glVertex2f(x + width / 2.0f, y + height);
        glVertex2f(x + width, y);
        glEnd();
    }
}

// Function to display the life of the player
void Player::displayLife()
{
    // Set the position of the lives
    lifey = 20.0f;
    lifex = 20.0f;

    // Set the width and height of the lives
    lifewidth = 15.0f;
    lifeheight = 15.0f;

    // For each life available
    for (int i = 0; i < lives; i++)
    {
        // Represent them with a triangle
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(lifex, lifey);
        glVertex2f(lifex + lifewidth / 2.0f, lifey + lifeheight);
        glVertex2f(lifex + lifewidth, lifey);
        glEnd();

        // Additional spacing between each life
        lifex = lifex + lifewidth + 15;
    }
}

// Function to display the score of the player
void Player::displayScore()
{
    // Set the position of the score
    scorex = 375.0f;
    scorey = 20.0f;

    // Set the color of the score
    glColor3f(1.0f, 1.0f, 1.0f);

    // Set the font of the score
    void *font = GLUT_BITMAP_HELVETICA_18;

    // Convert the score to a string
    string scoreStr = "Score: " + to_string(score);

    // Loop through each character in the score string and display it
    for (int i = 0; i < scoreStr.length(); i++)
    {
        glRasterPos2f(scorex, scorey);

        glutBitmapCharacter(font, scoreStr[i]);

        // Move the position of the score to the right for the next character
        scorex = scorex + glutBitmapWidth(font, scoreStr[i]);
    }
}

// Function to move the player to the left of the screen
void Player::playerLeft(unsigned char key)
{
    // If the user presses the a key
    if (key == 'a')
    {
        // And if their current position is greater than the left edge of the screen
        if (x > 1)
        {

            // The player will move left
            x = x - 15.0f;
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
            x = x + 15.0f;
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
void Player::playerShoot(unsigned char key)
{

    if (bullets.size() < mag)
    {
        if (key == ' ')
        {
            // Player shoots a bullet
            bullets.push_back(Bullet(x, y));
        }
    }
}

void Player::revive(unsigned char key)
{
    if (key == 'r')
    {
        lives = 3;
        score = 0;
        mag = 2;
        reviveCheck = true;
    }
    glutPostRedisplay();
}

// Destructor of Player
Player::~Player()
{
    // Implement player death + 3 lives of player here (if player get's hit thrice, they die)
}
