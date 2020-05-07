#include <sstream>
#include "PrivateMsg.h"
#include "CQApi.h"


void text(Msg msg, Robot robot)
{
	// ������Ϣ, ��Ҫ���Խӿڿ��Խ� RobotAsync.cpp ��textע�ʹ�
	if (entryMatch(msg, "����")) {
		std::ostringstream os;
		os << robot;
		CQApi::sendPrivateMag(MASTERQQ, os.str().c_str());
	}
}

extern bool helloWorld(Msg msg, Robot robot) {

	// �����Ҫ�����Ӧ, ��Ҫ������������
	srand((unsigned int)time(NULL));

	// �����Ҫ�޸Ľ�������Ϣ, ��Ҫ������������
	//Person person = getPerson(msg.fromQQ);
	
	if (entryMatch(msg, "���")) {
		int ret = rand() % 3;
		if (0 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "���"); }
		if (1 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "��?"); }
		if (2 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "?"); }
		return true;
	}
	return false;
}

// ������
extern bool sayName(Msg msg, Robot m_robot)
{
	srand((unsigned int)time(NULL));
	if (entryMatch(msg, m_robot.getName().c_str())) {
		int ret = rand() % 5;
		if (0 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "����"); }
		if (1 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "��"); }
		if (2 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "?"); }
		if (3 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "��ô��"); }
		if (4 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "����?"); }
		return true;
	}
	return false;
}

// С��С��
extern bool sayCao(Msg msg, Robot m_robot) {
	if (entryMatch(msg, "С��")) {
		CQApi::sendPrivateMag(msg.fromQQ, "С��С��");
		return true;
	}
	return false;
}

// �ڲ���?
extern bool sayAlive(Msg msg, Robot m_robot) {
	if (entryMatch(msg, "����") || entryMatch(msg, "�ڲ�")) {
		srand((unsigned int)time(NULL));
		int ret = rand() % 5;
		if (0 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "��ô��"); }
		if (1 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "�ڵ�"); }
		if (2 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "��ô?"); }
		if (3 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "?"); }
		if (4 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "����"); }
		return true;
	}
	return false;
}

// �ڸ�����?
extern bool sayWork(Msg msg, Robot m_robot) {
	if (entryMatch(msg, "�ڸ�")) {
		srand((unsigned int)time(NULL));
		int ret = rand() % 5;
		if (0 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "�ɻ�..."); }
		if (1 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "����"); }
		if (2 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "������"); }
		if (3 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "�Զ���"); }
		if (4 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "����"); }
		return true;
	}
	return false;
}


// ˽����Ϣ��ƥ���Ӧ
void nomatch(Msg msg, Robot m_robot) {
	srand((unsigned int)time(NULL));
	int ret = rand() % 10;
	if (0 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "?"); }
	if (1 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "......"); }
	if (2 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "����"); }
	if (3 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "��"); }
	if (4 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "��..."); }
}
