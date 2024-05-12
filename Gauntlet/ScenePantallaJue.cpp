#include "ScenePantallaJue.h"


ScenePantallaJue::ScenePantallaJue() {
}


ScenePantallaJue::~ScenePantallaJue() {
}

void ScenePantallaJue::init() {
    // Inicializamos el jugador y el mapa
    Player.init();
    Enemigo.init();
    MyMap.loadMap("PrimerMapa.tmx");
    mReinit = false;
}

void ScenePantallaJue::update() {
    // Actualizamos la posición del jugador
    Player.update();
    int jugadorPosX = Player.getPosX();
    int jugadorPosY = Player.getPosY();
    Enemigo.update(jugadorPosX, jugadorPosY);
    // Calculamos la velocidad de desplazamiento de la cámara (igual a la del jugador)
    int camaraVelX = Player.getPosX();
    int camaraVelY = Player.getPosY();

    // Movemos la cámara según la velocidad del jugador
    MyMap.setCameraPosition(jugadorPosX - (SCREEN_WIDTH / 2) + camaraVelX,
        jugadorPosY - (SCREEN_HEIGHT / 2) + camaraVelY);
}


void ScenePantallaJue::render() {
    // Renderizamos el mapa y el jugador
    MyMap.render();
   
    Player.render();
    Enemigo.render();
}
