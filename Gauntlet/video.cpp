#include "video.h"
#include "resourceManager.h"
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

video* video::pInstance = NULL;

video::video()
{
	gWindow = NULL;
	gRenderer = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	gWindow = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

video::~video()
{
}

video* video::getInstance()
{
	if (pInstance == NULL)
	{
		pInstance = new video();
	}
	return pInstance;
}

void video::renderGraphic(int img, int posX, int posY, int width, int height)
{
	SDL_Rect r, rectAux;
	r.x = posX;
	r.y = posY;
	
	rectAux.h = height;
	rectAux.w = width;
	rectAux.x = 0;
	rectAux.y = 0;

	SDL_Texture* origin = ResourceManager::getInstance()->getGraphicByID(img);
	SDL_RenderCopy(gRenderer, origin, &rectAux, &r);
}

void video::renderGraphic(int img, int posX, int posY, int wid, int hei, int width, int height)
{
	SDL_Rect r, rectAux;
	r.x = posX;
	r.y = posY;
	r.w = wid;
	r.h = hei;

	rectAux.h = height;
	rectAux.w = width;
	rectAux.x = 0;
	rectAux.y = 0;

	SDL_Texture* origin = ResourceManager::getInstance()->getGraphicByID(img);
	SDL_RenderCopy(gRenderer, origin, &rectAux, &r);
}


void video::clearScreen(unsigned int color_key)
{
	int r = 0xFF << 24;
	int g = 0xFF << 16;
	int b = 0xFF << 8;
	int a = 0xFF;
	SDL_SetRenderDrawColor(gRenderer, r, g, b, a);
	SDL_RenderClear(gRenderer);
}

void video::updateScreen()
{
	SDL_RenderPresent(gRenderer);
}

void video::waitTime(int ms)
{
	SDL_Delay(ms);
}

void video::close()
{
	SDL_Quit();
}
