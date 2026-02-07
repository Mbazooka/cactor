//
// Created by Mathis Boumaza on 03/02/2026.
//

#ifndef CACTOR_ACTORREF_H
#define CACTOR_ACTORREF_H

#include "Actor.h"
#include "Mailbox.h"
#include "Behavior.h"

template <typename T> requires std::is_aggregate_v<T>
class ActorRef {

public:
    ActorRef(/*Initial behavior, message types*/) = default;

    ~ActorRef() = default;

    void process_message(const ActorContext ctx) {};

private:
    std::unique_ptr<Actor<T>> actor;
    std::unique_ptr<Mailbox<T>> mailbox;
};


#endif //CACTOR_ACTORREF_H