//
// Created by Mathis Boumaza on 03/02/2026.
//

#ifndef CACTOR_ACTORREF_H
#define CACTOR_ACTORREF_H

#include "Actor.h"
#include "Mailbox.h"
#include "Behavior.h"

#include <iostream>

template <typename T> requires std::is_aggregate_v<T>
class ActorRef {

public:
    ActorRef(Behavior<T> behavior) : actor(new Actor<T>), mailbox(new Mailbox<T>) {
        std::cout << "Created actorRef" << std::endl;
    };

    ~ActorRef() = default;

    void send_message(T message) {
        mailbox->send_message(message);
    };

    bool process_message(const ActorContext context) {
        std::optional<T> optionalMessage(mailbox->get_message());
        if (optionalMessage.has_value()) {
            actor->beh.onReceiveMessage(context, optionalMessage.value());
            return true;
        } else {
            return false;
        }
    };

private:
    std::unique_ptr<Actor<T>> actor;
    std::unique_ptr<Mailbox<T>> mailbox;
};


#endif //CACTOR_ACTORREF_H