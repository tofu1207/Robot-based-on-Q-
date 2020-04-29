#include <sstream>
#include "PrivateMsg.h"
#include "CQApi.h"


void text(Msg msg, Robot robot)
{
	// 测试信息, 需要测试接口可以将 RobotAsync.cpp 的text注释打开
	if (entryMatch(msg, "测试")) {
		std::ostringstream os;
		os << robot;
		CQApi::sendPrivateMag(MASTERQQ, os.str().c_str());
	}
}

extern void helloWorld(Msg msg, Robot robot) {

	// 如果需要随机回应, 需要加上这条代码
	srand(time(NULL));

	// 如果需要修改交流方信息, 需要加上这条代码
	Person person = getPerson(msg.fromQQ);
	
	if (entryMatch(msg, "你好")) {
		// 这是个根据好感来随机输出信息, 有8条信息可以输入, 每两条作为一个分界
		// 你也可以在regexFun.cpp中自行定义接口
		randSaying(person, msg, "你好.", "嗯。");
		// 这里是修改了交流方的好感值, 其他属性也可以修改
		person.setGoodwill(++person.m_goodWill);
	}

}