#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "university.h"
#include "user.h"

class University;

class Director : public User
{
public:
    Director(std::string name);
    void decreaseStipend(University *u); // decrease stipend of u by 2
};

#endif // DIRECTOR_H
