#pragma once
#include<string>
#include<sstream>
class Company
{
public:
	static std::string dataLength(char mode1, char mode2, double number);//���ݳ���
	static std::string angle(char mode1, char mode2, double number);//�Ƕ�
	static std::string volume(char mode1, char mode2, double number);//����/���
	static std::string mass(char mode1, char mode2, double number);//����
	static std::string length(char mode1, char mode2, double number);//����
	static std::string area(char mode1, char mode2, double number);//���
	static std::string time(char mode1, char mode2, double number);//ʱ��
	static std::string temperature(char mode1, char mode2, double number);//�¶�
	static std::string energy(char mode1, char mode2, double number);//����
	static std::string speed(char mode1, char mode2, double number);//�ٶ�
	static std::string power(char mode1, char mode2, double number);//����
	static std::string pressure(char mode1, char mode2, double number);//ѹǿ
};

