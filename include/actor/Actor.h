//
// Created by Mathis Boumaza on 03/02/2026.
//

#ifndef CACTOR_ACTOR_H
#define CACTOR_ACTOR_H

#include "Behavior.h"

// Shared pointers?

template <typename T> requires std::is_aggregate_v<T>
class Actor {

public:
    Actor(Behavior<T> beh) : beh(beh) {};

    void change_behavior(Behavior<T> behavior) {
        this->beh = behavior;
    };

private:
    Behavior<T> beh;

};


#endif //CACTOR_ACTOR_H