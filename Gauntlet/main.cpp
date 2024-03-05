#include <SDL_image.h>
#include <iostream>
#include "keyManager.h"
#include "soundManager.h"
#include"resourceManager.h"
#include <string>
#include"video.h"
#include <SDL_mixer.h>
#include "SceneDirector.h"
#include "InputControl"

#include "Timer.h"

Uint32 		global_elapsed_time = 0;
bool		gameOn = true;
SceneDirector* sDirector = NULL;
InputControl* sInputControl = NULL;

int main(int argc, char* argv[]) {
	//Init Singletons
	sInputControl = ControlInput::getInstance();
	sDirector = SceneDirector::getInstance();

	//Main Loop
	// Init Time control
	Timer* globalTimer = new Timer();
	globalTimer->start();
	Uint32 last_time = 0;

	while (gameOn) {
		//ReInit o no
		if (sDirector->getCurrentScene()->mustReInit()) {
			sDirector->getCurrentScene()->ReInit();
		}
		// Read controls
		sInputControl->update();

		//Update time
		Uint32 actualtime = globalTimer->getTicks();
		global_elapsed_time = actualtime - last_time;
		last_time = actualtime;

		// Updates scene
		sDirector->getCurrentScene()->update();

		if (!sDirector->getCurrentScene()->mustReInit()) {
			sDirector->getCurrentScene()->render();
		}
	}

	return 0;
}

