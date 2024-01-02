#ifndef _LEVEL_MANAGE_H_
#define _LEVEL_MANAGE_H_

#include "GameScene.h"

class LevelManager 
{
public:
	void startGame();

	int returnCurrentLevel();

	void unlockedNextLevel();

	static LevelManager* getInstance();

	LevelManager();

private:
	int currentLevel;

};

#endif
