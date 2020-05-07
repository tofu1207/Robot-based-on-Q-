#include "RobotAsync.h"
#include "PrivateMsg.h" //私聊消息

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
    bool ret = false;
    while (!m_quit)
    {
        if (m_MsgBuffer.size() > 0)
        {
            m_mutex.lock();
            Msg msg = m_MsgBuffer.front();
            m_MsgBuffer.pop();
            m_mutex.unlock();

            /*--------------------------------------------------------------------------------
            *----------------------------   处理消息队列   -----------------------------------*
             --------------------------------------------------------------------------------*/
            //text(msg, m_robot);
            
            // 处理交流方
            setPerson(msg.fromQQ);

                /*--------------------------------------------------------------------------------
                *----------------------------   私聊消息队列   -----------------------------------*
                 --------------------------------------------------------------------------------*/
            ret = false;
            if (msg.fromAddr == 0) {
                if (helloWorld(msg, m_robot)    |
                    sayName(msg, m_robot)       |
                    //sayCao(msg, m_robot)        |
                    sayAlive(msg, m_robot)      |
                    sayWork(msg, m_robot)
                    ) {

                    ret = true;
                }
            }
            if (ret == false) {
                // 无匹配时 回复(私聊)
                nomatch(msg, m_robot);
            }
         
                /*--------------------------------------------------------------------------------
                *----------------------------   群聊消息队列   -----------------------------------*
                 --------------------------------------------------------------------------------*/
            if (msg.fromAddr != 0) {    //注意, 群聊和讨论组发送消息的接口是不一样的
                

            }
        }
        else
        {
            // 无消息需要暂停, 如果cpu占用高的话, 可以调高
            Sleep(10);
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
    Robot crobot(ROBOTINI, PERSONINI);
    m_robot = crobot;
    m_quit = false;
    ThreadBase::start();
}

void RobotAsync::quite()
{
    ThreadBase::quit();
    m_quit = true;
}