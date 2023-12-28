#ifndef _STARTGAME_SCENE_H_
#define _STARTFAME_SCENE_H_

#include "cocos2d.h"

class StartGame : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuStartCallBack(cocos2d::Ref* pSender);
	void menuEndCallBack(cocos2d::Ref* pSender);

	CREATE_FUNC(StartGame);

};

#endif 
