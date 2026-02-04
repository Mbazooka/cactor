//
// Created by Mathis Boumaza on 03/02/2026.
//

#ifndef CACTOR_CONCURRENTQUEUE_H
#define CACTOR_CONCURRENTQUEUE_H
#include <queue>
#include <vector>


template <typename T>
class ConcurrentQueue {

public:
    ConcurrentQueue() = default;
    void enqueue(T value) {
        std::lock_guard lock(m);
        q.push(value);
    }

    T dequeue() {
        std::lock_guard lock(m);
        if (!q.empty()) {
            T value = q.front();
            q.pop();
            return value;
        } else {
            throw std::runtime_error("Queue is empty");
        }
    }

    // Determines whether the queue is non-empty. Bad interleavings may occur.
    bool is_queued() {
        std::lock_guard lock(m);
        return !q.empty();
    }

private:
    std::queue<T> q;
    std::recursive_mutex m;


};


#endif //CACTOR_CONCURRENTQUEUE_H