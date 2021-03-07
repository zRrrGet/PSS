#include <iostream>
#include "university.h"

int main() {

    srand(time(0));

    University::Pool p;
    // init students
    const std::vector<std::string> studentNames = {"Maria", "Natali", "Alexandr", "Mikhail",
                                        "Ivan", "Ilya", "Dmitriy", "Albert",
                                        "Anna", "Egor", "Roman", "Ruslan",
                                       "Pavel", "Artem", "Alexey", "Sergey"};
    for (const std::string &name : studentNames)
        p.students.push_back(Student(name, 4));
    p.students.at(4).addPhrase("Math is saint!");

    // init employees
    const std::vector<std::string> employeeNames = {"Bulich", "Maria", "Natali", "Alexandr",
                                        "Ivan", "Ilya", "Dmitriy", "Albert"};
    for (size_t i = 1;i <= employeeNames.size(); ++i)
        p.lemployees.push_back(LabEmployee(employeeNames.at(i-1),
                                           static_cast<LabEmployee::Lab>(i/2)));
    // adding phrases
    p.lemployees.at(0).addPhrase("The test will be easy, should be max grade");
    p.lemployees.at(0).addPhrase("Don't call me Bulich");

    // init professors
    const std::vector<std::string> professorNames = {"Gorodos", "Tormasov", "Kholodov", "Shilov"};
    for (const std::string &name : professorNames)
        p.professors.push_back(Professor(name));
    // adding phrases
    p.professors.at(0).addPhrase("You should know it from school!");
    p.professors.at(0).addPhrase("Midterm approaches...");
    p.professors.at(1).addPhrase("Basically, hazards are inevitable");
    p.professors.at(2).addPhrase("I know English");
    p.professors.at(3).addPhrase("I'm lord");
    p.professors.at(3).addPhrase("Let's prove pi equals three");

    // init admins
    const std::vector<std::string> adminNames = {"Anonymous", "Hacker1337"};
    for (const std::string &name : adminNames)
        p.admins.push_back(Admin(name));

    // init director
    p.directors.push_back(Director("Seminikhin"));
    // adding phrases
    p.directors.at(0).addPhrase("Stipend is our will");
    p.directors.at(0).addPhrase("Need more gold");
    p.directors.at(0).addPhrase("It is the market");

    // init rooms
    std::vector<Room> rooms;
    // personal room for director
    rooms.push_back(Room(501, p.directors.at(0)));
    // personal rooms for all professors
    for (size_t i = 0;i < p.professors.size(); ++i)
        rooms.push_back(Room(502+i, p.professors.at(i)));
    // adding specific rooms
    rooms.push_back(Room(312, Room::Type::Class));
    rooms.push_back(Room(408, Room::Type::Laboratory));
    rooms.push_back(Room(108, Room::Type::Lecture));
    rooms.push_back(Room(100, Room::Type::Conference));

    // example of granting access to user from admin
    p.admins.at(0).grantAccess(p.professors.at(3), rooms.at(0));

    University innopolis(p, rooms, "Innopolis", 36000);
    innopolis.start(3);
}
