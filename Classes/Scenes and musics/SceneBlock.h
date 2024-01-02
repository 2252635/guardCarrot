#pragma once
#ifndef _CARROT_SCENE_BLOCK_
#define _CARROT_SCENE_BLOCK_
#include"Entity.h"
class SceneBlock :public Entity
{
private:
	Sprite* myBlock;
public:
	void init(BlockType type);
	Sprite* getBlock() { return myBlock; };
	
	~SceneBlock();
	CC_SYNTHESIZE_PASS_BY_REF(Vec2, pos, Pos);
	CC_SYNTHESIZE_PASS_BY_REF(BlockType, label, _label);
};
#endif
