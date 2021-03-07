#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "user.h"
#include "student.h"

class Professor : public User
{
public:
    Professor(std::string name);
    void drop(Student &s); // drop student(set student's avg grade to 2)
};

#endif // PROFESSOR_H
