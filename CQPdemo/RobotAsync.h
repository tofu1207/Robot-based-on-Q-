#pragma once

#include <queue>
#include <mutex>
#include <Windows.h>

#include "ThreadBase.h"
#include "Robot.h"
#include "CQApi.h"


struct Msg
{
    int32_t msgId;
    int64_t fromAddr;   // ˽��Ϊ0
    int64_t fromQQ;
    std::string msg;

    Msg(int32_t msgId, int64_t fromAddr, int64_t fromQQ, std::string msg)
        :msgId(msgId), fromQQ(fromQQ), fromAddr(fromAddr), msg(msg) {}
};

class RobotAsync :
	public ThreadBase
{
public:
    RobotAsync();
    ~RobotAsync();
    // ��ʼ�߳�
    void start();
    // �����߳�
    void quite();
    // �򻺴������������Ϣ
    void pushMsg(Msg msg);
private:
    // ��д�̵߳�ִ�к���
    virtual void threadMain();
private:
    // ��Ϣ����
    std::queue<Msg> m_MsgBuffer;
    // ��Ϣ�����ڲ�ͬ���߳��б�������������Ҫһ��������
    std::mutex m_mutex;
    // �Ƿ��˳�
    bool m_quit;
    // �������߳�
    Robot m_robot;
};



