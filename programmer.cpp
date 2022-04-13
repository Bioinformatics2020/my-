#include "programmer.h"

std::string programmer::conversion(int a, int b, std::string number)
{
	if (a <= 1 || a > 36 || b <= 1 || b > 36)
		throw std::invalid_argument("������ƴ���");
	int num = 0;
	std::string ans;
	for (auto i : number)
	{
		if (i >= '0'&&i <= '9')
			i -= '0';
		else if (i >= 'a'&&i <= 'z')
			i -=('a' - 10);
		else if (i >= 'A'&&i <= 'Z')
			i -= ('A' - 10);
		else
			throw std::invalid_argument("�������ִ���");
		num *= a;
		num += i;
	}
	while (num != 0)
	{
		ans.push_back(num%b);
		num /= b;
	}
	for (auto &i : ans)
	{
		if (i >= 10)
			i += ('a' - 10);
		else
			i += '0';
	}
	return std::string(ans.rbegin(),ans.rend());
}

std::string programmer::calculation(std::string &input)
{
	ToPostfix p(input);
	std::vector<int> stackNum;
	for (auto i = p.postfix.begin(); i < p.postfix.end(); ++i)
	{
		if (i->symbol != 0)//
		{
			if (stackNum.size() < 2)
				throw std::invalid_argument("����������");
			int tempNum(stackNum.back());
			stackNum.pop_back();
			switch (i->symbol)
			{
			case '+':
				stackNum.back() += tempNum;
				break;
			case '-':
				stackNum.back() -= tempNum;
				break;
			case '*':
				stackNum.back() *= tempNum;//Ԥ�����
				break;
			case '/':
				stackNum.back() /= tempNum;
				break;
			case '%':
				stackNum.back() /= tempNum;
				break;
			case '^':
				stackNum.back() ^= tempNum;
				break;
			case '|':
				stackNum.back() |= tempNum;
				break;
			case '&':
				stackNum.back() &= tempNum;
				break;
			case '>':
				stackNum.back() >>= tempNum;
			case '<':
				stackNum.back() <<= tempNum;
			default:
				throw std::invalid_argument("��֧�ֵ������");
				break;
			}
		}
		else
		{
			stackNum.push_back(std::stoi(conversion(a,10,i->str)));
		}
	}
	if (stackNum.size() != 1)
		throw std::invalid_argument("ȱ�������");
	return conversion(10, b, std::to_string(stackNum.back()));
}
