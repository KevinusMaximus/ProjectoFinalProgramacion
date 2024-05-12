#pragma once
#include<iostream>
#include "Scene.h"
#include "CargarMapas.h"
#include "Character.h"
#include"Camara.h"
#include "Enemigos.h"

class ScenePantallaJue : public Scene {
    CargarMapas MyMap;
    Character Player;
    Camara* camara;
    Enemigos Enemys;
  

public:
    ScenePantallaJue();
    ~ScenePantallaJue();
    void init();
    void update();
    void render();
};
