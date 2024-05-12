#pragma once
#include "Character.h"
#include "CargarMapas.h"

class Camara
{
private:
    int screenWidth;
    int screenHeight;
    int cameraX;
    int cameraY;
    Character* player;
    CargarMapas* map;

public:
    Camara(Character* player, CargarMapas* map, int screenWidth, int screenHeight);
    ~Camara();
    void update();
    void render();
};

