#pragma once
#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include<SDL_mixer.h>
#include <string>
#include <unordered_map>

class SoundManager
{
public:
    ~SoundManager();

    bool init();
    void close();

    bool loadSound(const std::string& filePath, const std::string& soundID);
    void playSound(const std::string& soundID, int loops);

    static SoundManager* getInstance();

private:
    SoundManager();

    std::unordered_map<std::string, Mix_Chunk*> mSoundMap;
    static SoundManager* pInstance;
};

#endif