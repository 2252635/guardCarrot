#include"CsvUtil.h"

String1 FileLoadUtil::GetDataLines(const std::string&Src)
{
	String1 DataList;
	if (!cocos2d::FileUtils::getInstance()->isFileExist(Src))//�ļ�������
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
    String1 StringList;//��ʼ��װ���ַ�����һάVector

    int Size = Src.size();//ȷ����С

    std::string Str(Src);//��ԭ������ʼ��һ���µ�string����Str���ڽ����޸Ĳ���

    int Start = 0;

    int End = 0;

    End = Str.find(SubStr);//��������Ѱ���Ӵ���һ�γ��ֵ�λ��

    std::string SplitStr = "";

    while (End > 0)
    {
        SplitStr = Str.substr(Start, End);//��SplitStr���մ���������ȡ�����Ӵ�

        StringList.push_back(SplitStr);//�����Ӵ���������б�

        Str = std::string(Str.substr(End + 1, Size));//����StrΪɾ��SplitStr֮��Ĳ���

        End = Str.find(SubStr);//Ѱ����һ���Ӵ���λ��
    }

    if (Str != "") {
        StringList.push_back(Str);
    }
    return StringList;
}
CsvUtil::CsvUtil()//����Csv��map����ռ�
{
	MapPtr = new CsvMap;
}
CsvUtil::~CsvUtil()//��ȫ�ͷſռ�
{
	CC_SAFE_DELETE(MapPtr);
}
CsvUtil* CsvUtil::GetInstance()
{
	if (!Instance)//��ǰʵ��Ϊ��
		Instance = new CsvUtil;//�����µĶ���
	return Instance;//���ظ�ʵ����ַ
}
bool CsvUtil::DestructInstance()//����ʵ��
{
	if (Instance) {//ʵ����Ϊ��
		CC_SAFE_DELETE(Instance);//�ͷ���ռ�õĿռ�
		return true;
	}
	return false;
}

void CsvUtil::AddFilePath(std::string& Src)
{
	if (Src == "")//·��Ϊ��
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
