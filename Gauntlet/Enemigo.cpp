#include "Enemigo.h"
#include "video.h"
#include <cstdlib>
#include <ctime>

Enemigo::Enemigo() {}

Enemigo::~Enemigo() {}

void Enemigo::init(int numEnemies)
{
    srand(time(NULL));

    for (int i = 0; i < numEnemies; ++i) {
        EnemyInstance newEnemy;
        newEnemy.PosX = rand() % 500;
        newEnemy.PosY = rand() % 500;
        newEnemy.active = true;
        newEnemy.enemigo = ResourceManager::getInstance()->loadAndGetGraphicID("../images/Enemigo1.png");

        enemigos.push_back(newEnemy);
    }
}

void Enemigo::update(Character& character) {
    for (auto& enemy : enemigos) {
        // Perseguir al personaje
        if (enemy.PosX < character.getPosX()) {
            enemy.PosX++;
        }
        else if (enemy.PosX > character.getPosX()) {
            enemy.PosX--;
        }

        if (enemy.PosY < character.getPosY()) {
            enemy.PosY++;
        }
        else if (enemy.PosY > character.getPosY()) {
            enemy.PosY--;
        }

        // Comprobar si ha sido golpeado por una bala del personaje
        const std::vector<Bullet>& characterBullets = character.getActiveBullets();
        for (const auto& bullet : characterBullets) {
            if (bullet.active &&
                bullet.PosX >= enemy.PosX && bullet.PosX <= enemy.PosX + 32 &&
                bullet.PosY >= enemy.PosY && bullet.PosY <= enemy.PosY + 32) {
                enemy.active = false;
                break;
            }
        }
    }
}

void Enemigo::render() {
    for (const auto& enemy : enemigos) {
        // Renderizar enemigo si está activo
        if (enemy.active) {
            // Renderizar el enemigo en la posición actual
            video::getInstance()->renderGraphic(enemy.enemigo, enemy.PosX, enemy.PosY, 32, 32);
        }
    }
}

int Enemigo::GetPosX(int index) const {
    if (index >= 0 && index < enemigos.size())
        return enemigos[index].PosX;
    else
        return -1; // Manejo de error
}

int Enemigo::GetPosY(int index) const {
    if (index >= 0 && index < enemigos.size())
        return enemigos[index].PosY;
    else
        return -1; // Manejo de error
}
