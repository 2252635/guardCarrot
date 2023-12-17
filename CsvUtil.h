#pragma once

#ifndef _CSV_UTIL_
#define _CSV_UTIL_

#include <vector>
#include <map>
#include <string>

typedef std::vector<std::string>String1;
typedef std::vector<String1>String2;//二维string数组
typedef std::map<std::string, String2> CsvMap;//存储物体属性的变量

class FileLoadUtil {//读取文件的类
public:
	String1 GetDataLines(const std::string& Src);
};
class StringUtil {
public:
	String1 Print(const std::string& Src, const std::string& Sep);
};
class CsvUtil {

public:
	static CsvUtil* GetInstance();//获取实例指针
	static bool DestructInstance();//销毁一个实例

	virtual void AddFilePath(std::string& Src);//添加图片路径
	virtual void ReleaseFile(std::string& Dst);//删除图片路径

	virtual std::string GetText(const int Row, const int Col, const std::string& Dst);//读取文件信息
	virtual int Initiate(const int Row, const int Col, const std::string& Dst);//修改文件内容
	virtual double Duplicate(const int Row, const int Col, const std::string& Dst);//复制文件内容

	virtual String1 GetSomeRow(const int Row, const std::string& Dst);//读取某几行文件的信息
	virtual std::tuple<int, int> GetRowAndCol(const std::string& Src);//获取行数和列数
	virtual int FindValueWithLine(const std::string& Value, const int& ValueCol, const std::string& Src);

protected:
	virtual String2& GetFile(const std::string& Src);//获取文件内容
	~CsvUtil();//析构函数

private:
	CsvUtil();//构造函数
	CsvUtil(const CsvUtil& Src)=delete;//根据已有csv构造新的csv
	CsvUtil& operator=(const CsvUtil& Src) = delete;//重载赋值运算符

	static CsvUtil* Instance;
	CsvMap* MapPtr;
};
#endif _CSV_UTIL_