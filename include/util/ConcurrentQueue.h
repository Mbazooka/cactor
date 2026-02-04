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
    void enqueue(T value);
    T dequeue();
    bool is_queued();

private:
    std::queue<T> q;
    std::recursive_mutex m;


};


#endif //CACTOR_CONCURRENTQUEUE_H