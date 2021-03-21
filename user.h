#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include "accesslevel.h"
#include "room.h"

class Room;

class User
{
protected:
    std::string name;
    AccessLevel level; // level of access
    std::vector<std::string> phrases; // phrases to say
public:
    User(std::string name, AccessLevel l);
    void say() const; // say to std::cout
    std::string getName() const;
    AccessLevel::Level getLevel() const;
    void addPhrase(std::string p);
    void openRoom(Room &r);
};

#endif // USER_H
