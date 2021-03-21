#include "room.h"
#include <algorithm>

Room::Type Room::getRt() const
{
    return rt;
}

bool Room::isAccessable(User *u) const
{
    AccessLevel::Level userLevel = u->getLevel();

    // everybody has access to class and everybody with red access has access to all rooms so true os returned
    if (rt == Room::Type::Class || userLevel == AccessLevel::Level::red) return true;

    switch (rt) {
        case Room::Type::Personal:
            if (userLevel == AccessLevel::Level::yellow &&
                    std::find_if(users.begin(), users.end(), // if user is present in "users" vector which regulate users who have access to room
                    [&u](const User &a){return a.getName()==u->getName();})!=users.end())
                return true;
            break;
        case Room::Type::Conference:
            if (userLevel == AccessLevel::Level::yellow)
                return true;
            break;
        case Room::Type::Laboratory:
            if (userLevel == AccessLevel::Level::green)
                return true;
            break;
        case Room::Type::Lecture:
            if (userLevel != AccessLevel::Level::no_level)
                return true;
            break;
    }
    return false;
}

unsigned int Room::getIndex() const
{
    return index;
}

Room::Room(unsigned int index, Room::Type type) : index(index), rt(type)
{

}

Room::Room(unsigned int index, User &u) : index(index), rt(Type::Personal)
{
    users.push_back(u);
}
