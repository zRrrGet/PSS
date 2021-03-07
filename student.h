#ifndef STUDENT_H
#define STUDENT_H

#include "user.h"
#include "accesslevel.h"

class Student : public User
{
private:
    friend class Professor;
    float avgGrade; // average grade
public:
    Student(std::string name, float avgGrade);
    void studyHard(); // +0.1 to average grade
    float getAvgGrade() const;
};

#endif // STUDENT_H
