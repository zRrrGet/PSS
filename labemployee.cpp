#include "labemployee.h"

LabEmployee::LabEmployee(std::string name, Lab l) : User(name, AccessLevel::Level::green) {
    lab = l;
    addPhrase("Inventing stuff today...");
}

void LabEmployee::work() const
{
    std::cout << "Working at ";
    switch (lab) {
        case Lab::Robotics:
            std::cout << "Robotics";
            break;
        case Lab::DS:
            std::cout << "Data Science";
            break;
        case Lab::Security:
            std::cout << "Security";
            break;
        case Lab::SE:
            std::cout << "Software Engineering";
            break;
        default: // if not all cases of the enum are covered
            throw std::runtime_error("In labemployee.cpp, work(): not all switch cases are covered(add cases for all enum values)");
    }
    std::cout << " laboratory..." << std::endl;
}
