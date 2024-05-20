#include <iostream>
#include "Character.h"
Global* Seleccion = Global::getInstance();
Character::Character() {
    direccionCharacter = 0;
    PosX = 32;
    PosY = 32;
    eleccion = 1;
}

Character::~Character() {}

void Character::setEleccion(int valor) {
    eleccion = valor;
}
void Character::init() {
    
    if (Seleccion->getSeleccion() == 1)
    {
    Jugador = ResourceManager::getInstance()->loadAndGetGraphicID("../images/Player1.png");
    }
    else if (Seleccion->getSeleccion() == 2)
    {
        Jugador = ResourceManager::getInstance()->loadAndGetGraphicID("../images/Player2.png");
    }
    else if (Seleccion->getSeleccion() == 3)
    {
        Jugador = ResourceManager::getInstance()->loadAndGetGraphicID("../images/Player3.png");
    }
    else if (Seleccion->getSeleccion() == 4)
    {
        Jugador = ResourceManager::getInstance()->loadAndGetGraphicID("../images/Player4.png");
    }
    if (Seleccion->getSeleccion() == 1)
    {
        Bala = ResourceManager::getInstance()->loadAndGetGraphicID("../images/bala.png");
        SoundManager::getInstance()->loadSound("../sounds/firewarrior.mp3", "1");
    }
    else if (Seleccion->getSeleccion() == 2)
    {
        Bala = ResourceManager::getInstance()->loadAndGetGraphicID("../images/bala2.png");
        SoundManager::getInstance()->loadSound("../sounds/firevalkyrie.mp3", "2");
    }
    else if (Seleccion->getSeleccion() == 3)
    {
        Bala = ResourceManager::getInstance()->loadAndGetGraphicID("../images/bala3.png");
        SoundManager::getInstance()->loadSound("../sounds/firewizard.mp3", "3");
    }
    else if (Seleccion->getSeleccion() == 4)
    {
        Bala = ResourceManager::getInstance()->loadAndGetGraphicID("../images/bala4.png");
        
        if (!SoundManager::getInstance()->loadSound("../sounds/fireelf.mp3", "4")) {
            cout<< "Failed to load the song!" << endl;
        }
    }
    
}

void Character::shoot() {
    // Create a bullet and add it to the vector
    Bullet bullet;
    bullet.PosX = PosX;
    bullet.PosY = PosY;
    bullet.direction = direccionCharacter;
    bullet.active = true;
    bullets.push_back(bullet);

    if (Seleccion->getSeleccion() == 1)
    {
        SoundManager::getInstance()->playSound("1", 0);
    }
    if (Seleccion->getSeleccion() == 2)
    {
        SoundManager::getInstance()->playSound("2", 0);
    }
    if (Seleccion->getSeleccion() == 3)
    {
        SoundManager::getInstance()->playSound("3", 0);
    }
    if (Seleccion->getSeleccion() == 4)
    {
        SoundManager::getInstance()->playSound("4", 0);
    }
}

void Character::update() {
    KeyManager* Tecla = KeyManager::getInstance();
    if (Tecla->isKeyDown(ARRIBA)) {
        if (PosY > 32) {
            PosY -= 10;
            direccionCharacter = 1;
        }
    }
    if (Tecla->isKeyDown(ABAJO)) {
        if (PosY < 1010) {
            PosY += 10;
            direccionCharacter = 2;
        }
    }
    if (Tecla->isKeyDown(IZQUIERDA)) {
        if (PosX > 32) {
            PosX -= 10;
            direccionCharacter = 3;
        }
    }
    if (Tecla->isKeyDown(DERECHA)) {
        if (PosX < 1156) {
            PosX += 10;
            direccionCharacter = 4;
        }
    }
    if (Tecla->isKeyDown(ESPACIO)) {
        shoot();
    }

    // Movimiento bala
    for (auto& bullet : bullets) {
        if (bullet.active) {
            switch (bullet.direction) {
            case 1: bullet.PosY -= 5; break;
            case 2: bullet.PosY += 5; break;
            case 3: bullet.PosX -= 5; break;
            case 4: bullet.PosX += 5; break;
            }
        }
    }
}

void Character::render() {

    video::getInstance()->renderGraphic(Jugador, PosX, PosY, 32, 32);
    

    for (const auto& bullet : bullets) {
        if (bullet.active) {
            video::getInstance()->renderGraphic(Bala, bullet.PosX, bullet.PosY, 32, 32);
        }
    }
}


