#ifndef BULLET_H
#define BULLET_H

#include <iostream>

#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>

#include "enemy.h"

class Bullet
{
    public:

    // Bullet position
    float x;
    float y;

    // Spped of the bullet
    float speed;
    
    // Bool to check if the bullet is on screen
    bool shot;

    // Bullet constructor
    Bullet(float playerX, float playerY);

    // Function to display the bullet
    void display();

    // Function to move the bullet across the screen once shot
    void automove();
    
    // Function to see if the bullet passes the top of the screen
    bool passTop();

    // Function to see if the bullet collides with the enemy
    bool collide(Enemy enemy);

    bool exist();
};

#endif