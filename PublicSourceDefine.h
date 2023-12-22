#pragma once
//�洢��Ŀ�������ļ�������
#ifndef _PUBLIC_SOURCE_DEFINE_
#define _PUBLIC_SOURCE_DEFINE_

const static std::string TOWERCSVFILE = "csv/Tower.csv";//������
const static std::string BACKGROUNDSOUND = "Music/Main/BGMusic.mp3";//��������
const static std::string BUILDTOWER = "Music/Items/TowerBulid.mp3";//�������������Ч
const static std::string UPGRADETOWER = "Music/Items/TowerUpdata.mp3";
const static std::string SELLTOWER = "Music/Items/TowerSell.mp3";
const static std::string SELECTFAULT = "Music/Items/SelectFault.mp3";

const static std::string LEVELCSVFILE = "csv/Level.csv";
const static std::string BARRIERCSVFILE = "csv/Barrier.csv";

const static std::string LEVELCONFIGFILENAME = "level/LevelConfig.xml";
const static std::string LEVELCONFIGROOT = "LevelConfigRoot";
const static std::string TOWERTYPE = "TowerType";
const static std::vector<std::string> LEVELCONFIGTYPE =
{
    "ThemeIndex",//����
    "Level",//�ؿ�
    "Money",//���
    "MonsterBatch",
    "Star",
    "Sun1",
    "Rocket"
};
const static std::vector<std::string> TOWERS =
{
    "Themes/Towers/TStar-hd",
    "Themes/Towers/TPin-hd",
    "Themes/Towers/TRocket-hd"
};
#define LEVELDATACHANGE "levelDataChange"
#endif
