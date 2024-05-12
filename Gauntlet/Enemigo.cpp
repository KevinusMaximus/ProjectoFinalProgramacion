#include "Enemigo.h"


Enemigo::Enemigo()
{
    
    enemigo = ResourceManager::getInstance()->loadAndGetGraphicID("../images/Enemigo1.png");

    vida = 5;

    PosX = 1000;
    PosY = 100;

    vEnemy = 1.0f;
}

Enemigo::~Enemigo()
{
}

void Enemigo::init()
{
}

void Enemigo::update(float characterPosX, float characterPosY)
{
    // Calcula la distancia entre el enemigo y el personaje
    float distance = calculateDistance(PosX, PosY, characterPosX, characterPosY);

    // Define el umbral de distancia para comenzar a perseguir al personaje
    float chaseDistance = 600.0f;

    // Si la distancia es menor que el umbral, mueve al enemigo hacia el personaje
    if (distance < chaseDistance) {
        moveTowards(characterPosX, characterPosY);
    }
}

void Enemigo::render()
{
    // Render Enemy
    video::getInstance()->renderGraphic(enemigo, PosX, PosY, 32, 32);
}

float Enemigo::calculateDistance(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void Enemigo::moveTowards(float targetX, float targetY)
{
    // Calcula la dirección hacia la que debe moverse
    float deltaX = targetX - PosX;
    float deltaY = targetY - PosY;
    float distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

    // Normaliza el vector de dirección
    float dirX = deltaX / distance;
    float dirY = deltaY / distance;

    // Mueve al enemigo hacia el personaje
    PosX += dirX * vEnemy;
    PosY += dirY * vEnemy;
}