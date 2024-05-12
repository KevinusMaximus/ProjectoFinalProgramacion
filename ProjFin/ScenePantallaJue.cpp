#include "ScenePantallaJue.h"



ScenePantallaJue::ScenePantallaJue()
{

}

ScenePantallaJue::~ScenePantallaJue()
{
}



void ScenePantallaJue::init()
{
    Player.init();
    Enemys.init();
    MyMap.loadMap("PrimerMapa.tmx");
    camara = new Camara(&Player, &MyMap, SCREEN_WIDTH, SCREEN_HEIGHT);
    mReinit = false;

}

void ScenePantallaJue::update()
{
    Player.update();
    Enemys.update(&Player);
    // Actualizar la cámara
    camara->update();
}

void ScenePantallaJue::render()
{
    MyMap.render();
    camara->render();
    Player.render();
    Enemys.render();
}

