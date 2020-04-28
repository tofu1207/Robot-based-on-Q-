#include "regexFun.h"

extern bool entryMatch(Msg msg, const char* re) {

	// 匹配结果保存
	std::smatch result;

	// 正则表达式
	regex pattern(re, regex::icase);

	// 迭代器声明
	string::const_iterator iter = msg.msg.begin();
	string::const_iterator iterEnd = msg.msg.end();
	string temp;

	// 正则查找
	while (std::regex_search(iter, iterEnd, result, pattern))
	{
		temp = result[0];
		if (temp == re) {
			return true;
		}
		//更新搜索起始位置
		iter = result[0].second;
	}

	return false;
}