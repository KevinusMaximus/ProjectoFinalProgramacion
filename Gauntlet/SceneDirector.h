#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <vector>
#include "Scene.h"

//! Enum Scenes.
/*! All the Scenes in the game. */
enum SceneEnum {
		PANTALLA_INI, PANTALLA_JUE, PAUSE,HIGHSCORE, _LASTSCENE
};

#define NUM_SCENES _LASTSCENE

class SceneDirector
{
	public:
		~SceneDirector();

		void init();
		
		void changeScene(SceneEnum next_scene, bool reinit = true);

		SceneEnum getCurrSceneEnum(){return EscenaActual;};

		Scene* getCurrentScene(){return mVectorScenes[EscenaActual];};
		
		//! Gets pointer to instance
		static SceneDirector* getInstance();

	protected:
		SceneDirector();
		static SceneDirector*	pInstance;	/*!<  pointer instance*/

		std::vector<Scene*>	mVectorScenes;
		SceneEnum		EscenaActual;
};

#endif
