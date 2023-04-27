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
    void playerLeft(unsigned char key);

    // Function to move player right
    void playerRight(unsigned char key);

    // Our "setter function" for our player's x position
    void setPlayer(float x);

    // Our "getter function" for our player's x position
    float getX() const{return x;}

    // Function to have the player shoot a bullet
    void playerShoot();

    // Destructor (for when player dies)
    ~Player();

};

#endif
