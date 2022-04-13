#pragma once
#include<unordered_map>
#include<vector>
#include<string>
#include<fstream>
#include<exception>

constexpr char setName[] = "mySet.set";

class SetRoot
{
private:
	std::fstream fSet;
	bool is_change = false;
protected:
	std::unordered_map<std::string, std::unordered_map<std::string, std::string>> m;
	bool change(std::string str1, std::string str2, std::string mode)
	{
		if (m[str1][str2].empty())//没有这一项
			return false;
		is_change = true;
		m[str1][str2] == mode;
		return true;
	}
public:
	SetRoot()
	{
		fSet.open(setName, std::ios::in);
		if (!fSet.is_open())
			throw std::logic_error("configuration file open error");
		std::string str1,str2,str3;
		while (fSet >> str1 >> str2 >> str3)
		{
			m[str1][str2] = str3;
		}
	}
	~SetRoot()
	{
		if (is_change)
		{
			for (auto kk : m)
			{
				for (auto k : kk.second)
				{
					fSet << kk.first << ' ' << k.first << ' ' << k.second << '\n';
				}
			}
		}
	}
};

class SetDate :public virtual SetRoot
{
private:
	std::string str1 = "Date";
public:
	std::unordered_map<std::string, std::string>& set;

	SetDate() :set(m[str1]) { ; }
	bool setDateFormat(std::string mode){return change(str1, "dateFormat", mode);}
	bool setTimeFormat(std::string mode) { return change(str1, "timeFormat", mode); }
};

class SetHis :public virtual SetRoot
{
private:
	std::string str1 = "His";
public:
	std::unordered_map<std::string, std::string>& set;

	SetHis() :set(m[str1]) { 
		;
	}
	bool setDateFormat(std::string mode) { return change(str1, "dateFormat", mode); }
	bool setTimeFormat(std::string mode) { return change(str1, "timeFormat", mode); }
};

class SetCommon :public SetRoot
{
private:
	std::string str1 = "Common";
public:
	std::unordered_map<std::string, std::string>& set;
	SetCommon() :set(m[str1]) {
		;
	}
	
};

class Set :public SetDate, public SetHis,public SetCommon//包含所有set类
{
	;
};