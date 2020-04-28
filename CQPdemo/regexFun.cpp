#include "regexFun.h"

extern bool entryMatch(Msg msg, const char* re) {

	// ƥ��������
	std::smatch result;

	// ������ʽ
	regex pattern(re, regex::icase);

	// ����������
	string::const_iterator iter = msg.msg.begin();
	string::const_iterator iterEnd = msg.msg.end();
	string temp;

	// �������
	while (std::regex_search(iter, iterEnd, result, pattern))
	{
		temp = result[0];
		if (temp == re) {
			return true;
		}
		//����������ʼλ��
		iter = result[0].second;
	}

	return false;
}