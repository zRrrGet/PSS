#include "student.h"


float Student::getAvgGrade() const
{
    return avgGrade;
}

Student::Student(std::string name, float avgGrade) : User(name, AccessLevel::Level::no_level)
{
    this->avgGrade = avgGrade;
    addPhrase("What a wonderful day to study!");
    addPhrase("I don't want me be dropped.");
}

void Student::studyHard()
{
    avgGrade+=0.1;
    if (avgGrade>5) avgGrade = 5;
}
