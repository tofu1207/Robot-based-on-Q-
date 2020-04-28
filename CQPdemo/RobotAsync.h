#pragma once

#include <queue>
#include <mutex>
#include <Windows.h>
#include "ThreadBase.h" //�̻߳���
#include "Robot.h"      //��������


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



