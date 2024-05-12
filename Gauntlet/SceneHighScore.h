#pragma once
#include<iostream>
#include"Scene.h"
class SceneHighScore:
	public Scene
{
public:
	SceneHighScore();
	~SceneHighScore();
	void init();
	void update();
	void render();
};

