#pragma once
#include <regex>
#include "Robot.h"

using std::regex;

// �����Ӧ�ӿ� 1.2)<=30; 3,4)<=50; 5,6)<=75; 7,8)<=100;
extern void randSaying(Person person, Msg msg, 
	const char* ch1 = "", const char* ch2 = "", const char* ch3 = "",
	const char* ch4 = "", const char* ch5 = "", const char* ch6 = "",
	const char* ch7 = "", const char* ch8 = "");

// �ַ����������  1)�ַ��� 2)��ƥ��Ĵ���
extern bool entryMatch(Msg msg, const char* re);