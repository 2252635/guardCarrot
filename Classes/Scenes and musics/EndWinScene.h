#ifndef __ENDWIN_SCENE_H__
#define __ENDWIN_SCENE_H__

#include "LevelManage.h"


class EndWinScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuConCallBack(cocos2d::Ref* pSender);

	CREATE_FUNC(EndWinScene);

};

#endif 
