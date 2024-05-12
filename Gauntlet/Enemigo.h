#pragma once

#include "Character.h"
#include "resourceManager.h"
#include "ResourceManager.h"
class Enemigo
{
private:
    int enemigo;

    int vida;

    float PosX;
    float PosY;

    float vEnemy;

public:
    Enemigo();
    ~Enemigo();

    void init();
    void update(float characterPosX, float characterPosY); // Se pasan las posiciones del personaje
    void render();

    float calculateDistance(float x1, float y1, float x2, float y2); // Calcular la distancia entre dos puntos
    void moveTowards(float targetX, float targetY); // Mover al enemigo hacia un punto

    float GetPosX() const { return PosX; } // Obtener la posición X del enemigo
    float GetPosY() const { return PosY; } // Obtener la posición Y del enemigo

    int GetHealth() const { return vida; } // Obtener la vida del enemigo
};


