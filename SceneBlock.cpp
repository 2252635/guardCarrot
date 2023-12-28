#include"SceneBlock.h"
void SceneBlock::init(BlockType type, const std::string& fileName)
{
	myBlock = Sprite::create(fileName);
	label = type;
}
SceneBlock::~SceneBlock()
{
	CC_SAFE_RELEASE_NULL(myBlock);
}