#ifndef ROOM_H
#define ROOM_H

#include "user.h"

class User;

class Room
{
public:
    enum Type {  // types of rooms
        Class, Lecture, Personal, Conference, Laboratory
    };
private:
    friend class Admin;
    Type rt; // type of room
    unsigned int index; // room's number
    std::vector<User> users; // users who have access to room
public:
    Room(unsigned int index, Type type);
    Room(unsigned int index, User &u); // create personal room for u
    Type getRt() const;
    bool isAccessable(User *u) const; // is room can be accessed by u
    unsigned int getIndex() const;
};

#endif // ROOM_H
