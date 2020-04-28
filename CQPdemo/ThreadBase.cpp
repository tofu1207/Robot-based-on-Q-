#include "ThreadBase.h"

ThreadBase::ThreadBase()
{
    m_thread = NULL;
}

ThreadBase::~ThreadBase()
{
}

void ThreadBase::start()
{
    if (m_thread == NULL)
    {
        std::shared_ptr<std::thread> p(new std::thread{ &ThreadBase::threadMain,this });
        m_thread = p;
    }
}

void ThreadBase::quit()
{
    
}