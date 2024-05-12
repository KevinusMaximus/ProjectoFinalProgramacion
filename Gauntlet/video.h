#pragma once
#include "sdl.h"
#define SCREEN_WIDTH 1220
#define SCREEN_HEIGHT 1080
class video
{
	public:
		~video();
		static video* getInstance();
		void renderGraphic(int img, int posX, int posY, int width, int height);
		void renderGraphic(int img, int posX, int posY, int wid, int hei, int width, int height);
		void clearScreen(unsigned int color_key);
		void updateScreen();
		void waitTime(int ms);
		void close();
		SDL_Window* gWindow;
		SDL_Renderer* gRenderer;
	protected:
		video();
		static video* pInstance;
};

