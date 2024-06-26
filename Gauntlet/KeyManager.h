#pragma once
#ifndef KEYMANAGER_H
#define KEYMANAGER_H

#define ESCAPE  SDL_SCANCODE_ESCAPE
#define ESPACIO  SDL_SCANCODE_SPACE
#define ARRIBA  SDL_SCANCODE_UP
#define ABAJO  SDL_SCANCODE_DOWN
#define IZQUIERDA  SDL_SCANCODE_LEFT
#define DERECHA  SDL_SCANCODE_RIGHT
#define ENTER  SDL_SCANCODE_RETURN

#define UNO SDL_SCANCODE_1 
#define DOS SDL_SCANCODE_2
#define TRES SDL_SCANCODE_3
#define CUATRO SDL_SCANCODE_4 
enum Teclas
{
    Uno,Dos,Tres,Cuatro
};


#include <SDL.h>
#include <unordered_map>

class KeyManager
{
public:
    ~KeyManager();

    void update();
    bool isKeyPressed(SDL_Scancode key);
    bool isKeyDown(SDL_Scancode key);
    bool isKeyUp(SDL_Scancode key);
    static KeyManager* getInstance();

private:
    KeyManager();
    void updateKeyStates(const SDL_Event& event);

    std::unordered_map<SDL_Scancode, bool> mKeyStates;
    std::unordered_map<SDL_Scancode, bool> mKeyDownStates;
    std::unordered_map<SDL_Scancode, bool> mKeyUpStates;
    static KeyManager* pInstance;
};

#endif