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
    friend class University; // we can change properties of rooms from University class as the rooms are part of the University
    Type rt; // type of room
    int index; // room's number
    int floor; // floor's number
    bool isOpened;
    std::vector<User> users; // users who have access to room
public:
    Room(int index, int floor, Type type);
    Room(int index, int floor, User &u); // create personal room for u
    Type getRt() const;
    bool isAccessable(User *u) const; // is room can be accessed by u
    int getIndex() const;
    int getFloor() const;
    bool getIsOpened() const;
};

#endif // ROOM_H
