#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "user.h"
#include "student.h"
#include "director.h"
#include "labemployee.h"
#include "professor.h"
#include "admin.h"
#include "guest.h"

class Director;

class University
{
public:
    // users in university
    struct Pool {
        std::vector<Student> students;
        std::vector<Admin> admins;
        std::vector<Director> directors;
        std::vector<LabEmployee> lemployees;
        std::vector<Professor> professors;
        std::vector<Guest> guests;
    };
private:
    friend class Director;
    Pool p;
    std::vector<Room> rooms; // rooms in university
    std::string name; // name of university
    unsigned long long stipend;
    bool emergencyStatus; // true if now is emergency
    void doDailyStuff(User &u, std::string spec); // private method for inner implementation of start(int)
public:
    University(Pool p, std::vector<Room> r, std::string name, unsigned long long stipend);
    void start(int days); // start the life of the university with the number of iterations
    bool getEmergencyStatus() const;
    void setEmergencyStatus(bool value);
};

#endif // UNIVERSITY_H
