#pragma once
#include <regex>
#include "Robot.h"

using std::regex;

//字符串正则查找  1)字符串 2)想匹配的词条
extern bool entryMatch(Msg msg, const char* re);