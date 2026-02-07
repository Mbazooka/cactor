#ifndef CACTOR_CONCURRENTQUEUE_H
#define CACTOR_CONCURRENTQUEUE_H
#include <queue>
#include <vector>

// TO DO:
// Make it lock free

template <typename T>
class ConcurrentQueue {

public:
    ConcurrentQueue() = default;
    void enqueue(T value) {
        std::lock_guard lock(m);
        q.push(value);
    }

    ~ConcurrentQueue() = default;

    std::optional<T> dequeue() {
        std::lock_guard lock(m);
        if (!q.empty()) {
            T value = q.front();
            q.pop();
            return value;
        }
        return std::nullopt;
    }

private:
    std::queue<T> q;
    std::recursive_mutex m;
};


#endif //CACTOR_CONCURRENTQUEUE_H