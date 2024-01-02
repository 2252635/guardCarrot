#include"SceneBlock.h"

void SceneBlock::init(BlockType type)
{
	switch (type) {
	case ROAD:
		myBlock = Sprite::create("pictures/items/BlueRoad.png");
		myBlock->setScale(1.075);
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