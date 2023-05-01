#ifndef SWARM_H
#define SWARM_H

#include "enemy.h"
#include "polyEnemies.h"
#include "player.h"
#include "enemyBullet.h"

class Swarm
{
public:
    // Number of rows for enemies
    const static int enemyArr = 5;
    

    // Number of enemies in each row
    const static int enemyCol = 9;

    int lastShotTime; // Initialize lastShotTime to the current time

    int SHOT_DELAY;

    int cleared = 0;

    // Spacing between each enemy
    float space = 40.0f;

    // Speed of the rows of enemies
    // 0.5f
    float speed = 0.5f;

    //Creat a vector of enemy bullets
    vector<enemyBullet> ebullets;

    Player &player;

    // Array of enemies (Swarm)
    Enemy *swarm[enemyArr][enemyCol];

    // Swarm Constructor
    Swarm(Player &player);

    // Function to display the Swarm
    void display();

    // Function to move the Swarm
    void automove();

    // Function for the attack of the Swarm
    void attack(float dt);

    bool shootChance();

    // Function to destroy enemies within the Swarm
    void destroy(std::vector<Bullet> &b);

    void reachesPlayer();

    // Function to reposition the Swarm once the player kills off all enemies
    void reposition();

    // void collision(Player& player);

    // Swarm destructor (cases when the player kills off whole swarm + when player kills off a row)
    ~Swarm();
};

#endif