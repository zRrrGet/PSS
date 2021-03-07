#include "admin.h"

Admin::Admin(std::string name) : User(name, AccessLevel::Level::red)
{
    addPhrase("Try reloading");
}

void Admin::breakMoodle()
{
    std::cout << "Moodle don't respond. Again..." << std::endl;
}

void Admin::grantAccess(User &u, Room &l)
{
    l.users.push_back(u);
}
