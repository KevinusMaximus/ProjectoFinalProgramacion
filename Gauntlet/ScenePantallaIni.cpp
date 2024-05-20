#include "ScenePantallaIni.h"

ScenePantallaIni::ScenePantallaIni()
{
	CargaImagen = NULL;
}

ScenePantallaIni::~ScenePantallaIni()
{
}

void ScenePantallaIni::init()
{
	
	CargaImagen = ResourceManager::getInstance()->loadAndGetGraphicID("../images/gauntlet.png");//Cargo los graficos(imagenes)
	mReinit = false;
}

void ScenePantallaIni::update()
{
	KeyManager* Tecla = KeyManager::getInstance();
	Global* Selector = Global::getInstance();
	if (Tecla->isKeyDown(UNO))
	{
		Selector->setSeleccion(1);
		ResourceManager::getInstance()->removeGraphic("../images/gauntlet.png");
		SceneDirector::getInstance()->changeScene(PANTALLA_JUE);
	}
	else if (Tecla->isKeyDown(DOS))
	{
		Selector->setSeleccion(2);
		ResourceManager::getInstance()->removeGraphic("../images/gauntlet.png");
		SceneDirector::getInstance()->changeScene(PANTALLA_JUE);
	}
	else if (Tecla->isKeyDown(TRES))
	{
		Selector->setSeleccion(3);
		ResourceManager::getInstance()->removeGraphic("../images/gauntlet.png");
		SceneDirector::getInstance()->changeScene(PANTALLA_JUE);
	}
	else if (Tecla->isKeyDown(CUATRO))
	{
		Selector->setSeleccion(4);
		ResourceManager::getInstance()->removeGraphic("../images/gauntlet.png");
		SceneDirector::getInstance()->changeScene(PANTALLA_JUE);
	}
	
}

void ScenePantallaIni::render()
{
	video::getInstance()->renderGraphic(CargaImagen, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);//Pinto el fondo con los graficos(imagenes)

}
