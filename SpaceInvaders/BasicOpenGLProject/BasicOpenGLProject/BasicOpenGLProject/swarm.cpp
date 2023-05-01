#include "swarm.h"
#include "player.h"
#include "enemyBullet.h"
#include "enemy.h"

#include <iostream>

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 800

// Swarm Constructor
Swarm::Swarm(Player &player) : player(player)
{

    // For each row of enemies...
    for (int i = 0; i < enemyArr; i++)
    {
        // For each enemy in each row...
        for (int j = 0; j < enemyCol; j++)
        {
            if (i == 0)
            {
                swarm[i][j] = new Imperator();
            }
            else if (i == 1 || i == 2)
            {
                swarm[i][j] = new Praetor();
            }
            else if (i == 3 || i == 4)
            {
                swarm[i][j] = new Legate();
            }
        }
    }

    // For each row of enemies...
    for (int i = 0; i < enemyArr; i++)
    {
        // For each enemy in each row...
        for (int j = 0; j < enemyCol; j++)
        {
            // Set x position of swarm (include spacing)
            swarm[i][j]->x = space * j + 50.0f;

            // Set y position of swarm (include spacing)
            swarm[i][j]->y = SCREEN_HEIGHT - space * i - 100.0f;

            // Set width of each enemy
            swarm[i][j]->width = 20.0f;

            // Set height of each enemy
            swarm[i][j]->height = 20.0f;

            // Set the direction of the enemy
            swarm[i][j]->dir = 1;
        }
    }
}

// Function to display the Swarm
void Swarm::display()
{
    // For each row of enemies...
    for (int i = 0; i < enemyArr; i++)
    {
        // For each enemy in each row...
        for (int j = 0; j < enemyCol; j++)
        {
            if (swarm[i][j]->visible == true)
            {
                // Display each enemy
                swarm[i][j]->display();
            }
        }
    }
}

// Function to move the swarm automatically
void Swarm::automove()
{

    // Variable to check if the swarm reaches the edges
    bool edges = false;

    // For each row of enemies...
    for (int i = 0; i < enemyArr; i++)
    {
        // For each enemy in each row...
        for (int j = 0; j < enemyCol; j++)
        {
            // If the swarm's direction is to the right...
            if (swarm[i][j]->dir == 1)
            {
                // The enemies will move to the right...
                swarm[i][j]->x = swarm[i][j]->x + speed;

                // If the swarm x movement along with the width of the swarm is greater than or equal to the width (right side) of the screen...
                if (swarm[i][j]->x + swarm[i][j]->width >= SCREEN_WIDTH)
                {
                    // We will say we hit the rigth side of the screen
                    edges = true;
                }
            }

            // Otherwise
            else
            {
                // The swarm will move to the left
                swarm[i][j]->x = swarm[i][j]->x - speed;

                // And if the swarm's x-position is less than or equal to the left side of the screen...
                if (swarm[i][j]->x <= 0)
                {
                    // We will say we hit the left side of the screen
                    edges = true;
                }
            }
        }

        // And if we hit either side of the screen
        if (edges == true)
        {
            // For each enemy in the row of enemies
            for (int j = 0; j < enemyCol; j++)
            {
                // If the swarm is moving to the right
                if (swarm[i][j]->dir == 1)
                {
                    // We will make the swarm move to the left
                    swarm[i][j]->dir = 0;
                }

                // Otherwise if the swarm is moving to the left...
                else if (swarm[i][j]->dir == 0)
                {
                    // We will move it to the right
                    swarm[i][j]->dir = 1;
                }

                // And shift the swarm down
                swarm[i][j]->y = swarm[i][j]->y - space;
            }
        }
    }

    glutPostRedisplay();
}

void Swarm::destroy(std::vector<Bullet> &b)
{
    // For each row of enemies...
    for (int i = 0; i < enemyArr; i++)
    {
        // For each enemy in each row...
        for (int j = 0; j < enemyCol; j++)
        {

            if (swarm[i][j]->hit == true)
            {
                swarm[i][j]->visible = false;
                
            }
            else
            {
                for (int k = 0; k < b.size(); k++)
                {
                    // if (b[k].x > swarm[i][j]->x && b[k].x < swarm[i][j]->x + swarm[i][j]->width && b[k].y > swarm[i][j]->y && b[k].y < swarm[i][j]->y + swarm[i][j]->height)
                    if (b[k].collide(*swarm[i][j]) == true)
                    {
                        // if (swarm[i][j] != nullptr)
                        // {
                        swarm[i][j]->hit = true;
                    
                        if (swarm[i][j]->getType() == 1)
                        {
                            player.score = player.score + 10;
                        }
                        else if (swarm[i][j]->getType() == 2)
                        {
                            player.score = player.score + 20;
                        }
                        else if (swarm[i][j]->getType() == 3)
                        {
                            player.score = player.score + 30;
                        }
                    
                        b[k].shot = false;
                        cleared++;
                        // std::cout << "Enemy hit\n";
                        
                    }
                }
            }
        }
    }
    
    // Draw all remaining bullets
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i].exist())
        {
            b[i].display();
        }
        else
        {
            // Remove bullet if it does not exist
            b.erase(b.begin() + i);
            i--;
        }
    }
}

