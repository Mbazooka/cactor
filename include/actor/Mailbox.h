//
// Created by Mathis Boumaza on 03/02/2026.
//

#ifndef CACTOR_MAILBOX_H
#define CACTOR_MAILBOX_H
#include <queue>
#include <iostream>

// TO DO:
// Make it lock free

template <typename T> requires std::is_aggregate_v<T>
class Mailbox {

public:
    Mailbox() = default;
    void send_message(T value) {
        std::lock_guard lock(m);
        q.push(value);
        std::cout << "Received" << std::endl;
    }

    ~Mailbox() = default;

    std::optional<T> get_message() {
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


#endif //CACTOR_MAILBOX_H