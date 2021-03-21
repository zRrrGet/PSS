#ifndef GUEST_H
#define GUEST_H

#include "user.h"

class Guest : public User
{
public:
    Guest(std::string name);
    void lookThoroughly();
};

#endif // GUEST_H
