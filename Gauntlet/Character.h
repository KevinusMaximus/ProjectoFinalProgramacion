#pragma once
#include <vector>
#include <iostream>
#include <SDL.h>
#include "resourceManager.h"
#include "KeyManager.h"
#include "video.h"
#include"soundManager.h"
#include"Global.h"




using namespace std;

struct Bullet {
    float PosX;
    float PosY;
    int direction;
    bool active; // Indica si hay bala activa o no
};

class Character {
private:
 
    SDL_Rect _GfxRect;
    SDL_Rect _GfxWorld;
    int eleccion;
    int direccionCharacter;
    int direccion;
    int Jugador;
    int Jugador2;
    int Jugador3;
    int Jugador4;
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
    void setEleccion(int valor);

    float getPosX() const { return PosX; }
    float getPosY() const { return PosY; }

    int getWorldX() { return _GfxWorld.x; };
    int getWorldY() { return _GfxWorld.y; };
    int getWorldW() { return _GfxWorld.w; };
    int getWorldH() { return _GfxWorld.h; };
    const std::vector<Bullet>& getActiveBullets() const {
        return bullets;
    }


};