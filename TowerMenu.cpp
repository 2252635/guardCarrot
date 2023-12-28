#include"TowerMenu.h"

void TowerMenu::showTowerSelectMenu(const Vec2& position,std::string&bottleTower,std::string&starTower,std::string&shitTower ) {
    auto menu = Menu::create();

    // ����������ѡ��
    auto towerOption1 = MenuItemImage::create(bottleTower, "BottleSelected.png", CC_CALLBACK_1(TowerMenu::onTowerSelected, this, TowerType::BOTTLE,position));
    auto towerOption2 = MenuItemImage::create(starTower, "StarSelected.png", CC_CALLBACK_1(TowerMenu::onTowerSelected, this, TowerType::STAR,position));
    auto towerOption3 = MenuItemImage::create(shitTower, "ShitSelected.png", CC_CALLBACK_1(TowerMenu::onTowerSelected, this, TowerType::SHIT,position));

    menu->addChild(towerOption1);
    menu->addChild(towerOption2);
    menu->addChild(towerOption3);

    this->addChild(menu);
    // �� MenuItemImage ����ʱʹ�ò�ͬ��ͼƬ����ʾ��ͬ״̬

    auto cancelOption = MenuItemImage::create(
        "cancel_normal.png",
        "cancel_selected.png",
        "cancel_disabled.png",
        [this](Ref* sender) {
            // �Ƴ��˵�
            this->removeChildByTag(kTowerSelectMenuTag);
        }
    );

    // ����ȡ��ѡ���λ�ã��ɸ�����Ҫ������
    cancelOption->setPosition(Vec2(0, -50));

    menu->addChild(cancelOption);

    // ���ò˵���λ�úͱ�ǩ
    menu->setPosition(position);
    menu->setTag(kTowerSelectMenuTag);
    this->addChild(menu);
}

void TowerMenu::onTowerSelected(Ref* sender,TowerType type,Vec2 pos) {
    // �� sender ��ȡ�˵���Ͳ˵�
    auto menuItem = dynamic_cast<MenuItem*>(sender);
    auto menu = menuItem->getParent();

    // �Ƴ��˵�
    menu->removeFromParentAndCleanup(true);
    TowerManager::addTower(type, pos);
}

