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
	
	if (KeyManager::getInstance()->isKeyDown(ABAJO))
	{
		ResourceManager::getInstance()->removeGraphic("../images/gauntlet.png");
		SceneDirector::getInstance()->changeScene(PANTALLA_JUE);
		
	}
	
	
	
	
}

void ScenePantallaIni::render()
{
	video::getInstance()->renderGraphic(CargaImagen, 0, 0, 600, 400);//Pinto el fondo con los graficos(imagenes)

}
