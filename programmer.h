#pragma once
#include<string>
#include"ToPostfix.h"

class programmer
{
public:
	int a = 10;
	int b = 10;
	std::string conversion(int a, int b, std::string number);//number a����תb����
	std::string calculation(std::string &input);
	std::string set(int a, int b)
	{
		if (a <= 1 || a > 36 || b <= 1 || b > 36)
			return "������ƴ���";
		else
		{
			programmer::a = a;
			programmer::b = b;
			return "set OK";
		}
	}
};
