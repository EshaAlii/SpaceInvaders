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

    float cooldown;         // Time between shots (in seconds)

    float timeSinceLastShot;// Time elapsed since last shot (in seconds)

    bool canShoot;          // Whether the enemy can currently shoot

    Enemy();

    virtual void display();

    void automove();

    void attack();

    void setTimeSinceLastShot(float time);

    float getTimeSinceLastShot();

    void setCanShoot(bool value);

    bool getCanShoot() const;

    float getCooldown();

    // Return the type of the enemy
    virtual int getType();

    ~Enemy();
};


#endif
