#pragma once
#include "2d/CCMenu.h"
USING_NS_CC;
class TowerMenu:public Menu
{
	auto normalSprite = Sprite::create("buttonNormal.png"); // 正常状态的图像
	auto selectedSprite = Sprite::create("buttonSelected.png"); // 选中状态的图像
	auto disabledSprite = Sprite::create("buttonDisabled.png"); // 禁用状态的图像

};