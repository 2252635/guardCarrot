#ifndef _STARTGAME_SCENE_H_
#define _STARTFAME_SCENE_H_

#include "LevelManage.h"

class StartGame : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuStartCallBack(cocos2d::Ref* pSender);
	void menuEndCallBack(cocos2d::Ref* pSender);
	void menuHelpCall(cocos2d::Ref* pSender);
	void menuMusic(cocos2d::Ref* pSender);

	CREATE_FUNC(StartGame);

private:
	void onMouseDown(Event* event);

	bool isMusicPlaying = true;

	MenuItemImage* musicItem;
};

#endif 
