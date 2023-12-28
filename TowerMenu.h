<<<<<<< HEAD
#pragma once
#include "2d/CCMenu.h"
USING_NS_CC;
class TowerMenu:public Menu
{
	auto normalSprite = Sprite::create("buttonNormal.png"); // Õı³£×´Ì¬µÄÍ¼Ïñ
	auto selectedSprite = Sprite::create("buttonSelected.png"); // Ñ¡ÖĞ×´Ì¬µÄÍ¼Ïñ
	auto disabledSprite = Sprite::create("buttonDisabled.png"); // ½ûÓÃ×´Ì¬µÄÍ¼Ïñ
=======
#include "2d/CCMenu.h"
#include"cocos2d.h"
#include"TowerManager.h"
USING_NS_CC;
class TowerMenu :public Menu
{
    static const int kTowerSelectMenuTag = 10;

public:

    void showTowerSelectMenu(const Vec2& position, std::string& bottleTower, std::string& starTower, std::string& shitTower);
    void onTowerSelected(Ref* sender,TowerType type,Vec2 pos);
>>>>>>> 3cc07b4 (lyy2)

};