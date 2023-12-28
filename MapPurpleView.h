#ifndef __MapPurpleView_SCENE_H__
#define __MapPurpleView_SCENE_H__

#include "cocos2d.h"

class MapPurpleView : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuStartCallBack(cocos2d::Ref* pSender);

	void menuReturnCallBack(cocos2d::Ref* pSender);

	void menuTranCallBack(cocos2d::Ref* pSender);

	CREATE_FUNC(MapPurpleView);

};

#endif 
