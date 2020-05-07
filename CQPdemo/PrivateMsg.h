#pragma once
#include "regexFun.h"   //正则常用函数


// 这里是处理私聊消息的

// 测试
extern void text(Msg msg, Robot robot);

// 问好
extern bool helloWorld(Msg msg, Robot robot);

// 叫名字
extern bool sayName(Msg msg, Robot m_robot);

// 小草小草
extern bool sayCao(Msg msg, Robot m_robot);

// 在不在?
extern bool sayAlive(Msg msg, Robot m_robot);

// 在干嘛呢?
extern bool sayWork(Msg msg, Robot m_robot);

// 私聊消息无匹配
extern void nomatch(Msg msg, Robot m_robot);