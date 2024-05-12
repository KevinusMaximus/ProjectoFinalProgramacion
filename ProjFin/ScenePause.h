#pragma once
#include<iostream>
#include"Scene.h"
class ScenePause:
	public Scene
{
public:
	ScenePause();
	~ScenePause();
	void init();
	void update();
	void render();
};

