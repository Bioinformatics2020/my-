/*
���ļ�ֻ�����������������ʷ��¼����
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

/*ȫ�ֱ���*/
Set set;
History his(set);

bool myGetOpt(string &input, vector<string> &in)
{
	cin.seekg(ios::end);
	getline(cin, input);
	if (input == "0")
		return false;
	int space = 0, space2;
	//ȡ����������
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
		cout << "����Ա������:>";
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
		cout << "��ѧ������:>";
		vector<string> in;
		if (!myGetOpt(input, in))
			return;
		try {
			if (in.size() == 3)
			{
				if (in[0] == "more")
				{
					if (in[1] == "set")
						;//ͳ��ģʽ
					else if (in[1].size() == 1 && in[1][0] >= 'A' && in[1][0] <= 'Z')
						ans = a.changePreset(in[1][0] - 'A', in[2]);
				}
				else if (in[0] == "batch")
					ans = a.batch(in[1], in[2]);
			}
			else if (in.size() == 1)
				ans = a.calculation(input);
			else
				throw invalid_argument("��������");
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
		cout << "����������:>";
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
		cout << "���ڼ���:>";
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
				cout << "�����������\n";
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
					cout << "�����������\n";
			}
			else
				cout << "�����������\n";
			break; 
		case 'n':
			if (in.size() > 1)
				cout << "�����������\n";
			else
				ans = a.getNow();
			break;
		case 's':
			cout << a.sign() << endl;
			break;
		case 'c':
			if (in.size() != 2)
				cout << "�����������\n";
			try {
				int year = stol(in[1]);//�ַ���ת���ͣ����������ʽ����
				if (year <= 0)
				{
					cout << "�ݲ�֧�ֹ�Ԫǰ" << endl;
				}
				a.put_cal(year,cout);
				ans = "��������ʾ";
			}
			catch (const invalid_argument)
			{
				cout << "����������" << endl;
			}
			break;
		default:
			cout << "ѡ�����\n";
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
		cout << "��λ����:>";
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
			catch (std::invalid_argument)//�Ƿ�������stod�����mode����
			{
				is_err = true;
			}
		}
		else
			is_err = true;
		if (is_err)
		{
			cout << "����ѡ����������\n";
			continue;
		}
		cout << ans << endl;
		his.push(his1, input, ans);
	} while (true);
}

int main()
{
	cout << "��ӭ�����๦�ܼ�����2.0\n";
	string input;//ֱ�Ӷ�ȡ�ַ������Է�ֹ�����������
	do {//����ѡ��
		cout << "�˵�:>";
		cin >> input;
		//���¿���ʹ���ֵ��Ż�
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
			cout << "ѡ�����\n";
			cin.clear();
		}
	} while (true);
	cout << "good bye\n";
	return 0;
}