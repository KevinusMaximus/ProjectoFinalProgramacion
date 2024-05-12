#pragma once
#include<iostream>
#include"Scene.h"
#include"video.h"
#include <iostream>
#include"KeyManager.h"
#include"SceneDirector.h"
#include"CargarMapas.h"

class ScenePantallaIni : public Scene
{
private:
	
	Sint32 CargaImagen;
public:
	
	ScenePantallaIni();
	~ScenePantallaIni();
	void init();
	void update();
	void render();
};

