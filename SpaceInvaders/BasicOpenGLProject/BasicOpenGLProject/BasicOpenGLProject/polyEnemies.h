#ifndef POLYENEMIES_H
#define POLYENEMIES_H

#define GL_SILENCE_DEPRECATION

#include "enemy.h"

#include <GL/glut.h>

class Legate : public Enemy
{
public:
    Legate();

    void display();

    void automove();

    void attack();

    int getType();

    ~Legate();
};

class Praetor : public Enemy
{
public:
    Praetor();

    void display();

    void automove();

    void attack();

    int getType();

    ~Praetor();
};

class Imperator : public Enemy
{
public:
    Imperator();

    void display();

    void automove();

    void attack();

    int getType();

    ~Imperator();
};

#endif