#pragma once
#include<string>
#include<vector>
#include"ToPostfix.h"

class myData
{
public:
	std::string num;
	int minus = 0;//0为正，1为负
	int point = 0;//小数位数
	myData() = default;
	myData(std::string str,int ok=0)
	{
		if (ok ==1)
		{
			num.swap(str);
			return;
		}
		if (str.empty())
			return;
		if (str[0] == '-')
		{
			minus = 1;
			num = str.substr(1);
		}
		else
			num.swap(str);
		int a = num.find('.');
		if (a != -1)
		{
			point = num.size() - a - 1;
			num.erase(a, 1);
		}
		for (auto &i : num)
		{
			if (i > '9' || i < '0')
				throw std::invalid_argument("数字输入错误");
			else
				i -= 48;
		}
	}
	std::string to_str();
	void justify(myData &str);
	myData& operator+=(myData str);
	myData& operator-=(myData str);//使用了swap
	myData& operator*=(const myData &str);
	myData& operator/=(myData str);
	myData operator--(int)//后置减减
	{
		myData temp = (*this);
		myData a("1");
		(*this) -= a;
		return temp;
	}
	bool operator==(const char a)//只用到了a==0的情况
	{
		return (num.size() == 1 && num[0] == a) ? true : false;
	}
	bool operator!=(const char a)
	{
		return (num.size() == 1 && num[0] == a) ? false : true;
	}
	bool operator<(const myData &str)
	{
		return (num.size() - point == str.num.size() - str.point) ?
			(num.compare(str.num) < 0) : (num.size() - point < str.num.size() - str.point);
	}
};
myData operator*(const myData &num1, const int num2);

class bigNumber
{
public:
	std::string calculation(std::string &input);
private:

};

