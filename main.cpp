/*
本文件只包含命令交互部分与历史记录部分
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"History.h"
#include"date.h"
#include"set.h"
#include"company.h"
#include"bigNumber.h"
#include"programmer.h"
#include"common.h"

using namespace std;

/*全局变量*/
Set set;
History his(set);

bool myGetOpt(string &input, vector<string> &in)
{
	cin.seekg(ios::end);
	getline(cin, input);
	if (input == "0")
		return false;
	int space = 0, space2;
	//取出输入内容
	int i = 0;
	while (i < 4)
	{
		space2 = input.find(' ', space);
		if (space2 == -1)
		{
			in.push_back(input.substr(space));
			break;
		}
		in.push_back(input.substr(space, space2 - space));
		space = space2 + 1;
		++i;
	}
	return true;
}

void mainHelp()
{
	ifstream fHelp("help.txt", ios::in);
	if (fHelp.is_open())
		cout << fHelp.rdbuf() << endl;
	else
		cout << "help.txt is lost" << endl;
}

void programmerMenu()
{
	string his1 = "programmer";
	programmer a;
	do {
		string input, ans;
		cout << "程序员计算器:>";
		vector<string> in;
		if (!myGetOpt(input, in))
			return;
		if (in.size() == 4 && in[0] == "more")
		{
			if (in[3] == "set")
			{
				ans = a.set(stoi(in[1]), stoi(in[2]));
			}
			else
				ans = a.conversion(stoi(in[1]), stoi(in[2]), in[3]);

		}
		else 
		{
			try {
				ans = a.calculation(input);
			}
			catch (invalid_argument& err)
			{
				cout << err.what() << endl;
			}
		}
		cout << ans << endl;
		his.push(his1, input, ans);
	} while (true);
}

void commonMenu()
{
	string his1 = "common";
	Common a(set);
	do {
		string input, ans;
		cout << "科学计算器:>";
		vector<string> in;
		if (!myGetOpt(input, in))
			return;
		try {
			if (in.size() == 3)
			{
				if (in[0] == "more")
				{
					if (in[1] == "set")
						;//统计模式
					else if (in[1].size() == 1 && in[1][0] >= 'A' && in[1][0] <= 'Z')
						ans = a.changePreset(in[1][0] - 'A', in[2]);
				}
				else if (in[0] == "batch")
					ans = a.batch(in[1], in[2]);
			}
			else if (in.size() == 1)
				ans = a.calculation(input);
			else
				throw invalid_argument("参数错误");
		}
		catch (invalid_argument& err)
		{
			cout << err.what() << endl;
			continue;
		}

		cout << ans << endl;
		his.push(his1, input, ans);
	} while (true);
}

void bigNumMenu()
{
	string his1 = "bigNum";
	bigNumber a;
	do {
		string input, ans;
		cout << "大数计算器:>";
		vector<string> in;
		if (!myGetOpt(input, in))
			return;
		try {
			ans = a.calculation(input);
		}
		catch (invalid_argument& err)
		{
			cout << err.what() << endl;
			
		}
		
		cout << ans << endl;
		his.push(his1, input, ans);
	} while (true);
}

void dateMenu()
{
	string his1 = "date";
	Date a(set);
	do {
		string input, ans;
		cout << "日期计算:>";
		vector<string> in;
		if (!myGetOpt(input, in))
			return;
		char mode = -1;
		if (in[0].size()==1)
			mode = in[0][0];
		switch (mode)
		{
		case 'i':
			if (in.size() > 3 || in.size() < 2)
				cout << "输入参数错误\n";
			else
			{
				if (in.size() == 2)
					in.push_back("");
				ans = a.diffTime(in[1], in[2]);
			}
			break;
		case 'v'://v 2022/4/9 + 1
			if (in.size() == 4)
			{
				if (in[2] == "+")
					ans = a.changeTime(in[1], in[3], true);
				else if(in[2] == "-")
					ans = a.changeTime(in[1], in[3], false);
				else
					cout << "输入参数错误\n";
			}
			else
				cout << "输入参数错误\n";
			break; 
		case 'n':
			if (in.size() > 1)
				cout << "输入参数错误\n";
			else
				ans = a.getNow();
			break;
		case 's':
			cout << a.sign() << endl;
			break;
		case 'c':
			if (in.size() != 2)
				cout << "输入参数错误\n";
			try {
				int year = stol(in[1]);//字符串转整型，避免输入格式错误
				if (year <= 0)
				{
					cout << "暂不支持公元前" << endl;
				}
				a.put_cal(year,cout);
				ans = "日历已显示";
			}
			catch (const invalid_argument)
			{
				cout << "年份输入错误" << endl;
			}
			break;
		default:
			cout << "选项错误\n";
			continue;
		}
		cout << ans << endl;
		his.push(his1, input, ans);
	} while (true);
}

void companyMenu()
{
	string his1("company");
	string(*funs[])(char, char, double) = { Company::dataLength,Company::angle,Company::volume,Company::mass,Company::length,Company::area,Company::time,Company::temperature,Company::energy,Company::speed,Company::power,Company::pressure };
	do{
		string input, ans;
		cout << "单位换算:>";
		vector<string> in;
		if (!myGetOpt(input, in))
			return;
		bool is_err = false;
		char mode = -1;
		if (in[0].size() == 1)
			mode = in[0][0];
		if (mode >= 'a'&&mode <= 'l'&& in.size() == 4 && in[1].size() == 1 && in[2].size() == 1)
		{
			try {
				ans = funs[mode - 'a'](in[1][0], in[2][0], stod(in[3]));
			}
			catch (std::invalid_argument)//非法参数，stod错误或mode错误
			{
				is_err = true;
			}
		}
		else
			is_err = true;
		if (is_err)
		{
			cout << "输入选项或参数错误\n";
			continue;
		}
		cout << ans << endl;
		his.push(his1, input, ans);
	} while (true);
}

int main()
{
	cout << "欢迎来到多功能计算器2.0\n";
	string input;//直接读取字符串可以防止输出参数错误
	do {//功能选择
		cout << "菜单:>";
		cin >> input;
		//以下可以使用字典优化
		if (input == "help")
			mainHelp();
		else if (input == "exit" || input == "0")
			break;
		else if (input == "common")
			commonMenu();
		else if (input == "bigNum")
			bigNumMenu();
		else if (input == "programmer")
			programmerMenu();
		else if (input == "date")
			dateMenu();
		else if (input == "company")
			companyMenu();
		else
		{
			cout << "选项错误\n";
			cin.clear();
		}
	} while (true);
	cout << "good bye\n";
	return 0;
}