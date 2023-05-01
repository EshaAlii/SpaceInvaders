#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#define GL_SILENCE_DEPRECATION
#include <GL/glut.h>

#include "bullet.h"
#include <vector>

using namespace std;

// Create our Player
class Player
{
public:
    // Player Positions
    float x;
    float y;

    // Player Dimensions
    float width;
    float height;

    // Player lives
    int lives;

    // Position for the lives
    float lifex;
    float lifey;

    // Lives Dimensions
    float lifewidth;
    float lifeheight;

    // Position for the score
    float scorex;
    float scorey;

    int score;

    int mag;

    bool reviveCheck;

    // Create a vector of bullets
    vector<Bullet> bullets;

    // Constructor
    Player();

    // Display Function
    void display();

    // Display Function for player's life
    void displayLife();

    // Display Function for player's score
    void displayScore();

    // Function to move player left
    void playerLeft(unsigned char key);

    // Function to move player right
    void playerRight(unsigned char key);

    // Our "setter function" for our player's x position
    void setPlayer(float x);

    // Our "getter function" for our player's x position
    float getX() const { return x; }

    // Function to have the player shoot a bullet
    void playerShoot(unsigned char key);

    void revive(unsigned char key);

    // Destructor (for when player dies)
    ~Player();
};

#endif
