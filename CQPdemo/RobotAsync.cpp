#include "RobotAsync.h"


void RobotAsync::pushMsg(Msg msg)
{
    //����������Ϣ����100��  ��ֱ�������µ�����Ϣ
    if (m_MsgBuffer.size() < 100)
    {
        m_mutex.lock();
        m_MsgBuffer.push(msg);
        m_mutex.unlock();
    }
}

void RobotAsync::threadMain()
{
    while (!m_quit)
    {
        if (m_MsgBuffer.size() > 0)
        {
            m_mutex.lock();
            Msg msg = m_MsgBuffer.front();
            m_MsgBuffer.pop();
            m_mutex.unlock();

            /*
            ������Ϣ�Ĵ���
            */
            if (msg.msg == "ǳ��" && msg.fromQQ == MASTERQQ) {
                std::ostringstream m;
                m << m_robot;
                CQApi::sendPrivateMag(msg.fromQQ, m.str().c_str());
            }
        }
        else
        {
            // ����Ϣ��Ҫ��ͣ, ���cpuռ�øߵĻ�, �������
            Sleep(100);
        }
    }
    return;
}

RobotAsync::RobotAsync()
{
    
    m_quit = false;
}

RobotAsync::~RobotAsync()
{
}

void RobotAsync::start()
{
    Robot crobot("ShallowBird.ini", "Person.ini");
    m_robot = crobot;
    m_quit = false;
    ThreadBase::start();
}

void RobotAsync::quite()
{
    ThreadBase::quit();
    m_quit = true;
}