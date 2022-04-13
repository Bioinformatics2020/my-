#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<ctime>
#include<iomanip>
#include<sstream>
#include"set.h"

class Date
{
private:
	
	SetDate &set;
	std::string tFormat;
	tm getTime(std::string & str);//stringתtm
	void deff(tm &time1, tm &time2);//tm1 tm2֮��ľ���ֵ��������time1
	int tmToDay(tm &time);//��tm����
	int tmToSecond(tm &time);//��tm����
	void print1582_10_11_12(std::ostream &calOut);//���1582�������������(ʮ��)����
public:
	std::string sign();
	Date(SetDate &set):set(set)
	{
		tFormat = set.set["dateFormat"]+ " " + set.set["timeFormat"];
	}
	std::string getNow();//��ȡ����ʱ��
	std::string diffTime(std::string &str1, std::string &str2);//�����ڼ��
	void put_cal(int year, std::ostream &calOut);//�����������
	std::string changeTime(std::string &str1, std::string &str2, bool is_add);//���ڼӼ�����
};

