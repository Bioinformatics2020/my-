#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<vector>
#include<unordered_map>
//��˫Ŀ��������뿪����ת���ɺ�׺���ʽpostfix

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
	ToPostfix(std::string input);//���ɺ�׺���ʽ

private:
	std::unordered_map<char, int> priority =//˫Ŀ��������ȼ���
	{
		{'+',2},{'-',2},
		{'*',3},{'/',3},{'%',3},
		{'&',4},{'|',4},{'^',4},
		{'<',5},{'>',5},//��ʾ��������	
		{'(',INT_MAX},{')',INT_MIN}
	};
};


