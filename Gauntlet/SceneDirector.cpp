#include "SceneDirector.h"

#include "ScenePantallaIni.h"
#include "ScenePantallaJue.h"
#include "ScenePause.h"
#include "SceneHighScore.h"
#include "SceneTypeHighScore.h"

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

	ScenePantallaIni	*main		= new SceneMain();
	ScenePantallaJue	*juego	= new SceneOptions();
	ScenePause	*pausa		= new SceneSaveLoad();
	SceneHighScore	*puntuacion		= new SceneIntro();
	SceneTypeHighScore* escribir_res = new SceneGameOver();

	mVectorScenes[PANTALLA_INI] = main;
	mVectorScenes[PANTALLA_JUE] = juego;
	mVectorScenes[PAUSE] = pausa;
	mVectorScenes[HIGHSCORE] = puntuacion;
	mVectorScenes[TYPE_HIGHSCORE] = escribir_res;

	main->init();
	juego->init();
	pausa->init();
	puntuacion->init();
	escribir_res->init();

	EscenaActual = PANTALLA_INI;
}

void SceneDirector::changeScene(SceneEnum next_scene, bool reinit){
	mVectorScenes[next_scene]->setReInit(reinit);
	EscenaActual = next_scene;
}
