#include"CsvUtil.h"

String1 FileLoadUtil::GetDataLines(const std::string&Src)
{
	String1 DataList;
	if (!cocos2d::FileUtils::getInstance()->isFileExist(Src))//文件不存在
		return DataList;
	else {
		size_t Size = 0;

		StringUtil MyStringUtil;

		unsigned char* Datas = cocos2d::FileUtils::getInstance()->getFileData(Src, "r", &Size);

		if (Datas) 
			DataList = MyStringUtil.Print((char*)Datas, "\n");

		return DataList;
	}
}
String1 StringUtil::Print(const std::string& Src, const std::string& SubStr)
{
    String1 StringList;//初始化装载字符串的一维Vector

    int Size = Src.size();//确定大小

    std::string Str(Src);//用原主串初始化一个新的string，该Str用于进行修改操作

    int Start = 0;

    int End = 0;

    End = Str.find(SubStr);//从主串中寻找子串第一次出现的位置

    std::string SplitStr = "";

    while (End > 0)
    {
        SplitStr = Str.substr(Start, End);//用SplitStr接收从主串中提取到的子串

        StringList.push_back(SplitStr);//将该子串放入输出列表

        Str = std::string(Str.substr(End + 1, Size));//更新Str为删除SplitStr之后的部分

        End = Str.find(SubStr);//寻找下一个子串的位置
    }

    if (Str != "") {
        StringList.push_back(Str);
    }
    return StringList;
}
CsvUtil::CsvUtil()//给该Csv的map分配空间
{
	MapPtr = new CsvMap;
}
CsvUtil::~CsvUtil()//安全释放空间
{
	CC_SAFE_DELETE(MapPtr);
}
CsvUtil* CsvUtil::GetInstance()
{
	if (!Instance)//当前实例为空
		Instance = new CsvUtil;//创建新的对象
	return Instance;//返回该实例地址
}
bool CsvUtil::DestructInstance()//销毁实例
{
	if (Instance) {//实例不为空
		CC_SAFE_DELETE(Instance);//释放其占用的空间
		return true;
	}
	return false;
}

void CsvUtil::AddFilePath(std::string& Src)
{
	if (Src == "")//路径为空
		return;
	else {
        FileLoadUtil MyFileLoadUtil;
        auto LinesVec = MyFileLoadUtil.GetDataLines(Src);
        String1 StrsVec;
        String2 StrsVecVec;
        StringUtil MyStringUtil;

        for (const auto& CurrentLine : LinesVec)
        {
            StrsVec = MyStringUtil.Print(CurrentLine.c_str(), ",");
            StrsVecVec.push_back(StrsVec);
        }
        MapPtr->insert(std::make_pair(std::string(Src), StrsVecVec));
	}
}
void CsvUtil::ReleaseFile(std::string& Dst)
{
    MapPtr->erase(Dst);
}
std::tuple<int, int> CsvUtil::GetRowAndCol(const std::string& Src)
{
    auto Dict = GetFile(Src);
    int Row = Dict.size();
    int Col = (*(Dict.begin())).size();
    return std::make_tuple(Col, Row - 1);
}
std::string CsvUtil::GetText(const int Row, const int Col, const std::string& Dst)
{
    const auto Dict = GetFile(Dst);

    const auto LineDatas = Dict.at(Row);

    return LineDatas.at(Col);
}

int CsvUtil::Initiate(const int Row, const int Col, const std::string& Dst)
{
    return atoi(GetText(Row, Col, Dst).c_str());
}

double CsvUtil::Duplicate(const int Row, const int Col, const std::string& Dst)
{
    return atof(GetText(Row, Col, Dst).c_str());
}

String1 CsvUtil::GetSomeRow(const int Row, const std::string& Dst)
{
    auto CurrentRow = std::get<1>(GetRowAndCol(Dst));

    if (Row > CurrentRow) return String1();

    return  MapPtr->at(Dst).at(Row);
}
String2& CsvUtil::GetFile(const std::string& Src)
{
    return MapPtr->at(Src);
}
int CsvUtil::FindValueWithLine(const std::string& Value, const int& ValueCol, const std::string& Src)
{
    auto RowCount = std::get<1>(GetRowAndCol(Src));

    auto Ret = -1;
    std::string FindValue(Value);

    for (int i = 0; i < RowCount; ++i)
    {
        std::string TmpValue = GetText(i, ValueCol, Src);
        if (FindValue == TmpValue)
        {
            Ret=RowCount;
            break;
        }
    }
    return Ret;
}
