#ifndef CACTOR_BEHAVIOR_H
#define CACTOR_BEHAVIOR_H
#include <type_traits>
#include "ActorContext.h"

template <typename T> requires std::is_aggregate_v<T>
class Behavior {

public:
    Behavior() = default;
    virtual void onReceiveMessage(ActorContext context, T message) =0;

    virtual ~Behavior() = default;

private:
    const ActorContext context;
};


#endif //CACTOR_BEHAVIOR_H