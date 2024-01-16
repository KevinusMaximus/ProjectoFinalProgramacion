#include <iostream>
#include "resourceManager.h"
#include "video.h"

int main(int argc, char* args[])
{
	video::getInstance();

	Sint32 elPepe = ResourceManager::getInstance()->loadAndGetGraphicID("halalgoku.jpg");
	Sint32 fondito = ResourceManager::getInstance()->loadAndGetGraphicID("losuponia.jpg");
	ResourceManager::getInstance()->removeGraphic("halalgoku.jpg");

	elPepe = ResourceManager::getInstance()->loadAndGetGraphicID("mondongo.jpg");

	bool fin = false;
	while (!fin)
	{
		SDL_Event MyEvent;
		while (SDL_PollEvent(&MyEvent))
		{
			switch (MyEvent.type)
			{
			case SDL_QUIT:
				fin = true;
				break;
			case SDL_KEYDOWN:
				if (MyEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				{
					fin = true;
				}
				break;
			default:
				break;
			}
		}

		video::getInstance()->renderGraphic(fondito, 0, 0, ResourceManager::getInstance()->getGraphicWidth(fondito), ResourceManager::getInstance()->getGraphicWidth(fondito), ResourceManager::getInstance()->getGraphicWidth(fondito), ResourceManager::getInstance()->getGraphicHeight(fondito));
		video::getInstance()->renderGraphic(elPepe, 360, 0, ResourceManager::getInstance()->getGraphicWidth(elPepe), ResourceManager::getInstance()->getGraphicWidth(elPepe), ResourceManager::getInstance()->getGraphicWidth(elPepe), ResourceManager::getInstance()->getGraphicHeight(elPepe));

		video::getInstance()->updateScreen();
		video::getInstance()->waitTime(100);
	}
	video::getInstance()->close();
	return 0;
}