#pragma once
#include <regex>
#include "Robot.h"

using std::regex;

//�ַ����������  1)�ַ��� 2)��ƥ��Ĵ���
extern bool entryMatch(Msg msg, const char* re);