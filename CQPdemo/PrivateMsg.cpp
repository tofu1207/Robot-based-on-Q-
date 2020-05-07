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

extern bool helloWorld(Msg msg, Robot robot) {

	// 如果需要随机回应, 需要加上这条代码
	srand((unsigned int)time(NULL));

	// 如果需要修改交流方信息, 需要加上这条代码
	//Person person = getPerson(msg.fromQQ);
	
	if (entryMatch(msg, "你好")) {
		int ret = rand() % 3;
		if (0 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "你好"); }
		if (1 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "嗯?"); }
		if (2 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "?"); }
		return true;
	}
	return false;
}

// 叫名字
extern bool sayName(Msg msg, Robot m_robot)
{
	srand((unsigned int)time(NULL));
	if (entryMatch(msg, m_robot.getName().c_str())) {
		int ret = rand() % 5;
		if (0 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "我在"); }
		if (1 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "嗯"); }
		if (2 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "?"); }
		if (3 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "怎么了"); }
		if (4 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "干嘛?"); }
		return true;
	}
	return false;
}

// 小草小草
extern bool sayCao(Msg msg, Robot m_robot) {
	if (entryMatch(msg, "小草")) {
		CQApi::sendPrivateMag(msg.fromQQ, "小草小草");
		return true;
	}
	return false;
}

// 在不在?
extern bool sayAlive(Msg msg, Robot m_robot) {
	if (entryMatch(msg, "在吗") || entryMatch(msg, "在不")) {
		srand((unsigned int)time(NULL));
		int ret = rand() % 5;
		if (0 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "怎么了"); }
		if (1 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "在的"); }
		if (2 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "怎么?"); }
		if (3 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "?"); }
		if (4 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "我在"); }
		return true;
	}
	return false;
}

// 在干嘛呢?
extern bool sayWork(Msg msg, Robot m_robot) {
	if (entryMatch(msg, "在干")) {
		srand((unsigned int)time(NULL));
		int ret = rand() % 5;
		if (0 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "干活..."); }
		if (1 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "工作"); }
		if (2 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "码字呢"); }
		if (3 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "吃东西"); }
		if (4 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "发呆"); }
		return true;
	}
	return false;
}


// 私聊消息无匹配回应
void nomatch(Msg msg, Robot m_robot) {
	srand((unsigned int)time(NULL));
	int ret = rand() % 10;
	if (0 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "?"); }
	if (1 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "......"); }
	if (2 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "嗯嗯"); }
	if (3 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "好"); }
	if (4 == ret) { CQApi::sendPrivateMag(msg.fromQQ, "昂..."); }
}
