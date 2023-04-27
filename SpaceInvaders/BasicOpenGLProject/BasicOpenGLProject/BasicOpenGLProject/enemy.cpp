#include "enemy.h"
#include <iostream>

#define SCREEN_WIDTH 480

Enemy::Enemy()
{
    // x and y position of the enemy object(s)
    x = 0;
    y = 0;

    // dimensions of the enemy object(s)
    width = 20.0f;
    height = 20.0f;

    // speed at which enemies move
    speed = 1.5f;

    // determines direction enemies are moving in
    dir = 1;
}

void Enemy::display()
{
    // Represent them with a square
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void Enemy::automove()
{
    // runs indefinitely without any sort of loop because the loop is already in the main
    // if left of screen is reached
    if (dir == 1)
    {
        // Moving right
        x += speed;

        if (x + width >= SCREEN_WIDTH)
        {
            // when right of screen is hit, we change direction back to left
            dir = 0;
            y -= height;
        }
    }
    else
    {
        // Moving left
        x -= speed;

        if (x <= 0)
        {
            // If we hit the left side of the screen, change direction and move down
            dir = 1;
            y -= height;
        }
    }

    glutPostRedisplay();
}

void Enemy::attack()
{
}

Enemy::~Enemy()
{
}