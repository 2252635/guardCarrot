#pragma once
#include "2d/CCMenu.h"
USING_NS_CC;
class TowerMenu:public Menu
{
	auto normalSprite = Sprite::create("buttonNormal.png"); // ����״̬��ͼ��
	auto selectedSprite = Sprite::create("buttonSelected.png"); // ѡ��״̬��ͼ��
	auto disabledSprite = Sprite::create("buttonDisabled.png"); // ����״̬��ͼ��

};