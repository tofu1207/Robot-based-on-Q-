#pragma once

#include <queue>
#include <mutex>
#include <Windows.h>
#include "ThreadBase.h" //线程基类
#include "Robot.h"      //机器人类


class RobotAsync :
	public ThreadBase
{
public:
    RobotAsync();
    ~RobotAsync();
    // 开始线程
    void start();
    // 结束线程
    void quite();
    // 向缓存队列中抛入消息
    void pushMsg(Msg msg);
private:
    // 重写线程的执行函数
    virtual void threadMain();
private:
    // 消息缓存
    std::queue<Msg> m_MsgBuffer;
    // 消息缓存在不同的线程中被操作，所以需要一个互斥锁
    std::mutex m_mutex;
    // 是否退出
    bool m_quit;
    // 机器人线程
    Robot m_robot;
};



