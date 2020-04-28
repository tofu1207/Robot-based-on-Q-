#pragma once

#include <thread>

class ThreadBase
{
public:
    ThreadBase();
    virtual ~ThreadBase();
    virtual void start();
    virtual void quit();
protected:
    virtual void threadMain() = 0;
private:
    std::shared_ptr<std::thread> m_thread;
};