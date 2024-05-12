#include <iostream>
#include "Character.h"



Character::Character()
{
    direccion = 0;
    disparo = 0;

    PosX = 32;
    PosY = 32;
}

Character::~Character()
{
}

void Character::init()
{
    Jugador = ResourceManager::getInstance()->loadAndGetGraphicID("../images/Player1.png");
    Bala = ResourceManager::getInstance()->loadAndGetGraphicID("../images/bala.png");
}

void Character::shoot() {
    // Create a bullet and add it to the vector
    Bullet bullet;
    bullet.PosX = PosX;
    bullet.PosY = PosY;
    bullet.direction = direccionCharacter; // Assuming direccion holds the direction the character is facing
    bullet.active = true;
    bullets.push_back(bullet);
}

void Character::update()
{
    KeyManager* Tecla = KeyManager::getInstance();
    if (Tecla->isKeyDown(ARRIBA))
    {
        if (PosY > 32)
        {
            PosY -= 10;
            direccionCharacter = 1;

        }
    }
    if (Tecla->isKeyDown(ABAJO))
    {
        if (PosY <1010)
        {
            PosY += 10;
            direccionCharacter = 2;
        }
    }
    if (Tecla->isKeyDown(IZQUIERDA))
    {
        if (PosX > 32)
        {
            PosX -= 10;
            direccionCharacter = 3;
        }
    }
    if (Tecla->isKeyDown(DERECHA))
    {
        if (PosX < 1156)
        {
            PosX += 10;
            direccionCharacter = 4;
        }
    }
    if (Tecla->isKeyDown(ESPACIO)) {
        shoot();
      
    }

    // Movimiento bala que ahora no se si va ahi o no
    for (auto bullet = bullets.begin(); bullet != bullets.end(); ++bullet) {
        if (bullet->active) {
            // Movimiento de las balas hacia una direccion
            switch (bullet->direction) {
            case 1:
                bullet->PosY -= 5;

                break;
            case 2:
                bullet->PosY += 5;

                break;
            case 3:
                bullet->PosX -= 5;

                break;
            case 4:
                bullet->PosX += 5;

                break;
            }
        }
        // TOPES !
    }
}

void Character::render() {
    // Render Character
    video::getInstance()->renderGraphic(Jugador, PosX, PosY, 32, 32);

    // Render bullets
    for (const auto& bullet : bullets) {
        if (bullet.active) {
            // Render bullet
            video::getInstance()->renderGraphic(Bala, bullet.PosX, bullet.PosY, 32, 32); // Example renderBullet function
        }
    }
}
