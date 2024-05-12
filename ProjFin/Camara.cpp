#include "Camara.h"

Camara::Camara(Character* player, CargarMapas* map, int screenWidth, int screenHeight) {
    this->player = player;
    this->map = map;
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->cameraX = 0;
    this->cameraY = 0;
}

Camara::~Camara() {}

void Camara::update() {
    // Mover la c�mara para seguir al personaje
    int playerX = player->getPosX();
    int playerY = player->getPosY();

    cameraX = playerX - (screenWidth / 2);
    cameraY = playerY - (screenHeight / 2);

    // Asegurarse de que la c�mara no se salga del mapa
    if (cameraX < 0) cameraX = 0;
    if (cameraY < 0) cameraY = 0;
    if (cameraX > map->getWidth() - screenWidth) cameraX = map->getWidth() - screenWidth;
    if (cameraY > map->getHeight() - screenHeight) cameraY = map->getHeight() - screenHeight;
}

void Camara::render() {
    // Se supone que este m�todo renderiza el �rea visible del mapa en la pantalla,
    // usando las coordenadas de c�mara adecuadas. No se proporciona la implementaci�n
    // completa aqu� ya que depende de c�mo se renderiza el mapa en tu aplicaci�n.
    // Debes completar esta funci�n seg�n tu m�todo de renderizado de mapas.
}
