#include "enemy.h"
#include <iostream>

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 800

Enemy::Enemy()
{
    // x and y position of the enemy object(s)
    x = 50.0f;
    y = 700.0f;

    // dimensions of the enemy object(s)
    width = 20.0f;
    height = 20.0f;

    // speed at which enemies move
    speed = 7.0f;

    // determines direction enemies are moving in
    dir = 1;

    hit = false;

    visible = true;

    type = 0;

    cooldown = 600;

    timeSinceLastShot = 0;

    canShoot = true;
}

void Enemy::display()
{
    if (visible)
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
    
}

void Enemy::automove()
{
    // runs indefinitely without any sort of while/for loop because the loop is already in the main
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

int Enemy::getType()
{
    return type;
}

void Enemy::attack()
{
}

void Enemy::setTimeSinceLastShot(float time) { 
    timeSinceLastShot = time; 
}

float Enemy::getTimeSinceLastShot() { 
    return timeSinceLastShot; 
}

void Enemy::setCanShoot(bool value) { 
    value = getCanShoot();
}
bool Enemy::getCanShoot() const {
    return canShoot; 
}
float Enemy::getCooldown() { 
    return cooldown; 
}

Enemy::~Enemy()
{
}
