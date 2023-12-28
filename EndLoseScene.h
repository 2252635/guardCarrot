#ifndef __ENDLOSE_SCENE_H__
#define __ENDLOSE_SCENE_H__

#include "cocos2d.h"

class EndLoseScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuConCallBack(cocos2d::Ref* pSender);

	CREATE_FUNC(EndLoseScene);

};

#endif 