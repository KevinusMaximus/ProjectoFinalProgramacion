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
    // Mover la cámara para seguir al personaje
    int playerX = player->getPosX();
    int playerY = player->getPosY();

    cameraX = playerX - (screenWidth / 2);
    cameraY = playerY - (screenHeight / 2);

    // Asegurarse de que la cámara no se salga del mapa
    if (cameraX < 0) cameraX = 0;
    if (cameraY < 0) cameraY = 0;
    if (cameraX > map->getWidth() - screenWidth) cameraX = map->getWidth() - screenWidth;
    if (cameraY > map->getHeight() - screenHeight) cameraY = map->getHeight() - screenHeight;
}

void Camara::render() {
    // Se supone que este método renderiza el área visible del mapa en la pantalla,
    // usando las coordenadas de cámara adecuadas. No se proporciona la implementación
    // completa aquí ya que depende de cómo se renderiza el mapa en tu aplicación.
    // Debes completar esta función según tu método de renderizado de mapas.
}
