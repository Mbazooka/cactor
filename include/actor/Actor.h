//
// Created by Mathis Boumaza on 03/02/2026.
//

#ifndef CACTOR_ACTOR_H
#define CACTOR_ACTOR_H

#include "behavior.h"


class actor {

public:
    actor(behavior beh);
    void change_behavior(behavior beh);

private:
    behavior beh;

};


#endif //CACTOR_ACTOR_H