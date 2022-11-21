#ifndef __PROTECTED_QUEUE__
#define __PROTECTED_QUEUE__

#include <queue>
#include <mutex>

template <class T> class ProtectedQueue {
 private:
    std::mutex mutex;
    std::queue<T> queue;

 public:
    void push(T item) {
        std::lock_guard<std::mutex> lock(this->mutex);
        this->queue.push(item);
    }

    size_t size() {
        std::lock_guard<std::mutex> lock(this->mutex);
        return this->queue.size();
    }

    bool is_empty() {
        std::lock_guard<std::mutex> lock(this->mutex);
        return this->queue.size() == 0;
    }

    T pop() {
        std::lock_guard<std::mutex> lock(this->mutex);
        T item = this->queue.front();
        this->queue.pop();
        return item;
    }
};

#endif  //  __PROTECTED_QUEUE__
