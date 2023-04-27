#ifndef ENEMY_H
#define ENEMY_H

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

class Enemy
{
public:
    // x and y position of the enemy object(s)

    float x;
    float y;

    // dimensions of the enemy object(s)

    float width;
    float height;

    // speed at which enemies move

    float speed;

    // determines direction enemies are moving in

    int dir;

    Enemy();

    void display();

    void automove();

    void attack();

    ~Enemy();
};

#endif