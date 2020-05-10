#ifndef THREAD_H
#define THREAD_H

#include <thread>

class Thread {
    std::thread thread;
public:
    Thread();
    void start();
    virtual void run() = 0;
    void join();
    virtual ~Thread();
    Thread(const Thread&) = delete;
    Thread& operator=(const Thread&) = delete;
    Thread(Thread&& other);
    Thread& operator=(Thread&& other);
};


#endif // THREAD_H
