#include "soundManager.h"

SoundManager::~SoundManager()
{
    close();
}

bool SoundManager::init()
{
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        return false;
    }
    return true;
}

void SoundManager::close()
{
    for (auto& pair : mSoundMap)
    {
        Mix_FreeChunk(pair.second);
    }
    mSoundMap.clear();

    Mix_CloseAudio();
}

bool SoundManager::loadSound(const std::string& filePath, const std::string& soundID)
{
    Mix_Chunk* sound = Mix_LoadWAV(filePath.c_str());
    if (sound == nullptr)
    {
        return false;
    }
    mSoundMap[soundID] = sound;
    return true;
}

void SoundManager::playSound(const std::string& soundID, int loops)
{
    Mix_PlayChannel(-1, mSoundMap[soundID], loops);
}

SoundManager* SoundManager::getInstance()
{
    if (pInstance == nullptr)
    {
        pInstance = new SoundManager();
    }
    return pInstance;
}

SoundManager::SoundManager()
{
}

SoundManager* SoundManager::pInstance = nullptr;