void Swarm::reachesPlayer()
{
    // For each row of enemies...
    for (int i = 0; i < enemyArr; i++)
    {
        // For each enemy in each row...
        for (int j = 0; j < enemyCol; j++)
        {
            // If the swarm reaches the player
            if (swarm[i][j]->x >= 0 && swarm[i][j]->x <= 480 && swarm[i][j]->y < 180.0f)
            {
                // And any enemies of the swarm is visible...
                if (swarm[i][j]->visible == true)
                {
                    // We set the player lives to 0
                    player.lives = 0;
                    // std::cout << "Player has died\n";
                }
            }
        }
    }
    // If the player dies (aka the enemies got to it or shot it)
    if (player.lives == 0)
    {

        player.mag = 0;
        // We set our cleared counter to 0
        cleared = 0;

        player.reviveCheck = true;

        // We stop the swarm
        if (player.reviveCheck == true)
        {
            player.reviveCheck = false;
            cleared = 45;
            // player.display();
            reposition();
            speed = 0.5f;
        }
    }
}

void Swarm::reposition()
{
    // Otherwise if the player cleared all enemies
    if (cleared == 45)
    {
        // We set our cleared counter to zero
        cleared = 0;

        // And increase the speed of the next swarm
        speed += 0.5f;

        // For each row of enemies...
        for (int i = 0; i < enemyArr; i++)
        {
            // For each enemy in each row...
            for (int j = 0; j < enemyCol; j++)
            {
                // Set x position of swarm (include spacing)
                swarm[i][j]->x = space * j + 50.0f;

                // Set y position of swarm (include spacing)
                swarm[i][j]->y = SCREEN_HEIGHT - space * i - 100.0f;

                // Set the direction of the enemy
                swarm[i][j]->dir = 1;

                // Make the swarm visible
                swarm[i][j]->visible = true;

                // Make thier "hit check" false
                swarm[i][j]->hit = false;

                // And have them automatically move
                swarm[i][j]->automove();
            }
        }
    }
}

bool Swarm::shootChance()
{
    float shootingProbability = 0.02;
    float randomValue = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    if (randomValue < shootingProbability) {
        int totalEnemies = enemyArr * enemyCol;
        int chance = rand() % totalEnemies;
        if (chance == 0)
        {
            int randRow = rand() % enemyArr;
            int randCol = rand() % enemyCol;
            if (swarm[randRow][randCol]->visible)
            {
                ebullets.push_back(enemyBullet(swarm[randRow][randCol]->x + swarm[randRow][randCol]->width / 2,
                swarm[randRow][randCol]->y + swarm[randRow][randCol]->height));
                return true;
            }
        }
    }
    return false;
}


void Swarm::attack(float dt)
{
    for (int i = 0; i < enemyArr; i++) {
        for (int j = 0; j < enemyCol; j++) {
            Enemy* enemy = swarm[i][j];
            if (enemy->visible == true) {
                bool canShoot = shootChance();
                if (canShoot) 
                {
                    enemy->setCanShoot(true);
                    ebullets.push_back(enemyBullet(enemy->x, enemy->y));
                }
                if (enemy->canShoot) 
                {
                    enemy->setCanShoot(false);
                    enemy->setTimeSinceLastShot(0);
                } 
                else if (canShoot == false){
                    // Increment the time since the last shot for this enemy
                    enemy->setTimeSinceLastShot(enemy->getTimeSinceLastShot() + dt);
                    // If enough time has elapsed, the enemy can shoot again
                    if (enemy->getTimeSinceLastShot() >= enemy->getCooldown()) {
                        enemy->setCanShoot(true);
                    }
                }
            }
        }
    }
}

// void Swarm::collision(Player& player)
// {
//     for (int i = 0; i < ebullets.size(); i++){
//         if (ebullets[i].collide(player))
//         {
//             player.lives--;
//             ebullets.erase(ebullets.begin() + i);
//         }
//     }
//     // player.reviveCheck = false;

// }


// void Swarm::revive()
// {
//     if (key == ' ')
//     {
//         player.lives = 3;
//         speed = 0.5f;
//         cleared = 45;
//         for (int i = 0; i < enemyArr; i++)
//         {
//             // For each enemy in each row...
//             for (int j = 0; j < enemyCol; j++)
//             {
//                 reposition();
//             }
//         }
//     }
// }

// Swarm Destructor
Swarm::~Swarm()
{
    // For each row of enemies...
    for (int i = 0; i < enemyArr; i++)
    {
        // For each enemy in each row...
        for (int j = 0; j < enemyCol; j++)
        {
            // Delete the enemy object
            delete swarm[i][j];
        }
    }
}