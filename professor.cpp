#include "professor.h"

Professor::Professor(std::string name) : User(name, AccessLevel::Level::yellow)
{
    addPhrase("What a wonderful day to drop someone!");
}

void Professor::drop(Student &s)
{
    s.avgGrade = 2;
}
