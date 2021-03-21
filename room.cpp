#include "room.h"
#include <algorithm>
Room::Type Room::getRt() const
{
    return rt;
}

bool Room::isAccessable(User *u) const
{
    AccessLevel::Level userLevel = u->getLevel();

    // if it is opened or user has red access level
    if (isOpened || userLevel == AccessLevel::Level::red) return true;

    switch (rt) {
        case Room::Type::Personal:
            if (userLevel == AccessLevel::Level::yellow &&
                    std::find_if(users.begin(), users.end(), // if user is present in "users" vector which regulate users who have access to room
                    [&u](const User &a){return a.getName()==u->getName();})!=users.end())
                return true;
            break;
        case Room::Type::Conference:
            if ((userLevel == AccessLevel::Level::yellow) || (userLevel == AccessLevel::Level::blue && floor==1))
                return true;
            break;
        case Room::Type::Laboratory:
            if (userLevel == AccessLevel::Level::green)
                return true;
            break;
        case Room::Type::Lecture:
            if ((userLevel != AccessLevel::Level::no_level && userLevel != AccessLevel::Level::blue)
                    || (userLevel == AccessLevel::Level::blue && floor==1))
                return true;
            break;
        case Room::Type::Class:
            if (userLevel != AccessLevel::Level::blue) return true;
            break;
        default: // if not all cases of the enum are covered
            throw std::runtime_error("In room.cpp, isAccessible(User*): not all switch cases are covered(add cases for all enum values)");
    }
    return false;
}

int Room::getIndex() const
{
    return index;
}

int Room::getFloor() const
{
    return floor;
}

bool Room::getIsOpened() const
{
    return isOpened;
}

Room::Room(int index, int floor, Room::Type type) : index(index), floor(floor), rt(type), isOpened(false)
{

}

Room::Room(int index, int floor, User &u) : index(index), floor(floor), rt(Type::Personal), isOpened(false)
{
    users.push_back(u);
}
