#include "user.h"

User::User(std::string name, AccessLevel l) : name(name), level(l.getLevel())
{
    addPhrase("Hello, it's me - " + name);
}

AccessLevel::Level User::getLevel() const
{
    return level.getLevel();
}

void User::addPhrase(std::string p)
{
    phrases.push_back(p);
}

void User::openRoom(Room &r)
{
    if (r.isAccessable(this)) std::cout << "Room #" + std::to_string(r.getIndex()) + " is opened";
    else std::cout << "Failed to open room #" + std::to_string(r.getIndex());
    std::cout << std::endl;
}

void User::say() const
{
    int ind = rand() % phrases.size();
    std::cout << name+": " << phrases.at(ind) << std::endl;
}

std::string User::getName() const
{
    return name;
}
