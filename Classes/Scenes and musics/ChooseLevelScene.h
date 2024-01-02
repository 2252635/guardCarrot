#ifndef __CHOOSE_SCENER_H__
#define __CHOOSE_SCENER_H__

#include "LevelManage.h"

class ChooseLevelScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuStartCallBackOne(cocos2d::Ref* pSender);

	void menuStartCallBackTwo(cocos2d::Ref* pSender);

	void menuStay(cocos2d::Ref* pSender);

	CREATE_FUNC(ChooseLevelScene);

};

#endif
