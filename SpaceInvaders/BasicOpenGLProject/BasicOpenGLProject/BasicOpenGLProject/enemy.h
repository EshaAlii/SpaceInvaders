#ifndef ENEMY_H
#define ENEMY_H

#define GL_SILENCE_DEPRECATION

#include <GL/glut.h>

class Enemy
{
public:
    float x;
    float y;

    float width;
    float height;

    float speed;
    int dir; // 0 for left, 1 for right

    bool hit;

    bool visible;

    int type;

    Enemy();

    virtual void display();

    void automove();

    void attack();

    // Return the type of the enemy
    virtual int getType();

    ~Enemy();
};

#endif