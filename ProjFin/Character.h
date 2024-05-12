#pragma once
#include <vector>
#include <iostream>
#include <SDL.h>
#include "resourceManager.h"
#include "KeyManager.h"
#include "video.h"
using namespace std;

struct Bullet {
    float PosX;
    float PosY;
    int direction;
    bool active; // Indicates if the bullet is active or not
};

class Character {
private:
    int direccionCharacter;
    int direccion;
    int disparo;
    int Jugador;
    int Bala;
    float PosX;
    float PosY;
    std::vector<Bullet> bullets;

public:
    Character();
    ~Character();
    void init();
    void update();
    void render();
    void shoot(); // Funcion para disparar

    float getPosX() const { return PosX; }
    float getPosY() const { return PosY; }
    void setPosX(float x) { PosX = x; }
    void setPosY(float y) { PosY = y; }

};