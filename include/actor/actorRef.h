//
// Created by Mathis Boumaza on 03/02/2026.
//

#ifndef CACTOR_ACTORREF_H
#define CACTOR_ACTORREF_H

#include "actor.h"
#include "mailbox.h"

class actorRef {

public:
    actorRef();

private:
    actor actor;
    //Mailbox<> mailbox;

};


#endif //CACTOR_ACTORREF_H