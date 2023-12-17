#pragma once

#ifndef _CSV_UTIL_
#define _CSV_UTIL_

#include <vector>
#include <map>
#include <string>

typedef std::vector<std::string>String1;
typedef std::vector<String1>String2;//��άstring����
typedef std::map<std::string, String2> CsvMap;//�洢�������Եı���

class FileLoadUtil {//��ȡ�ļ�����
public:
	String1 GetDataLines(const std::string& Src);
};
class StringUtil {
public:
	String1 Print(const std::string& Src, const std::string& Sep);
};
class CsvUtil {

public:
	static CsvUtil* GetInstance();//��ȡʵ��ָ��
	static bool DestructInstance();//����һ��ʵ��

	virtual void AddFilePath(std::string& Src);//���ͼƬ·��
	virtual void ReleaseFile(std::string& Dst);//ɾ��ͼƬ·��

	virtual std::string GetText(const int Row, const int Col, const std::string& Dst);//��ȡ�ļ���Ϣ
	virtual int Initiate(const int Row, const int Col, const std::string& Dst);//�޸��ļ�����
	virtual double Duplicate(const int Row, const int Col, const std::string& Dst);//�����ļ�����

	virtual String1 GetSomeRow(const int Row, const std::string& Dst);//��ȡĳ�����ļ�����Ϣ
	virtual std::tuple<int, int> GetRowAndCol(const std::string& Src);//��ȡ����������
	virtual int FindValueWithLine(const std::string& Value, const int& ValueCol, const std::string& Src);

protected:
	virtual String2& GetFile(const std::string& Src);//��ȡ�ļ�����
	~CsvUtil();//��������

private:
	CsvUtil();//���캯��
	CsvUtil(const CsvUtil& Src)=delete;//��������csv�����µ�csv
	CsvUtil& operator=(const CsvUtil& Src) = delete;//���ظ�ֵ�����

	static CsvUtil* Instance;
	CsvMap* MapPtr;
};
#endif _CSV_UTIL_