#pragma once
#ifndef KEYMANAGER_H
#define KEYMANAGER_H

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