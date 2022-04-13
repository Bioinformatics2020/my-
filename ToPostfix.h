#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<vector>
#include<unordered_map>
//将双目运算符分离开，并转换成后缀表达式postfix

class PostfixNode
{
public:
	PostfixNode(std::string str) :str(str),symbol(0) {};
	PostfixNode(char symbol) :symbol(symbol) {};
	std::string str;
	char symbol;
};

class ToPostfix
{
public:
	std::vector<PostfixNode> postfix;
	ToPostfix(std::string input);//生成后缀表达式

private:
	std::unordered_map<char, int> priority =//双目运算符优先级表
	{
		{'+',2},{'-',2},
		{'*',3},{'/',3},{'%',3},
		{'&',4},{'|',4},{'^',4},
		{'<',5},{'>',5},//表示左移右移	
		{'(',INT_MAX},{')',INT_MIN}
	};
};


