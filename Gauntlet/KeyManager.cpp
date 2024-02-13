#include "keyManager.h"

KeyManager::~KeyManager(void)
{
}

void KeyManager::update()
{
    mKeyDownStates.clear();
    mKeyUpStates.clear();

    SDL_Event event;
    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
        {
            updateKeyStates(event);
        }
    }
}

bool KeyManager::isKeyPressed(SDL_Scancode key)
{
    return mKeyStates[key];
}

bool KeyManager::isKeyDown(SDL_Scancode key)
{
    return mKeyDownStates[key];
}

bool KeyManager::isKeyUp(SDL_Scancode key)
{
    return mKeyUpStates[key];
}

KeyManager* KeyManager::pInstance = nullptr;

KeyManager::KeyManager(void)
{
}

void KeyManager::updateKeyStates(const SDL_Event& event)
{
    SDL_Scancode key = event.key.keysym.scancode;

    if (event.type == SDL_KEYDOWN)
    {
        mKeyStates[key] = true;
        mKeyDownStates[key] = true;
    }
    else if (event.type == SDL_KEYUP)
    {
        mKeyStates[key] = false;
        mKeyUpStates[key] = true;
    }
}

KeyManager* KeyManager::getInstance()
{
    if (pInstance == nullptr)
    {
        pInstance = new KeyManager();
    }
    return pInstance;
}