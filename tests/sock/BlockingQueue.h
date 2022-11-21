#ifndef __BLOCKING_QUEUE__
#define __BLOCKING_QUEUE__

#include <cstddef>
#include <queue>
#include <mutex>
#include <condition_variable>

template<class T>
class BlockingQueue {
 private:
    std::queue<T> queue;
    std::mutex mutex;
    std::condition_variable cond_variable;

    void wait_while_empty(std::unique_lock<std::mutex> &lock) {
        while (this->queue.empty())
            this->cond_variable.wait(lock);
    }

 public:
    void push(T& item) {
        std::unique_lock<std::mutex> lock(this->mutex);

        this->queue.push(item);
        this->cond_variable.notify_all();
    }

    std::size_t size() {
        std::unique_lock<std::mutex> lock(this->mutex);
        return this->queue.size();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(this->mutex);
        this->wait_while_empty(lock);

        T item = this->queue.front();
        this->queue.pop();

        return item;
    }


};

#endif  //  __BLOCKING_QUEUE__
