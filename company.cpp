#include "company.h"

constexpr double pi = 3.1415926535;
std::stringstream myCout;//���������

std::string Company::dataLength(char mode1, char mode2, double number)//���ݳ���
{//��׼Ϊbit
	switch (mode1)
	{
	case 'k':
		number *= 1024;
	case 'j':
		number *= 1024;
	case 'i':
		number *= 1024;
	case 'h':
		number *= 1024;
	case 'g':
		number *= 1024;
	case 'f':
		number *= 1024;
	case 'e':
		number *= 1024;
	case 'd':
		number *= 1024; 
	case 'c':
		number *= 1024;
	case 'b':
		number *= 8;
	case 'a':
		;
		break;
	default:
		throw std::invalid_argument("mode1 error");
	}
	switch (mode2)
	{
	case 'k':
		number /= 1024;
	case 'j':
		number /= 1024;
	case 'i':
		number /= 1024;
	case 'h':
		number /= 1024;
	case 'g':
		number /= 1024;
	case 'f':
		number /= 1024;
	case 'e':
		number /= 1024;
	case 'd':
		number /= 1024;
	case 'c':
		number /= 1024;
	case 'b':
		number /= 8;
	case 'a':
		;
		break;
	default:
		throw std::invalid_argument("mode2 error");
		break;
	}
	myCout.str("");
	myCout << number;
	return myCout.str();
}
std::string Company::angle(char mode1, char mode2, double number)//�Ƕ�
{//��׼Ϊ��
	switch (mode1)
	{
	case 'a':
		number /= 60;
	case 'b':
		number /= 60;
	case 'c':
		break;
	case 'd':
		number *= pi / 180;
		break;
	case 'e':
		number *= 0.9;
		break;
	default:
		throw std::invalid_argument("mode1 error");
		break;
	}
	switch (mode2)
	{
	case 'a':
		break;
	case 'b':
		number *= 180 / pi;
		break;
	case 'c':
		number *= 10/9;
		break;
	default:
		throw std::invalid_argument("mode2 error");
		break;
	}
	myCout.str("");
	myCout << number;
	return myCout.str();
}
std::string Company::volume(char mode1, char mode2, double number)//����/���
{//��׼Ϊ΢��
	switch (mode1)
	{
	case 'a':
		number *= 1000;
	case 'b':
		number *= 1000;
	case 'c':
		number *= 1000;
	case 'd':
		break;
	case 'e':
		number *= 1.5;
	case 'f':
		number *= 1000 * 10;//���Ʋ��ת΢��
		break;
	case 'g':
		number *= 42;
	case 'h':
		number *= 4;
	case 'i':
		number *= 2;
	case 'j':
		number *= 32;
	case 'k':
		number *= 3;
	case 'l':
		number *= 4.9289216 * 1000;//���Ʋ��ת΢��
		break;
	case 'm':
		number *= 36;
	case 'n':
		number *= 4;
	case 'o':
		number *= 2;
	case 'p':
		number *= 32;
	case 'q':
		number *= 3;
	case 'r':
		number *= 5.9193906 * 1000;//Ӣ�Ʋ��ת΢��
		break;
	case 's':
		number *= 27;
	case 't':
		number *= 1728;
	case 'u':
		number *= 16.38706 * 1000;//����Ӣ��ת΢��
		break;
	default:
		throw std::invalid_argument("mode1 error");
		break;
	}
	switch (mode2)
	{
	case 'a':
		number /= 1000;
	case 'b':
		number /= 1000;
	case 'c':
		number /= 1000;
	case 'd':
		break;
	case 'e':
		number /= 1.5;
	case 'f':
		number /= (1000 * 10);//΢��ת���Ʋ��
		break;
	case 'g':
		number /= 42;
	case 'h':
		number /= 4;
	case 'i':
		number /= 2;
	case 'j':
		number /= 32;
	case 'k':
		number /= 3;
	case 'l':
		number /= (4.9289216 * 1000);//΢��ת���Ʋ��
		break;
	case 'm':
		number /= 36;
	case 'n':
		number /= 4;
	case 'o':
		number /= 2;
	case 'p':
		number /= 32;
	case 'q':
		number /= 3;
	case 'r':
		number /= (5.9193906 * 1000);//΢��תӢ�Ʋ��
		break;
	case 's':
		number /= 27;
	case 't':
		number /= 1728;
	case 'u':
		number /= (16.38706 * 1000);//΢��ת����Ӣ��
		break;
	default:
		throw std::invalid_argument("mode2 error");
		break;
	}
	myCout.str("");
	myCout << number;
	return myCout.str();
}
std::string Company::mass(char mode1, char mode2, double number)//����
{//��׼Ϊ΢��
	switch (mode1)
	{
	case 'a':
		number *= 1000;
	case 'b':
		number *= 1000;
	case 'c':
		number *= 1000;
	case 'd':
		number *= 1000;
	case 'e':
		break;//ת΢��
	case 'f':
		number *= 100;
	case 'g':
		number *= 10;
	case 'h':
		number *= 10;
	case 'i':
		number *= 5*1000*1000;//Ǯת΢��
		break;
	case 'j':
		number *= 16;
	case 'k':
		number *= 28.349523*1000*1000;//��˾ת΢��
		break;
	case 'l':
		number *= 10;
	case 'm':
		number *= 0.02 * 1000 * 1000;//��(��ʯ)ת΢��
		break;
	default:
		throw std::invalid_argument("mode1 error");
		break;
	}
	switch (mode2)
	{
	case 'a':
		number /= 1000;
	case 'b':
		number /= 1000;
	case 'c':
		number /= 1000;
	case 'd':
		number /= 1000;
	case 'e':
		break;//΢��
	case 'f':
		number /= 100;
	case 'g':
		number /= 10;
	case 'h':
		number /= 10;
	case 'i':
		number /= (5 * 1000 * 1000);//΢��תǮ
		break;
	case 'j':
		number /= 16;
	case 'k':
		number /= (28.349523 * 1000 * 1000);//΢��ת��˾
		break;
	case 'l':
		number /= 10;
	case 'm':
		number /= (0.02 * 1000 * 1000);//΢��ת��(��ʯ)
		break;
	default:
		throw std::invalid_argument("mode2 error");
		break;
	}
	myCout.str("");
	myCout << number;
	return myCout.str();
}
std::string Company::length(char mode1, char mode2, double number)//����
{//��׼Ϊ��
	switch (mode1)
	{
	case 'a':
		number /= 1000;
	case 'b':
		number /= 1000;
	case 'c':
		number /= 1000;
	case 'd':
		number /= 10;
	case 'e':
		number /= 10;
	case 'f':
		break;//��
	case 'g':
		number *= 1.852;
	case 'h':
		number *= 2;
	case 'i':
		number *= 150;
	case 'j':
		number *= 10;
	case 'k':
		number *= 10;
	case 'l':
		number *= 10;
	case 'm':
		number *= 10;
	case 'n':
		number *= 3/10/1000;//��ת��
		break;
	case 'o':
		number *= 1760;
	case 'p':
		number *= 3;
	case 'q':
		number *= 12;
	case 'r':
		number *= 0.0254;//Ӣ��ת��
		break;
	case 's':
		number *= 30856775814671916;//����ת��
		break;
	case 't':
		number *= 149597870700;//���ĵ�λת��
		break;
	case 'u':
		number *= 9460730472580800;//����ת��
		break;
	default:
		throw std::invalid_argument("mode1 error");
		break;
	}
	switch (mode2)
	{
	case 'a':
		number *= 1000;
	case 'b':
		number *= 1000;
	case 'c':
		number *= 1000;
	case 'd':
		number *= 10;
	case 'e':
		number *= 10;
	case 'f':
		break;//��
	case 'g':
		number /= 1.852;
	case 'h':
		number /= 2;
	case 'i':
		number /= 150;
	case 'j':
		number /= 10;
	case 'k':
		number /= 10;
	case 'l':
		number /= 10;
	case 'm':
		number /= 10;
	case 'n':
		number /= (3 / 10 / 1000);//��ת��
		break;
	case 'o':
		number /= 1760;
	case 'p':
		number /= 3;
	case 'q':
		number /= 12;
	case 'r':
		number /= 0.0254;//Ӣ��ת��
		break;
	case 's':
		number /= 30856775814671916;//����ת��
		break;
	case 't':
		number /= 149597870700;//���ĵ�λת��
		break;
	case 'u':
		number /= 9460730472580800;//����ת��
		break;
	default:
		throw std::invalid_argument("mode2 error");
		break;
	}
	myCout.str("");
	myCout << number;
	return myCout.str();
}
std::string Company::area(char mode1, char mode2, double number)//���
{//��׼Ϊƽ������
	switch (mode1)
	{
	case 'a':
		number *= 100;
	case 'b':
		number *= 15;
	case 'c':
		number *= (2000/3);
	case 'd':
		number *= 10000;
	case 'e':
		number *= 100;
	case 'f':
		break;//ƽ������
	case 'g':
		number *= 640;
	case 'h':
		number *= 43560;
	case 'i':
		number *= 144;
	case 'j':
		number *= 645.16;//ƽ��Ӣ��תƽ������
		break;
	default:
		throw std::invalid_argument("mode1 error");
		break;
	}
	switch (mode2)
	{
	case 'a':
		number /= 100;
	case 'b':
		number /= 15;
	case 'c':
		number /= (2000 / 3);
	case 'd':
		number /= 10000;
	case 'e':
		number /= 100;
	case 'f':
		break;//ƽ������
	case 'g':
		number /= 640;
	case 'h':
		number /= 43560;
	case 'i':
		number /= 144;
	case 'j':
		number /= 645.16;//ƽ������תƽ��Ӣ��
		break;
	default:
		throw std::invalid_argument("mode2 error");
		break;
	}
	myCout.str("");
	myCout << number;
	return myCout.str();
}
std::string Company::time(char mode1, char mode2, double number)//ʱ��
{//��׼Ϊ��
	switch (mode1)
	{
	case 'a':
		number *= 100;
	case 'b':
		number *= (365.25/7);
	case 'c':
		number *= 7;
	case 'd':
		number *= 24;
	case 'e':
		number *= 60;
	case 'f':
		number *= 60;
	case 'g':
		break;//��
	case 'h':
		number *= 1000;
	case 'i':
		number *= 1000;
	case 'j':
		number /= 1000000000;
		break;//����ת��
	case 'k':
		number *= 8;
	case 'l':
		number *= (15*60);
		break;//��ת��
	default:
		throw std::invalid_argument("mode1 error");
		break;
	}
	switch (mode2)
	{
	case 'a':
		number /= 100;
	case 'b':
		number /= (365.25 / 7);
	case 'c':
		number /= 7;
	case 'd':
		number /= 24;
	case 'e':
		number /= 60;
	case 'f':
		number /= 60;
	case 'g':
		break;//��
	case 'h':
		number /= 1000;
	case 'i':
		number /= 1000;
	case 'j':
		number *= 1000000000;
		break;//��ת����
	case 'k':
		number /= 8;
	case 'l':
		number /= (15 * 60);
		break;//��ת��
	default:
		throw std::invalid_argument("mode2 error");
		break;
	}
	myCout.str("");
	myCout << number;
	return myCout.str();
}
std::string Company::temperature(char mode1, char mode2, double number)//�¶�
{//��׼Ϊ���϶�
	switch (mode1)
	{
	case 'a':
		number = (number - 32) / 1.8;//���϶�ת���϶�
	case 'b':
		break;
	case 'c':
		number -= 273.15;//������ת���϶�
		break;
	default:
		throw std::invalid_argument("mode1 error");
		break;
	}
	switch (mode2)
	{
	case 'a':
		number = number * 1.8 + 32;//���϶�ת���϶�
	case 'b':
		break;
	case 'c':
		number += 273.15;//���϶�ת������
		break;
	default:
		throw std::invalid_argument("mode2 error");
		break;
	}
	myCout.str("");
	myCout << number;
	return myCout.str();
}
std::string Company::energy(char mode1, char mode2, double number)//����
{//��׼Ϊ����
	switch (mode1)
	{
	case 'a':
		number *= 3600000;
	case 'b':
		break;
	case 'c':
		number *= 4.1858518;
		break;
	default:
		throw std::invalid_argument("mode1 error");
		break;
	}
	switch (mode2)
	{
	case 'a':
		number /= 3600000;
	case 'b':
		break;
	case 'c':
		number /= 4.1858518;
		break;
	default:
		throw std::invalid_argument("mode2 error");
		break;
	}
	myCout.str("");
	myCout << number;
	return myCout.str();
}
std::string Company::speed(char mode1, char mode2, double number)//�ٶ�
{//��׼Ϊ��ÿ��
	switch (mode1)
	{
	case 'a':
		number *= 340;
	case 'b':
		break;
	case 'c':
		number *= 1.852;
	case 'd':
		number /= 3.6;//����ÿСʱת��ÿ��
		break;
	default:
		throw std::invalid_argument("mode1 error");
		break;
	}
	switch (mode2)
	{
	case 'a':
		number /= 340;
	case 'b':
		break;
	case 'c':
		number /= 1.852;
	case 'd':
		number *= 3.6;//����ÿСʱת��ÿ��
		break;
	default:
		throw std::invalid_argument("mode2 error");
		break;
	}
	myCout.str("");
	myCout << number;
	return myCout.str();
}
std::string Company::power(char mode1, char mode2, double number)//����
{//��׼Ϊ��
	switch (mode1)
	{
	case 'a':
		number *= 1000;
	case 'b':
		break;
	case 'c':
		number *= 735.49875;//��������ת��
		break;
	default:
		throw std::invalid_argument("mode1 error");
		break;
	}
	switch (mode2)
	{
	case 'a':
		number /= 1000;
	case 'b':
		break;
	case 'c':
		number /= 735.49875;//��������ת��
		break;
	default:
		throw std::invalid_argument("mode2 error");
		break;
	}
	myCout.str("");
	myCout << number;
	return myCout.str();
}
std::string Company::pressure(char mode1, char mode2, double number)//ѹǿ
{//��׼Ϊǧ��
	switch (mode1)
	{
	case 'a':
		number *= 1.01325;
	case 'b':
		number *= 100;
	case 'c':
		number *= 7.5;
	case 'd':
		break;
	default:
		throw std::invalid_argument("mode1 error");
		break;
	}
	switch (mode2)
	{
	case 'a':
		number /= 1.01325;
	case 'b':
		number /= 100;
	case 'c':
		number /= 7.5;
	case 'd':
		break;
	default:
		throw std::invalid_argument("mode2 error");
		break;
	}
	myCout.str("");
	myCout << number;
	return myCout.str();
}