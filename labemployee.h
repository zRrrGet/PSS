#ifndef LABEMPLOYEE_H
#define LABEMPLOYEE_H

#include <string>
#include "user.h"
#include "accesslevel.h"

class LabEmployee : public User
{
public:
    enum Lab {   // types of labs
        Robotics, DS, Security, SE
    };
private:
    Lab lab; // what lab employee assigned to
public:
    LabEmployee(std::string name, Lab l);
    void work() const;  // to work(std::cout)
};

#endif // LABEMPLOYEE_H
