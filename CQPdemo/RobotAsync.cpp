#include "RobotAsync.h"
#include "PrivateMsg.h" //˽����Ϣ

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
            *----------------------------   ������Ϣ����   -----------------------------------*
             --------------------------------------------------------------------------------*/
            //text(msg, m_robot);
            
            // ��������
            setPerson(msg.fromQQ);

                /*--------------------------------------------------------------------------------
                *----------------------------   ˽����Ϣ����   -----------------------------------*
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
                // ��ƥ��ʱ �ظ�(˽��)
                nomatch(msg, m_robot);
            }
         
                /*--------------------------------------------------------------------------------
                *----------------------------   Ⱥ����Ϣ����   -----------------------------------*
                 --------------------------------------------------------------------------------*/
            if (msg.fromAddr != 0) {    //ע��, Ⱥ�ĺ������鷢����Ϣ�Ľӿ��ǲ�һ����
                

            }
        }
        else
        {
            // ����Ϣ��Ҫ��ͣ, ���cpuռ�øߵĻ�, ���Ե���
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