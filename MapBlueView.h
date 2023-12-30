#ifndef __MapBlueView_SCENE_H__
#define __MapBlueView_SCENE_H__

#include "GameScene.h"

class MapBlueView : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuStartCallBack(cocos2d::Ref* pSender);
	void menuReturnCallBack(cocos2d::Ref* pSender);
	void menuTranCallBack(cocos2d::Ref* pSender);
	void menuMusic(cocos2d::Ref* pSender);

	CREATE_FUNC(MapBlueView);

private:
	bool isMusicPlaying = true;

	MenuItemImage* musicItems;
	

};

#endif 

