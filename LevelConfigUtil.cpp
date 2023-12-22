#include "LevelConfigUtil.h"
#include "../cocos2d/external/tinyxml2/tinyxml2.h"
#include "CsvUtil.h"
#include "SceneManager.h"
using namespace tinyxml2;//引入文档处理的库

LevelConfigUtil* LevelConfigUtil::Instance;//声明静态指针存储实例

LevelConfigUtil::LevelConfigUtil()
{
}

LevelConfigUtil::~LevelConfigUtil()
{
    CC_SAFE_DELETE(EffectTowers);//删除EffectTowers
}


bool LevelConfigUtil::Initiate()
{

    bool Ret = false;

    do
    {
        EffectTowers = new std::vector<std::string>;

        Ret = true;
    } while (0);

    return Ret;

}

void LevelConfigUtil::LoadLevelConfig()//加载关卡配置信息
{
    EffectTowers->clear();//清空塔的vector

    tinyxml2::XMLDocument XmlDoc;//创建XML文档

    //解析XML文件
    //如果是安卓平台
    //使用FileUtils读取文件数据，并通过tinyxml2::XMLDocument解析XML
    if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) {

        tinyxml2::XMLError Error;//用于存储错误信息
        std::string FileName = LEVELCONFIGFILENAME;//获取文件名
        unsigned char* Buffer = NULL;
        FileUtils::getContents(FileName, Buffer);//读取文件
        if (Buffer)//如果读取成功
            Error = XmlDoc.Parse((const char*)Buffer);//解析文档并存储解析过程中的错误信息
        else
            CCLOG("[%d]%s %s error ", __LINE__, __func__, __FILE__);//输出错误信息
            return;
    }

    else {//其他平台
        //获取文件路径
        auto FileName = FileUtils::getInstance()->fullPathForFilename(LEVELCONFIGFILENAME);
        //查找文件名在完整路径中的位置并存储索引
        auto Index = FileName.find(LEVELCONFIGFILENAME);
        //截取文件名之前的部分，得到文件所在的目录
        FileName = FileName.substr(0, Index);

        //存储文件名
        auto File = LEVELCONFIGFILENAME;
        //输出日志
        CCLOG("[1]config %s  %s %s", LEVELCONFIGFILENAME.c_str(), FileName.c_str(), ((std::string)File).c_str());
        FileName = FileName + File;//获取完整的文件路径
        CCLOG("[2]config %s  %s %s", LEVELCONFIGFILENAME.c_str(), FileName.c_str(), ((std::string)File).c_str());
        //加载文件
        XmlDoc.LoadFile(FileName.c_str());
    }
    

    //获取文档的根元素
    auto Root = XmlDoc.RootElement();
    //获取场景管理的实例
    auto MySceneManager = SceneManager::getInstance();
    //找到对应页和关卡中的元素
    auto LevelElement = Root->FirstChildElement(StringUtils::format("%d_%02d", MySceneManager->getCurPageIndex() + 1, MySceneManager->getCurLevelIndex() + 1).c_str());
    //获取第一个子元素
    auto Element = LevelElement->FirstChildElement();

    while (Element)//遍历关卡元素中的子元素
    {
        if (LEVELCONFIGTYPE[0] == Element->Name())
            CurPageIndex = Element->IntAttribute(LEVELCONFIGTYPE[0].c_str());
        if (LEVELCONFIGTYPE[1] == Element->Name())
            CurLevelIndex = Element->IntAttribute(LEVELCONFIGTYPE[1].c_str());
        if (LEVELCONFIGTYPE[2] == Element->Name())
            CurLevelMoney = Element->IntAttribute(LEVELCONFIGTYPE[2].c_str());
        if (LEVELCONFIGTYPE[3] == Element->Name())
            MonsterBatchCount = Element->IntAttribute(LEVELCONFIGTYPE[3].c_str());


        if (Element->Name()==TOWERTYPE)
        {//获取第一个元素
            auto Tower = Element->FirstChildElement();

            while (Tower)
            {//将塔的名字逐一添加到EffectTowers中
                EffectTowers->push_back(Tower->Name());
                Tower = Tower->NextSiblingElement();
            }
            return;
        }
        Element = Element->NextSiblingElement();//获取关卡中的下一个元素
    }
}

