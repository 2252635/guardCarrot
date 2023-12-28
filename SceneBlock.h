#pragma once
#ifndef _CARROT_SCENE_BLOCK_
#define _CARROT_SCENE_BLOCK_
#include"PublicDefine.h"
class SceneBlock :public Node
{
private:
	int label;
	Sprite* myBlock;
	Vec2 position;
public:
	void init(BlockType type, const std::string& fileName);
	Sprite* getBlock() { return myBlock; };
	int getLabel() { return label; };
	Vec2 getPos() { return position; };
	~SceneBlock();
};
#endif