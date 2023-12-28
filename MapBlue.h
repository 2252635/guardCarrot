#pragma once
#ifndef _CARROT_MAP_BLUE_
#define _CARROT_MAP_BLUE_

#include"SceneBlock.h"
#include"PublicDefine.h"
#include "GameManager.h"

class MapBlue :public Scene
{
private:
	Vector<SceneBlock*> road;

	Vector<SceneBlock*> block;

	BlockType mapBoard[MAP_ROW][MAP_COL];

	Vec2 mousePosition;

	GameManager* gameManager;

public:
	static Scene* createScene();

	void layout();

	bool init();

	void setBarrier();

	CREATE_FUNC(MapBlue);

};
#endif

