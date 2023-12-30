#ifndef __HELP_SCENE_H__
#define __HELP_SCENE_H__

#include "GameScene.h"

class HelpScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuCallBack(cocos2d::Ref* pSender);
	void menuReturn(cocos2d::Ref* pSender);
	void menuMusic(cocos2d::Ref* pSender);

	CREATE_FUNC(HelpScene);
private:
	bool isMusicPlaying = true;

	MenuItemImage* musicItem;

};

#endif 

