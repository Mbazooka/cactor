//
// Created by Mathis Boumaza on 03/02/2026.
//

#ifndef CACTOR_ACTOR_H
#define CACTOR_ACTOR_H

#include "Behavior.h"


class Actor {

public:
    Actor(Behavior beh);
    void change_behavior(Behavior beh);

private:
    Behavior beh;

};


#endif //CACTOR_ACTOR_H