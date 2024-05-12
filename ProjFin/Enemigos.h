#pragma once
#include "Character.h"
class Enemigos : public Character
{
private:
    float speed;
    int EnemigoFollow;
    int enemigo1;

public:
   
    Enemigos(float initialSpeed = 5.0f);
    void init();
    void update(Character* player);
    void render();

};

