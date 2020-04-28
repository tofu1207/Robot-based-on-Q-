#include "RobotAsync.h"


void RobotAsync::pushMsg(Msg msg)
{
    //如果缓存的消息大于100条  则直接抛弃新到的消息
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
            处理消息的代码
            */
            if (msg.msg == "浅鸟" && msg.fromQQ == MASTERQQ) {
                std::ostringstream m;
                m << m_robot;
                CQApi::sendPrivateMag(msg.fromQQ, m.str().c_str());
            }
        }
        else
        {
            // 无消息需要暂停, 如果cpu占用高的话, 建议调高
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