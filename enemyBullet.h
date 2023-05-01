#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include <iostream>

#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>

#include "enemy.h"
#include "player.h"

class enemyBullet
{
    public:
    float x;
    float y;

    float speed;
    bool shot;

    enemyBullet(float enemyX, float enemyY);
    void display();
    void automove();
    bool passBottom();
    bool collide(Player player);
    bool exist();
};

#endif