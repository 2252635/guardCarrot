//#include"TowerMenu.h"
//#include"PublicSourceDefine.h"
//
//void TowerMenu::showTowerSelectMenu(const Vec2& position,std::string&bottleTower,std::string&starTower,std::string&shitTower ) {
//
//    // 创建防御塔选项
//    auto towerOption1 = MenuItemImage::create(bottleTower, BOTTLECANBUY, CC_CALLBACK_1(TowerMenu::onTowerSelected, this, TowerType::BOTTLE,position));
//    auto towerOption2 = MenuItemImage::create(starTower, STARCANBUY, CC_CALLBACK_1(TowerMenu::onTowerSelected, this, TowerType::STAR,position));
//    auto towerOption3 = MenuItemImage::create(shitTower, SHITCANBUY, CC_CALLBACK_1(TowerMenu::onTowerSelected, this, TowerType::SHIT,position));
//
//    /*menu->addChild(towerOption1);
//    menu->addChild(towerOption2);
//    menu->addChild(towerOption3);*/
//    menu = Menu::create(towerOption1, towerOption2, towerOption3, nullptr);
//   /* this->addChild(menu);*/
//    // 在 MenuItemImage 创建时使用不同的图片来表示不同状态
//
//    auto cancelOption = MenuItemImage::create(
//        "cancel_normal.png",
//        "cancel_selected.png",
//        "cancel_disabled.png",
//        [this](Ref* sender) {
//            // 移除菜单
//            this->removeChildByTag(kTowerSelectMenuTag);
//        }
//    );
//
//    // 设置取消选项的位置（可根据需要调整）
//    cancelOption->setPosition(Vec2(0, -50));
//
//    menu->addChild(cancelOption);
//
//    // 设置菜单的位置和标签
//    menu->setPosition(position);
//    menu->setTag(kTowerSelectMenuTag);
//    this->addChild(menu);
//}
//
//void TowerMenu::onTowerSelected(Ref* sender,TowerType type,Vec2 pos) {
//    // 从 sender 获取菜单项和菜单
//    auto menuItem = dynamic_cast<MenuItem*>(sender);
//    auto menu = menuItem->getParent();
//
//    // 移除菜单
//    menu->removeFromParentAndCleanup(true);
//    TowerManager::addTower(type, pos);
//}

