#ifndef LOCK_H
#define LOCK_H

#include <mutex>

class Lock {
    std::mutex& mutex;
public:
    explicit Lock(std::mutex &mutex) : mutex(mutex) {
        mutex.lock();
    }
    ~Lock() {
        mutex.unlock();
    }
    Lock(const Lock&) = delete;
    Lock& operator=(const Lock&) = delete;
    Lock(Lock&&) = delete;
    Lock& operator=(Lock&&) = delete;
};

#endif // LOCK_H
