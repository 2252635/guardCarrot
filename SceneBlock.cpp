#include"SceneBlock.h"

void SceneBlock::init(BlockType type,int color)
{
	switch (type) {
	case ROAD:
		if (color == 1)
			myBlock = Sprite::create("pictures/items/BlueRoad.png");
		else
			myBlock = Sprite::create("pictures/items/PurpleRoad.png");
		myBlock->setScale(1.5);
		break;
	default:
		myBlock = Sprite::create("pictures/items/Block.png");
		myBlock->setScale(1.0);
		break;
	}
	set_label(type);
}
SceneBlock::~SceneBlock()
{
	CC_SAFE_RELEASE_NULL(myBlock);
}