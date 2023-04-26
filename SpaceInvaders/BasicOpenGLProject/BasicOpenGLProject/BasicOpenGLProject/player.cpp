#include "player.h"

Player::Player()
{
    // Set the width
    x = 2.0f;
    y = 90.0f;
    width = 30.0 f;
    height = 30.0 f;
}

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

void Player::playerLeft()
{
    if (x > 0)
    {
        
    }
}

void Player::playerRight()
{
    
}