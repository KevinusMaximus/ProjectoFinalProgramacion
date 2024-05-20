#pragma once
#include "resourceManager.h"
#include <vector>
#include <iostream>
#include <SDL.h>
#include<cstdlib>
#include"video.h"
#include"Character.h"
#include "ResourceManager.h"

class Enemigo
{
private:
    struct EnemyInstance {
        int PosX;
        int PosY;
        int enemigo;
        bool active;
    };

    std::vector<EnemyInstance> enemigos;

public:
    Enemigo();
    ~Enemigo();

    void init(int numEnemies);
    void update(Character& character);
    void render();
    int GetPosX(int index) const;
    int GetPosY(int index) const;
};


