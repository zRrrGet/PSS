#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include "accesslevel.h"

class Admin : public User {
public:
    Admin(std::string name);
    void breakMoodle(); // to break moodle(basically, just a std::cout message)
    void grantAccess(User &u, Room &r); // grant u access to r
};

#endif // ADMIN_H
