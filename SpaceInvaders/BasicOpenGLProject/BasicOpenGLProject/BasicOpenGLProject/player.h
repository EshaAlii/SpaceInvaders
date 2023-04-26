#ifndef PLAYER_H
#define PLAYER_H

#include <GL/glut.h>

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

    // Constructor
    Player();

    // Display Function
    void display();

    // Function to move player left
    void playerLeft();

    // Function to move player right
    void playerRight();

    // Function to have the player shoot a bullet
    void playerShoot();


};

#endif