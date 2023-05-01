#include "polyEnemies.h"
#include <iostream>

#define SCREEN_WIDTH 480

////////////////////////////////////////////////
///////////////// LEGATE CLASS /////////////////
////////////////////////////////////////////////

Legate::Legate()
{
    type = 1;
}

void Legate::display()
{
    // Represent them with a square
    glBegin(GL_QUADS);
    glColor3f(0.97f, 0.97f, 0.95f);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

int Legate::getType()
{
    return type;
}

Legate::~Legate()
{
}

////////////////////////////////////////////////
///////////////// PRAETOR CLASS ////////////////
////////////////////////////////////////////////

Praetor::Praetor()
{
    type = 2;
}

void Praetor::display()
{
    // Represent them with a square
    glBegin(GL_QUADS);
    glColor3f(0.13f, 0.34f, 0.48f);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

int Praetor::getType()
{
    return type;
}

Praetor::~Praetor()
{
}

////////////////////////////////////////////////
//////////////// IMPERATOR CLASS ///////////////
////////////////////////////////////////////////

Imperator::Imperator()
{
    type = 3;
}

void Imperator::display()
{
    // Represent them with a square
    glBegin(GL_QUADS);
    glColor3f(0.98f, 0.21f, 0.25f);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

int Imperator::getType()
{
    return type;
}

Imperator::~Imperator()
{
}