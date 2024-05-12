#include "SceneDirector.h"
#include "ScenePantallaIni.h"
#include "ScenePantallaJue.h"
#include "ScenePause.h"
#include "SceneHighScore.h"

SceneDirector* SceneDirector::pInstance = NULL;

SceneDirector* SceneDirector::getInstance(){
	if (!pInstance) {
		pInstance = new SceneDirector();
	}
	return pInstance;
}

SceneDirector::SceneDirector(){
	init();
}

SceneDirector::~SceneDirector(){
}

void SceneDirector::init(){
	mVectorScenes.resize(NUM_SCENES);

	ScenePantallaIni	*main		= new ScenePantallaIni();
	ScenePantallaJue	*juego	= new ScenePantallaJue();
	ScenePause	*pausa		= new ScenePause();
	SceneHighScore	*puntuacion		= new SceneHighScore();

	mVectorScenes[PANTALLA_INI] = main;
	mVectorScenes[PANTALLA_JUE] = juego;
	mVectorScenes[PAUSE] = pausa;
	mVectorScenes[HIGHSCORE] = puntuacion;

	main->init();
	juego->init();
	pausa->init();
	puntuacion->init();

	EscenaActual = PANTALLA_INI;
}

void SceneDirector::changeScene(SceneEnum next_scene, bool reinit){
	mVectorScenes[next_scene]->setReInit(reinit);
	EscenaActual = next_scene;
}
