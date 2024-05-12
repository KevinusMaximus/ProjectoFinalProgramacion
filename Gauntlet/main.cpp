#include <SDL_image.h>
#include <iostream>
#include "keyManager.h"
#include "soundManager.h"
#include"resourceManager.h"
#include <string>
#include"video.h"
#include <SDL_mixer.h>
#include "SceneDirector.h"

//#include "Timer.h" Mirar de hacer una clase

Uint32 		global_elapsed_time = 0;
bool		gameOn = true;
SceneDirector* sDirector = NULL;
SoundManager* sonido = NULL;
KeyManager* teclas = NULL;
ResourceManager* inicio = NULL;


int main(int argc, char* argv[]) {
	//Init Singletons
	video::getInstance();
	sDirector = SceneDirector::getInstance();
	sonido = SoundManager::getInstance();
	teclas = KeyManager::getInstance();
	inicio = ResourceManager::getInstance();

	while (gameOn) {
		//ReInit o no
		if (sDirector->getCurrentScene()->mustReInit()) {
			sDirector->getCurrentScene()->init();
		}
		teclas->update();
		if (teclas->isKeyDown(ENTER)) {
			gameOn = false;
		}
		// Updates scene
		sDirector->getCurrentScene()->update();
		
		sDirector->getCurrentScene()->render();
		video::getInstance()->updateScreen();
		

	}
	return 0;
}
