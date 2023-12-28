#include "GameScene.h"
#include "MapBlueView.h"
#include "MapPurpleView.h"
#include "MapBlue.h"
#include "MapPurple.h"
#include "EndWinScene.h"
#include "EndLoseScene.h"
#include "ChooseLevelScene.h"
#include "PublicDefine.h"
#include "StartGameScene.h"

USING_NS_CC;

Scene* SceneFactory::createScene(int Level)
{
    Scene* pScene = nullptr;

    switch (Level)
    {
        case MAP_BLUE_VIEW:
            pScene = MapBlueView::createScene();
            break;
        case MAP_PURPLE_VIEW:
            pScene = MapPurpleView::createScene();
            break;
        case MAP_BLUE:
          
            break;
        case MAP_PURPLE:
          
            break;
        case END_WIN:
            pScene = EndWinScene::createScene();
            break;
        case END_LOSE:
            pScene = EndLoseScene::createScene();
            break;
        case START:
            pScene = StartGame::createScene();
            break;
        default:
            break;
    }
    return pScene;
}
