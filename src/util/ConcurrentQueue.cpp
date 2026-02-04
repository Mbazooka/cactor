//
// Created by Mathis Boumaza on 03/02/2026.
//

#include "util/ConcurrentQueue.h"

template<typename T>
void ConcurrentQueue<T>::enqueue(T value) {
    std::lock_guard<std::recursive_mutex> lock(m);
    q.push(value);
}

template<typename T>
T ConcurrentQueue<T>::dequeue() {
    std::lock_guard<std::recursive_mutex> lock(m);
    if (!q.empty()) {
        T value = q.front();
        q.pop();
        return value;
    } else {
        throw std::runtime_error("Queue is empty");
    }
}

template<typename T>
bool ConcurrentQueue<T>::is_queued() {
    std::lock_guard<std::recursive_mutex> lock(m);
    return !q.empty();
}
