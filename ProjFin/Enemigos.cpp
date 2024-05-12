#include "Enemigos.h"
#include <cmath>

Enemigos::Enemigos(float initialSpeed) : speed(initialSpeed) 
{
}

void Enemigos::init()
{
    enemigo1 = ResourceManager::getInstance()->loadAndGetGraphicID("enemigos1.png");
}

void Enemigos::update(Character* player) {
    float playerX = player->getPosX();
    float playerY = player->getPosY();

    float enemyX = getPosX();
    float enemyY = getPosY();

    float relativeX = playerX - enemyX;
    float relativeY = playerY - enemyY;

    // Calculating direction
    float deltaX = playerX - getPosX();
    float deltaY = playerY - getPosY();

    // Normalize direction
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    if (distance > 0) {
        deltaX /= distance;
        deltaY /= distance;

        // Move towards player
        setPosX(getPosX() + deltaX * speed);
        setPosY(getPosY() + deltaY * speed);
    }

    std::cout << "Posición relativa del enemigo respecto al jugador: (" << relativeX << ", " << relativeY << ")" << std::endl;

}

void Enemigos::render() {
    // Renderiza el personaje que sigue al jugador
    video::getInstance()->renderGraphic(enemigo1, 40, 200, 32, 32); // Ajusta el tamaño según las necesidades
}