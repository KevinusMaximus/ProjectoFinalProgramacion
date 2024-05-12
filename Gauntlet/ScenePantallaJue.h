#pragma once
#include<iostream>
#include "Scene.h"
#include "CargarMapas.h"
#include "Character.h"
#include"Enemigo.h"


class ScenePantallaJue : public Scene {
    CargarMapas MyMap;
    Character Player;
    Enemigo Enemigo;

  

public:
    ScenePantallaJue();
    ~ScenePantallaJue();
    void init();
    void update();
    void render();
};
