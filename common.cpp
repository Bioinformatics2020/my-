#include "common.h"

double Common::myFun(std::string & input)
{
	double ans;
	std::vector<double> num;
	int a = 2, b, i = 0;
	while (true)
	{
		b = input.find(',', a);
		if (b != - 1)//
		{
			num.push_back(std::stold(calculation(input.substr(a, b-a))));//12345
			a = b+1;
		}
		else
		{
			num.push_back(std::stold(calculation(input.substr(a, input.size()-1-a))));
			break;
		}
	}
	switch (input[0])
	{
	case 'a':
		if(num.size()!=1)
			throw std::invalid_argument("sqrt������������");
		ans = std::sqrt(num[0]);
		break;
	case 'b':
		if (num.size() != 1)
			throw std::invalid_argument("cbrt������������");
		ans = std::cbrt(num[0]);
		break;
	case 'c':
		if (num.size() != 2)
			throw std::invalid_argument("hypot������������");
		ans = std::hypot(num[0],num[1]);
		break;
	case 'd':
		if (num.size() != 1)
			throw std::invalid_argument("loge������������");
		ans = std::log(num[0]);
		break;
	case 'e':
		if (num.size() != 1)
			throw std::invalid_argument("log2������������");
		ans = std::log2(num[0]);
		break;
	case 'f':
		if (num.size() != 1)
			throw std::invalid_argument("log10������������");
		ans = std::log10(num[0]);
		break;
	case 'g':
		if (num.size() != 1)
			throw std::invalid_argument("sin������������");
		ans = std::sin(num[0]);
		break;
	case 'h':
		if (num.size() != 1)
			throw std::invalid_argument("cos������������");
		ans = std::cos(num[0]);
		break;
	case 'i':
		if (num.size() != 1)
			throw std::invalid_argument("tan������������");
		ans = std::tan(num[0]);
		break;
	case 'j':
		if (num.size() != 1)
			throw std::invalid_argument("arcsin������������");
		ans = std::asin(num[0]);
		break;
	case 'k':
		if (num.size() != 1)
			throw std::invalid_argument("arccos������������");
		ans = std::acos(num[0]);
		break;
	case 'l':
		if (num.size() != 1)
			throw std::invalid_argument("arctan������������");
		ans = std::atan(num[0]);
		break;
	case 'm':
		if (num.size() != 2)
			throw std::invalid_argument("p������������");
		ans = funfactorial(num[0]) / funfactorial(num[0] - num[1]);//����
		break;
	case 'n':
		if (num.size() != 2 || num[0] < num[1] || num[1] <0)
			throw std::invalid_argument("c������������");
		ans = funfactorial(num[0]) / funfactorial(num[0] - num[1]) / funfactorial(num[1]);//���
		break;
	case 'o':
		if (num.size() != 1)
			throw std::invalid_argument("c������������");
		ans = std::abs(num[0]);
		break;
	case 'p':
		if (num.size() != 1)
			throw std::invalid_argument("fun������������");
		ans = funfactorial(num[0]);
		break;
	default:
		throw std::invalid_argument("δ���庯��");
		break;
	}
	return ans;
}

std::string Common::calculation(std::string input)
{
	std::string input_is_change;
	for (int i = 0; i < input.size(); )//Ԥ����ȷ��Ԥ��ֵ�뺯��
	{
		if (input[i] >= 'A' && input[i] <= 'Z')//����Ԥ��ֵ
		{
			input_is_change += preset[input[i] - 'A' + 3];
			++i;
		}
		else if (i + 2 < input.size() && input[i] == 'a' && input[i+1] == 'n'&& input[i+2] == 's')
		{
			input_is_change += preset[0];
			i += 3;
		}
		else if (i + 1 < input.size() && input[i] == 'p' && input[i+1] == 'i')
		{
			input_is_change += preset[1];
			i += 2;
		}
		else if (input[i] == 'e')
		{
			input_is_change += preset[2];
			++i;
		}
		else if(input[i] >= 'a' && input[i] <= 'z')//������
		{
			int k = 0;
			for (int j = 0; j < funName.size(); ++j)//�������к���
			{
				int len = funName[j].size();
				if (i + len <= input.size())
				{
					k = 0;
					for (; k < len; ++k)
					{
						if (funName[j][k] != input[i + k])
							break;
					}
					if (k == len)
					{
						input_is_change += (j + 'a');//��Ӹú�������Ӧ��ĸ
						break;
					}
				}
			}
			if (k == 0)
				throw std::invalid_argument("�������ƴ���");
			else
				i += k;
		}
		else
		{
			input_is_change += input[i];
			++i;
		}
	}
	
	ToPostfix p(input_is_change);
	std::vector<double> stackNum;
	for (auto i = p.postfix.begin(); i < p.postfix.end(); ++i)
	{
		long long a;
		if (i->symbol != 0)
		{
			if (stackNum.size() < 2)
				throw std::invalid_argument("����������");
			double tempNum(stackNum.back());
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
				a = stackNum.back();
				a %= (long long)tempNum;
				stackNum.back() = a;
				break;
			case '^':
				stackNum.back() = std::pow(stackNum.back(),tempNum);
				break;
			default:
				throw std::invalid_argument("��֧�ֵ������");
				break;
			}
		}
		else
		{
			if(i->str[0]>='a'&&i->str[0] <= 'z')
				stackNum.push_back(myFun(i->str));
			else
				stackNum.push_back(std::stod(i->str));
		}
	}
	if (stackNum.size() != 1)
		throw std::invalid_argument("ȱ�������");
	std::ostringstream ss;
	ss << stackNum.back();
	preset[0] = ss.str();
	return ss.str();
}