std::tuple<int, int, int, std::vector<std::string>> LevelConfigUtil::GetLevelConfig()const
{
    return std::make_tuple(CurPageIndex, CurLevelIndex, MonsterBatchCount, *EffectTowers);
}

std::vector<std::string> LevelConfigUtil::GetCurLevelTowersInfo()const
{
    return *EffectTowers;
}

int LevelConfigUtil::GetCurLevelMonsterBatchCount()const
{
    return MonsterBatchCount;
}

int LevelConfigUtil::GetCurLevelMoney()const
{
    return CurLevelMoney;
}

void LevelConfigUtil::BuildLevelConfig()
{
    auto MyCsvUtil = CsvUtil::GetInstance();//获取Csv文件
    MyCsvUtil->AddFilePath(LEVELCSVFILE);

    auto ColumnRowCount = MyCsvUtil->GetRowAndCol(LEVELCSVFILE);//获取行数和列数
    //分离行数和列数
    auto Column = std::get<0>(ColumnRowCount);
    auto Row = std::get<1>(ColumnRowCount);
    //创建XML文件
    auto Xmldoc = new tinyxml2::XMLDocument;

    auto LevelConfigRoot = Xmldoc->NewElement(LEVELCONFIGROOT.c_str());//创建新的XML元素
    Xmldoc->LinkEndChild(LevelConfigRoot);//添加根元素到XML文档中

    for (int i = 1; i < Row; ++i)//逐行遍历Csv文件
    {

        auto ColumnCount = 0;
        auto ThemeIndex = MyCsvUtil->GetInt(i, 0, LEVELCSVFILE);//获取主题对应的整数
        auto LevelIndex = MyCsvUtil->GetInt(i, 1, LEVELCSVFILE);//获取关卡对应的整数
        //生成新元素
        auto LevelElement = Xmldoc->NewElement(StringUtils::format("%d_%02d", ThemeIndex, LevelIndex).c_str());
        LevelConfigRoot->LinkEndChild(LevelElement);//将新元素添加到XML文档的根元素中
        for (int j = 0; j < 4; ++j)//逐列遍历
        {
            auto Element = Xmldoc->NewElement(LEVELCONFIGTYPE[j].c_str());//创建新元素表示当前列的属性
            auto Value = MyCsvUtil->GetInt(i, j, LEVELCSVFILE);//获取对应位置的值
            Element->SetAttribute(LEVELCONFIGTYPE[j].c_str(), StringUtils::format("%d", Value).c_str());//设置属性
            LevelElement->LinkEndChild(Element);//添加
            ColumnCount = j;
        }
        ++ColumnCount;//跳到下一列
        auto TowerElement = Xmldoc->NewElement(TOWERTYPE.c_str());//获取塔的类型并添加到XML文档中
        LevelElement->LinkEndChild(TowerElement);
        for (; ColumnCount < Column; ++ColumnCount)//
        {

            auto Value = MyCsvUtil->GetInt(i, ColumnCount, LEVELCSVFILE);//获取对应列的值
            if (Value==1)//如果单元格的值为1，表示该类型的塔可用
            {
                auto Element = Xmldoc->NewElement(LEVELCONFIGTYPE[ColumnCount].c_str());//创建元素
                TowerElement->LinkEndChild(Element);//添加
            }
        }
    }

    Xmldoc->SaveFile((FileUtils::getInstance()->getWritablePath() + "LevelConfig.xml").c_str());//保存XML文档
    MyCsvUtil->ReleaseFile(LEVELCSVFILE);//释放Csv文件
    delete Xmldoc;//释放创建的文档
}