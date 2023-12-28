#include"SceneBlock.h"

void SceneBlock::init(BlockType type, std::string& fileName)
{
	myBlock = Sprite::create(fileName);
	label = type;
}
SceneBlock::~SceneBlock()
{
	CC_SAFE_RELEASE_NULL(myBlock);
}