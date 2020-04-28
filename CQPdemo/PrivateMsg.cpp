
#include "PrivateMsg.h"
#include "CQApi.h"


extern void helloWorld(Msg msg, Robot robot) {

	srand(time(NULL));

	Person person = getPerson(msg.fromQQ);
	
	if (entryMatch(msg, "你好")) {

		// 到时候封装成函数
		if (person.m_goodWill < 30) {
			if (rand() % 2 == 1) {
				CQApi::sendPrivateMag(msg.fromQQ, "你好.");
			}
			if (rand() % 2 == 2) {
				CQApi::sendPrivateMag(msg.fromQQ, "嗯");
			}
		}
		else if (person.m_goodWill < 60) {
			CQApi::sendPrivateMag(msg.fromQQ, "好吖.");
		}
		
	}

}