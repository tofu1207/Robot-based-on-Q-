
#include "PrivateMsg.h"
#include "CQApi.h"


extern void helloWorld(Msg msg, Robot robot) {

	srand(time(NULL));

	Person person = getPerson(msg.fromQQ);
	
	if (entryMatch(msg, "���")) {

		// ��ʱ���װ�ɺ���
		if (person.m_goodWill < 30) {
			if (rand() % 2 == 1) {
				CQApi::sendPrivateMag(msg.fromQQ, "���.");
			}
			if (rand() % 2 == 2) {
				CQApi::sendPrivateMag(msg.fromQQ, "��");
			}
		}
		else if (person.m_goodWill < 60) {
			CQApi::sendPrivateMag(msg.fromQQ, "��߹.");
		}
		
	}

}