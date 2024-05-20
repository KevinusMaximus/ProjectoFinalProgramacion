#pragma once

#include <iostream>
#include <string>
#include "tinyxml2.h"
#include "video.h"

#include"Tileset.h"

#define NUM_CAPAS 2
class CargarMapas
{
	int _width;
	int _height;
	int _tileWidth;
	int _tileHeight;

	std::vector <int> Layers[NUM_CAPAS];

	Tileset _tiles;


	int _CamaraX;
	int _CamaraY;

public:
	CargarMapas();
	~CargarMapas();

	// Carga XML i dades als parametres de clase. Llegeix el Mapa
	int loadMap(const char* filename); // Retorna cero si tot ha anat b�

	void render();
	bool isTileSolid(int x, int y);
	int getWidth() { return _width; };
	int getTileWidth() { return _tileWidth; };
	int getHeight() { return _height; };
	int getTileHeight() { return _tileHeight; };

	void setCameraPosition(int x, int y);
};