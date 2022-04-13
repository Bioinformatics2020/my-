#pragma once
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<cmath>
#include"set.h"
#include"ToPostfix.h"

constexpr char PI[] = "3.141592653589793";
constexpr char E[]  = "2.718281828459045";
//a sqrt,b cbrt,c hypot,d loge,e log2,f log10,g sin,h cos,i tan,j arcsin,k arccos,l arctan,m p,n c
class Common
{
private:
	SetCommon &set;
	std::vector<std::string> preset;
	std::vector<std::string> funName = { "sqrt","cbrt","hypot","loge","log2","log10","sin","cos","tan","arcsin","arccos","arctan","p","c","abs","fac" };//a-p
	double proAns = 0;//preset[0]
	double myFun(std::string &input);//在此添加新函数，并在funName添加名称即可，若总数大于26需要改变Common与ToPostfix
	double funfactorial(int num)
	{
		if (num == 0)
			return 1;
		else if(num<0)
			throw std::invalid_argument("fun函数参数错误");
		double ans=1;
		while (num)
			ans *= num--;
		return ans;
	}
	double funp(int a, int b)
	{
		return funfactorial(a) / funfactorial(a - b);
	}
public:
	Common(SetCommon &set) :set(set)
	{
		preset.resize(29);
		preset[1] = PI;
		preset[2] = E;
	}
	std::string calculation(std::string input);
	std::string batch(std::string fileNameIn, std::string fileNameOut)
	{
		std::fstream in(fileNameIn, std::ios::in);
		if(!in.is_open())
			throw std::invalid_argument("无法打开输入文件");
		std::fstream out(fileNameOut, std::ios::out);
		if (!out.is_open())
			throw std::invalid_argument("无法打开输出文件");
		std::string input,output;
		while (in>>input)
		{
			try {
				output = calculation(input);
			}
			catch (std::invalid_argument &err)
			{
				output = err.what();
			}
			out << output << '\n';
		}
		return "batch OK";
	}
	std::string changePreset(int index, std::string input)
	{
		if(index<0 || index>25)
			throw std::invalid_argument("预设参数错误");
		preset[index+3] = calculation(input);
		return "set OK";
	}
};

