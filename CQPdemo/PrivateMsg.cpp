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

extern void helloWorld(Msg msg, Robot robot) {

	// �����Ҫ�����Ӧ, ��Ҫ������������
	srand(time(NULL));

	// �����Ҫ�޸Ľ�������Ϣ, ��Ҫ������������
	Person person = getPerson(msg.fromQQ);
	
	if (entryMatch(msg, "���")) {
		// ���Ǹ����ݺø�����������Ϣ, ��8����Ϣ��������, ÿ������Ϊһ���ֽ�
		// ��Ҳ������regexFun.cpp�����ж���ӿ�
		randSaying(person, msg, "���.", "�š�");
		// �������޸��˽������ĺø�ֵ, ��������Ҳ�����޸�
		person.setGoodwill(++person.m_goodWill);
	}

}