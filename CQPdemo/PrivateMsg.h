#pragma once
#include "regexFun.h"   //�����ú���


// �����Ǵ���˽����Ϣ��

// ����
extern void text(Msg msg, Robot robot);

// �ʺ�
extern bool helloWorld(Msg msg, Robot robot);

// ������
extern bool sayName(Msg msg, Robot m_robot);

// С��С��
extern bool sayCao(Msg msg, Robot m_robot);

// �ڲ���?
extern bool sayAlive(Msg msg, Robot m_robot);

// �ڸ�����?
extern bool sayWork(Msg msg, Robot m_robot);

// ˽����Ϣ��ƥ��
extern void nomatch(Msg msg, Robot m_robot);