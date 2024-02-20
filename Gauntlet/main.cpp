#include <SDL_image.h>
#include <iostream>
#include "keyManager.h"
#include "soundManager.h"
#include <string>
#include"video.h"
#include <SDL_mixer.h>

using namespace std;

//Pantalla
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Variables globales
SDL_Surface* gScreenSurface = NULL;


int main(int argc, char* args[])
{
	int eleccion = 1;
	SDL_Init(SDL_INIT_EVERYTHING);
	//Crear la pantalla
	video::getInstance();

	//Inicializar variables de clase
	KeyManager* Teclas = KeyManager::getInstance();
	SoundManager* Sonido = SoundManager::getInstance();
	
	Sonido->init();
	Sonido->loadSound("../sounds/firewarrior.ogg", "sound1");
	Sonido->loadSound("../sounds/firevalkyrie.ogg", "sound2");
	Sonido->loadSound("../sounds/firewizard.ogg", "sound3");


	while (true) {

		Teclas->update();
		switch (eleccion)
		{
		case 1: 
			if (Teclas->isKeyDown(ARRIBA))
			{
				cout << "Arriba" << endl;
			}
			if (Teclas->isKeyDown(ABAJO))
			{
				cout << "Abajo" << endl;
			}
			if (Teclas->isKeyDown(IZQUIERDA))
			{
				Sonido->playSound("sound3", 0);
				cout << "Izquierda" << endl;
			}
			if (Teclas->isKeyDown(DERECHA))
			{
				Sonido->playSound("sound2", 0);
				cout << "Derecha" << endl;
			}
			if (Teclas->isKeyDown(ESPACIO))
			{
				Sonido->playSound("sound1", 0);
				cout << "Ataque" << endl;
			}
			break;

		}


		//Hacer update de la surface 
		video::getInstance()->updateScreen();
		video::getInstance()->waitTime(100);
	}
	video::getInstance()->close();
	return 0;
}