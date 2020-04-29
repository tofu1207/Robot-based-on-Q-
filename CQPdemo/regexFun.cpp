#include "regexFun.h"
#include "CQApi.h"

void randSaying(Person person, Msg msg,
	const char* ch1, const char* ch2, const char* ch3,
	const char* ch4, const char* ch5, const char* ch6,
	const char* ch7, const char* ch8)
{
	
	if (person.m_goodWill <= 30) {
		if (rand() % 3 == 1) {
			CQApi::sendPrivateMag(msg.fromQQ, ch1);
		}
		if (rand() % 3 == 2) {
			CQApi::sendPrivateMag(msg.fromQQ, ch2);
		}
	}
	else if (person.m_goodWill <= 50) {
		if (rand() % 3 == 1) {
			CQApi::sendPrivateMag(msg.fromQQ, ch3);
		}
		if (rand() % 3 == 2) {
			CQApi::sendPrivateMag(msg.fromQQ, ch4);
		}
	}
	else if (person.m_goodWill <= 75) {
		if (rand() % 3 == 1) {
			CQApi::sendPrivateMag(msg.fromQQ, ch5);
		}
		if (rand() % 3 == 2) {
			CQApi::sendPrivateMag(msg.fromQQ, ch6);
		}
	}
	else if (person.m_goodWill <= 100) {
		if (rand() % 3 == 1) {
			CQApi::sendPrivateMag(msg.fromQQ, ch7);
		}
		if (rand() % 3 == 2) {
			CQApi::sendPrivateMag(msg.fromQQ, ch8);
		}
	}
	
}

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