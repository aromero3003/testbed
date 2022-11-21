#include <iostream>
#include <thread>

#ifndef THREAD_H
#define THREAD_H

class Thread {
private:
    std::thread t;

    void runExpecting();
protected:
    virtual void run() = 0;

public:
    void start();

    void join();

    virtual ~Thread();
};

#endif