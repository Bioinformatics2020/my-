#include "bigNumber.h"

std::string bigNumber::calculation(std::string & input)
{
	ToPostfix p(input);
	std::vector<myData> stackNum;
	for (auto i = p.postfix.begin(); i < p.postfix.end(); ++i)
	{
		if (i->symbol != 0)//
		{
			if (stackNum.size() < 2)
				throw std::invalid_argument("����������");
			myData tempNum(stackNum.back());
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
				if (tempNum == 0 || tempNum.num.empty())
					throw 1;
				stackNum.back() /= tempNum;
				break;
			case '^'://С���η�
			{
				myData m = stackNum.back();
				while (tempNum-- != 1)
					stackNum.back() *= m;
				break;
			}
			default:
				throw std::invalid_argument("��֧�ֵ������");
				break;
			}
		}
		else
		{
			stackNum.push_back(i->str);
		}
	}
	if (stackNum.size() != 1)
		throw std::invalid_argument("ȱ�������");

	return stackNum.back().to_str();
}

std::string myData::to_str()
{
	std::string ans;
	if (num.empty())
		ans.push_back('0');
	else
	{
		if (minus)
			ans.push_back('-');
		while (point > 0 && num.back() == 0)
		{
			--point;
			num.pop_back();
		}
		std::string ans2(num);
		for (auto &i : ans2)
		{
			i += 48;
		}

		if (point >= (int)num.size())
		{
			std::string temp(point - num.size(), '0');
			while (ans2.back() == 0)
				ans2.pop_back();
			ans += "0." + temp + ans2;
		}
		else if (point != 0)
		{
			int n = num.size() - point;
			ans += ans2.insert(n, 1, '.');
		}
		else
		{
			ans+=ans2;
		}
	}
	return ans;
}

void myData::justify(myData & str)//���С������0��ʹС������
{
	if (this->point < str.point)
	{
		this->num.append(str.point - this->point, 0);
		this->point = str.point;
	}
	else
	{
		str.num.append(this->point - str.point, 0);
		str.point = this->point;
	}
}

myData & myData::operator+=(myData str)
{
	std::string ans;

	//һ��һ���ļӷ�������ȼ���
	if (this->minus == 1 && str.minus == 0)
	{
		this->minus = 0;
		(*this) = (str -= (*this));
	}
	else if (this->minus == 0 && str.minus == 1)
	{
		str.minus = 0;
		(*this) = ((*this) -= str);
	}
	else
	{
		//����С������
		justify(str);

		//ͬ��ʱ���Ӹ�λ��ʼ�����λ������ӣ�����λ����
		int len1 = this->num.size() - 1;
		int len2 = str.num.size() - 1;
		int carry = 0;//��λ
		while (len1 >= 0 && len2 >= 0)
		{
			ans.push_back(this->num[len1--] + str.num[len2--] + carry);
			carry = ans.back() / 10;
			ans.back() %= 10;
		}
		while (len1 >= 0)
		{
			ans.push_back(this->num[len1--] + carry);
			carry = ans.back() / 10;
			ans.back() %= 10;
		}
		while (len2 >= 0)
		{
			ans.push_back(str.num[len2--] + carry);
			carry = ans.back() / 10;
			ans.back() %= 10;
		}
		if (carry)
		{
			ans.push_back(carry);
		}
		//�����ϣ�ȥ�������0
		while (!ans.empty() && ans.back() == 0)
		{
			ans.pop_back();
		}

		//����,������
		this->num = std::string(ans.rbegin(), ans.rend());
	}
	return (*this);
}

myData & myData::operator-=(myData str)
{
	std::string ans;

	//һ��һ���ļ���������ȼӷ�
	if (minus != str.minus)
	{
		str.minus = minus;//ʹ����ͬ��
		(*this) += myData(str);
	}
	else
	{
		//����С������
		justify(str);

		if (minus == 1)//������������Ϊ�������������൱�ڳ˸�һ
		{
			minus = 0;
		}
		if ((*this) < str)//��֤������С������ʱ�����������൱�ڳ˸�һ
		{
			minus ^= 1;
			num.swap(str.num);
		}

		//ͬ��ʱ���Ӹ�λ��ʼ�����λ�������
		int len1 = num.size() - 1;
		int len2 = str.num.size() - 1;
		int carry = 0;//��λ
		while (len1 >= 0 && len2 >= 0)
		{
			ans.push_back(num[len1--] - str.num[len2--] + carry);
			if (ans.back() < 0)
			{
				ans.back() += 10;
				carry = -1;
			}
			else
				carry = 0;
		}
		while (len1 >= 0)
		{
			ans.push_back(num[len1--] + carry);
			if (ans.back() < 0)
			{
				ans.back() += 10;
				carry = -1;
			}
			else
				carry = 0;
		}
		//�����ϣ�ȥ�������0
		while (ans.back() == 0)
		{
			ans.pop_back();
			if (ans.empty())
			{
				this->num = "";
				return (*this);
			}
		}
		//����,������
		this->num = std::string(ans.rbegin(), ans.rend());
	}
	return (*this);
}

myData & myData::operator*=(const myData &str)
{
	myData ans;

	for (int i = str.num.size(), len = 0; len < i;)//���ַ���2��ÿ8λת����һ�����������г˷�
	{
		int num2 = 0;
		int k = 0;
		for (; k < 8 && len < i; ++len, ++k)//[len,i)
		{
			num2 *= 10;
			num2 += str.num[len];
		}
		ans.num.append(k, (char)0);//Ϊ��ʱ���0��Ӱ��ӷ�
		//ans.num.push_back(0);
		ans += (*this)*num2;
	}

	this->point += str.point;
	this->minus ^= str.minus;
	this->num = ans.num;
	return (*this);
}

myData operator*(const myData &num1, const int num2)
{
	std::string ans;
	int carry = 0;//��λ
	int sum = 0;
	for (int i = num1.num.size() - 1; i >= 0; --i)
	{
		sum = num1.num[i] * num2 + carry;
		carry = sum / 10;
		ans.push_back(sum % 10);
	}
	while (carry)
	{
		ans.push_back(carry % 10);
		carry /= 10;
	}

	return myData(std::string(ans.rbegin(), ans.rend()),1);//�������
}

myData & myData::operator/=(myData str)
{
	myData ans;
	ans.minus = this->minus^str.minus;
	this->minus = str.minus = 0;

	this->point -= str.point;
	ans.point = 0;
	str.point = 0;

	int myStrLeftMove = this->num.size() - this->point - str.num.size();
	if (myStrLeftMove > 0)
	{
		ans.point -= myStrLeftMove;
		this->point += myStrLeftMove;
	}


	for (int i = 0; i < 100; ++i)//����ౣ��100λ��Ч����
	{
		while ((*this) < str)
		{
			this->num.push_back(0);
			++ans.point;
		}
		int temp = 0;
		for (; !((*this) < str) && !(this->num.empty()); ++temp)
		{
			(*this) -= str;
		}
		ans.num.push_back(temp);
		if (this->num.empty())
			break;
	}
	if (ans.point < 0)
	{
		ans.num.append(-1 * ans.point, '\0');
		ans.point = 0;
	}
	*this = ans;
	return (*this);
}
