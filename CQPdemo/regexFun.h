#pragma once
#include <regex>
#include "Robot.h"

using std::regex;

// 随机回应接口 1.2)<=30; 3,4)<=50; 5,6)<=75; 7,8)<=100;
extern void randSaying(Person person, Msg msg, 
	const char* ch1 = "", const char* ch2 = "", const char* ch3 = "",
	const char* ch4 = "", const char* ch5 = "", const char* ch6 = "",
	const char* ch7 = "", const char* ch8 = "");

// 字符串正则查找  1)字符串 2)想匹配的词条
extern bool entryMatch(Msg msg, const char* re);