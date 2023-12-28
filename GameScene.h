#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"

class SceneFactory: public cocos2d::Scene
{
public:

    static Scene* createScene(int Level);
};

#endif

