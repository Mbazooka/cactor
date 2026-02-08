//
// Created by Mathis Boumaza on 03/02/2026.
//

#ifndef CACTOR_ACTOR_H
#define CACTOR_ACTOR_H

#include <memory>

#include "Behavior.h"

// Shared pointers?

template <typename T> requires std::is_aggregate_v<T>
class Actor {

public:
    Actor(std::shared_ptr<Behavior<T>> beh) : behavior(beh) {};

    ~Actor() = default;

    void change_behavior(std::shared_ptr<Behavior<T>> beh) {
        this->behavior = beh;
    };

    std::shared_ptr<Behavior<T>> get_behavior() {
      return this->behavior;
    };

private:
    std::shared_ptr<Behavior<T>> behavior;

};


#endif //CACTOR_ACTOR_H