#include "date.h"

constexpr char mysign[] = "��������03��21�� - 04��19�� ��ţ����04��20�� - 05��20��\n˫������05��21�� - 06��21�� ��з����06��22�� - 07��22��\nʨ������07��23�� - 08��22�� ��Ů����08��23�� - 09��22��\n��������09��23�� - 10��23�� ��Ы����10��24�� - 11��22��\n��������11��23�� - 12��21�� Ħ������12��22�� - 01��19��\nˮƿ����01��20�� - 02��18�� ˫������02��19�� - 03��20��\n";
std::vector<std::string>table = {
	"         1��                    2��                    3��        \n" ,
	"         4��                    5��                    6��        \n" ,
	"         7��                    8��                    9��        \n" ,
	"        10��                   11��                   12��        \n" ,
	"�� һ �� �� �� �� ��   �� һ �� �� �� �� ��   �� һ �� �� �� �� ��\n" };
int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
std::vector<std::string>trunk_and_branch = { "��","��","��","��","��","��","��","��","��","��",
"��","��","��","î","��","��","��","δ","��","��","��","��" };


tm Date::getTime(std::string & str)
{
	tm time;
	memset(&time, 0, sizeof(tm));
	std::stringstream s(str);
	s >> std::get_time(&time, set.set["dateFormat"].c_str());
	return time;
}
void Date::deff(tm &time1, tm &time2)//tm1 tm2֮��ľ���ֵ��������time1
{
	time_t t = mktime(&time1) - mktime(&time2);
	if (t < 0)
		t *= -1;
	time1 = *std::localtime(&t);

}
int Date::tmToDay(tm &time)//��tm����
{
	return (int)mktime(&time) / (60 * 60 * 24) + 1;
}

int Date::tmToSecond(tm &time)//��tm����
{
	return (int)mktime(&time);
}
void Date::print1582_10_11_12(std::ostream &calOut)//���1582�������������(ʮ��)����
{
	calOut << table[3] << table[4]
		<< "    1  2  3  4 15 16       1  2  3  4  5  6             1  2  3  4 \n"
		<< "17 18 19 20 21 22 23    7  8  9 10 11 12 13    5  6  7  8  9 10 11 \n"
		<< "24 25 26 27 28 29 30   14 15 16 17 18 19 20   12 13 14 15 16 17 18 \n"
		<< "31                     21 22 23 24 25 26 27   19 20 21 22 23 24 25 \n"
		<< "                       28 29 30               26 27 28 29 30 31    \n"
		<< "\n\n";
}
std::string Date::sign()
{
	return mysign;
}
std::string Date::getNow()//��ȡ����ʱ��
{
	std::time_t rev = std::time(nullptr);
	char t[32];
	std::strftime(t, 32, tFormat.c_str(), std::localtime(&rev));
	return std::string(t);
}
std::string Date::diffTime(std::string &str1, std::string &str2)//�����ڼ��
{
	tm t1, t2;
	t1 = getTime(str1);
	if (str2.empty())
	{
		std::time_t rev = std::time(nullptr);
		t2 = *std::localtime(&rev);
	}
	else
		t2 = getTime(str2);
	deff(t1, t2);
	return std::to_string(tmToDay(t1));
}

void Date::put_cal(int year, std::ostream &calOut)//�����������
{
	int week;
	month[1] = 28;//Ĭ�ϵڶ�����28��
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		month[1] = 29;//����2����29��

	//ÿ��һ����ͨ�꣬��������һ�죬365%7=1,����0������7//����ʷԭ��1582��10����10�죬ֱ����Ϊ�������
	if (year <= 1582)//1��1��1�������� 
		week = ((year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + 6) % 7;
	if (year >= 1583)//1583��1��1��������
		week = ((year - 1583) + (year - 1581) / 4 - (year - 1501) / 100 + (year - 1201) / 400 + 6) % 7;

	int month_week[12];
	for (int i = 0; i < 12; ++i)//ȷ��ÿ���µ�һ��
	{
		month_week[i] = 1 - week;
		week = (week + month[i]) % 7;
	}

	int trunk = (year % 10 + 10 - 3 - 1) % 10;
	int branch = (year % 12 + 12 - 3 - 1) % 12;

	calOut << '\n' << year << "������  " << trunk_and_branch[trunk] << trunk_and_branch[branch + 10] << "��\n";
	for (int i = 0; i < 4; ++i)//����ļ�
	{
		calOut << table[i] << table[4];
		for (int j = 0; j < 6; ++j)//���6�й�������
		{
			for (int k = 0; k < 3; ++k)//����������ڹ�һ��
			{
				for (int l = 0; l < 7; ++l)//���һ������
				{
					if (month_week[i * 3 + k] <= 0 || month_week[i * 3 + k] > month[i * 3 + k])
						calOut << "  ";
					else
					{
						calOut.width(2);
						calOut << month_week[i * 3 + k];
					}
					++month_week[i * 3 + k];
					calOut << ' ';
				}
				calOut << "  ";
			}
			calOut << "\n";
		}
		calOut << "\n";
		if (year == 1582 && i == 2)//1582��10 11 12�����⴦��
		{
			print1582_10_11_12(calOut);
			++i;
		}
	}
}
std::string Date::changeTime(std::string &str1, std::string &str2, bool is_add)//���ڼӼ�����
{
	tm t1;
	time_t d1, d2;
	t1 = getTime(str1);
	d1 = mktime(&t1);
	if (d1 == -1)
		return "��֧�ָ�ʱ��";
	d2 = std::stoi(str2) * 60 * 60 * 24;
	if (is_add)
		d1 += d2;
	else
	{
		d1 -= d2;
	}
	if (d1 < 0)
		return "1970��ǰ";
	char t[32];
	std::strftime(t, 32, set.set["dateFormat"].c_str(), std::localtime(&d1));
	return std::string(t);
}