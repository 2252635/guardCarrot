#include "LevelConfigUtil.h"
#include "../cocos2d/external/tinyxml2/tinyxml2.h"
#include "CsvUtil.h"
#include "SceneManager.h"
using namespace tinyxml2;//�����ĵ�����Ŀ�

LevelConfigUtil* LevelConfigUtil::Instance;//������ָ̬��洢ʵ��

LevelConfigUtil::LevelConfigUtil()
{
}

LevelConfigUtil::~LevelConfigUtil()
{
    CC_SAFE_DELETE(EffectTowers);//ɾ��EffectTowers
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

void LevelConfigUtil::LoadLevelConfig()//���عؿ�������Ϣ
{
    EffectTowers->clear();//�������vector

    tinyxml2::XMLDocument XmlDoc;//����XML�ĵ�

    //����XML�ļ�
    //����ǰ�׿ƽ̨
    //ʹ��FileUtils��ȡ�ļ����ݣ���ͨ��tinyxml2::XMLDocument����XML
    if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) {

        tinyxml2::XMLError Error;//���ڴ洢������Ϣ
        std::string FileName = LEVELCONFIGFILENAME;//��ȡ�ļ���
        unsigned char* Buffer = NULL;
        FileUtils::getContents(FileName, Buffer);//��ȡ�ļ�
        if (Buffer)//�����ȡ�ɹ�
            Error = XmlDoc.Parse((const char*)Buffer);//�����ĵ����洢���������еĴ�����Ϣ
        else
            CCLOG("[%d]%s %s error ", __LINE__, __func__, __FILE__);//���������Ϣ
            return;
    }

    else {//����ƽ̨
        //��ȡ�ļ�·��
        auto FileName = FileUtils::getInstance()->fullPathForFilename(LEVELCONFIGFILENAME);
        //�����ļ���������·���е�λ�ò��洢����
        auto Index = FileName.find(LEVELCONFIGFILENAME);
        //��ȡ�ļ���֮ǰ�Ĳ��֣��õ��ļ����ڵ�Ŀ¼
        FileName = FileName.substr(0, Index);

        //�洢�ļ���
        auto File = LEVELCONFIGFILENAME;
        //�����־
        CCLOG("[1]config %s  %s %s", LEVELCONFIGFILENAME.c_str(), FileName.c_str(), ((std::string)File).c_str());
        FileName = FileName + File;//��ȡ�������ļ�·��
        CCLOG("[2]config %s  %s %s", LEVELCONFIGFILENAME.c_str(), FileName.c_str(), ((std::string)File).c_str());
        //�����ļ�
        XmlDoc.LoadFile(FileName.c_str());
    }
    

    //��ȡ�ĵ��ĸ�Ԫ��
    auto Root = XmlDoc.RootElement();
    //��ȡ���������ʵ��
    auto MySceneManager = SceneManager::getInstance();
    //�ҵ���Ӧҳ�͹ؿ��е�Ԫ��
    auto LevelElement = Root->FirstChildElement(StringUtils::format("%d_%02d", MySceneManager->getCurPageIndex() + 1, MySceneManager->getCurLevelIndex() + 1).c_str());
    //��ȡ��һ����Ԫ��
    auto Element = LevelElement->FirstChildElement();

    while (Element)//�����ؿ�Ԫ���е���Ԫ��
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
        {//��ȡ��һ��Ԫ��
            auto Tower = Element->FirstChildElement();

            while (Tower)
            {//������������һ��ӵ�EffectTowers��
                EffectTowers->push_back(Tower->Name());
                Tower = Tower->NextSiblingElement();
            }
            return;
        }
        Element = Element->NextSiblingElement();//��ȡ�ؿ��е���һ��Ԫ��
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
    auto MyCsvUtil = CsvUtil::GetInstance();//��ȡCsv�ļ�
    MyCsvUtil->AddFilePath(LEVELCSVFILE);

    auto ColumnRowCount = MyCsvUtil->GetRowAndCol(LEVELCSVFILE);//��ȡ����������
    //��������������
    auto Column = std::get<0>(ColumnRowCount);
    auto Row = std::get<1>(ColumnRowCount);
    //����XML�ļ�
    auto Xmldoc = new tinyxml2::XMLDocument;

    auto LevelConfigRoot = Xmldoc->NewElement(LEVELCONFIGROOT.c_str());//�����µ�XMLԪ��
    Xmldoc->LinkEndChild(LevelConfigRoot);//��Ӹ�Ԫ�ص�XML�ĵ���

    for (int i = 1; i < Row; ++i)//���б���Csv�ļ�
    {

        auto ColumnCount = 0;
        auto ThemeIndex = MyCsvUtil->GetInt(i, 0, LEVELCSVFILE);//��ȡ�����Ӧ������
        auto LevelIndex = MyCsvUtil->GetInt(i, 1, LEVELCSVFILE);//��ȡ�ؿ���Ӧ������
        //������Ԫ��
        auto LevelElement = Xmldoc->NewElement(StringUtils::format("%d_%02d", ThemeIndex, LevelIndex).c_str());
        LevelConfigRoot->LinkEndChild(LevelElement);//����Ԫ����ӵ�XML�ĵ��ĸ�Ԫ����
        for (int j = 0; j < 4; ++j)//���б���
        {
            auto Element = Xmldoc->NewElement(LEVELCONFIGTYPE[j].c_str());//������Ԫ�ر�ʾ��ǰ�е�����
            auto Value = MyCsvUtil->GetInt(i, j, LEVELCSVFILE);//��ȡ��Ӧλ�õ�ֵ
            Element->SetAttribute(LEVELCONFIGTYPE[j].c_str(), StringUtils::format("%d", Value).c_str());//��������
            LevelElement->LinkEndChild(Element);//���
            ColumnCount = j;
        }
        ++ColumnCount;//������һ��
        auto TowerElement = Xmldoc->NewElement(TOWERTYPE.c_str());//��ȡ�������Ͳ���ӵ�XML�ĵ���
        LevelElement->LinkEndChild(TowerElement);
        for (; ColumnCount < Column; ++ColumnCount)//
        {

            auto Value = MyCsvUtil->GetInt(i, ColumnCount, LEVELCSVFILE);//��ȡ��Ӧ�е�ֵ
            if (Value==1)//�����Ԫ���ֵΪ1����ʾ�����͵�������
            {
                auto Element = Xmldoc->NewElement(LEVELCONFIGTYPE[ColumnCount].c_str());//����Ԫ��
                TowerElement->LinkEndChild(Element);//���
            }
        }
    }

    Xmldoc->SaveFile((FileUtils::getInstance()->getWritablePath() + "LevelConfig.xml").c_str());//����XML�ĵ�
    MyCsvUtil->ReleaseFile(LEVELCSVFILE);//�ͷ�Csv�ļ�
    delete Xmldoc;//�ͷŴ������ĵ�
}