//
// Created by Mathis Boumaza on 03/02/2026.
//

#ifndef CACTOR_ACTORREF_H
#define CACTOR_ACTORREF_H

#include "Actor.h"
#include "Mailbox.h"

class ActorRef {

public:
    ActorRef();

private:
    Actor actor;
    //Mailbox mailbox;

};


#endif //CACTOR_ACTORREF_H