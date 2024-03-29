#include <iomanip>
#include "university.h"

bool University::getEmergencyStatus() const
{
    return emergencyStatus;
}

void University::setEmergencyStatus(bool value)
{
    for(Room &a : rooms)
        a.isOpened = value;
    emergencyStatus = value;
}

void University::doDailyStuff(User &u, std::string spec)
{
    std::cout << spec+" ";
    if (spec=="Student") {
        std::cout << "average grade ";
        std::cout << std::fixed << std::setprecision(2) << static_cast<Student&>(u).getAvgGrade() << " ";
    }
    u.say();
    if (!(rand()%5)) u.openRoom(rooms.at(rand()%rooms.size()));
}

University::University(University::Pool p, std::vector<Room> r, std::string name, unsigned long long stipend)
    : p(p), rooms(r), name(name), stipend(stipend), emergencyStatus(false)
{
    std::cout << name+" University is ready" << std::endl;
}

void University::start(int days) // mostly, things in university are done by random(that's life)
{
    for (int i = 1;i <= days; ++i) {
        std::cout << "Day: " << std::to_string(i) << std::endl;
        // will today be emergency
        if (!(rand()%5)) {
            setEmergencyStatus(true);
            std::cout << "Emergency! All doors are opened" << std::endl;
        }

        std::cout << "<------------Guests------------>" << std::endl;
        // every user do daily stuff and specific for them things which are randomly determined
        for (Guest &a : p.guests) {
            doDailyStuff(a, "Guest");
            if (rand()%2) {
                a.lookThoroughly();
            }
        }
        std::cout << "<------------Students(current stipend:" << stipend << ")------------>" << std::endl;
        for (Student &a : p.students) {
            doDailyStuff(a, "Student");
            if (rand()%2) {
                std::cout << "studying..." << std::endl;
                a.studyHard();
            }
        }
        std::cout << "<------------Professors------------>" << std::endl;
        for (Professor &a : p.professors) {
            doDailyStuff(a, "Professor");
            for (Student &s : p.students) {
                if (!(rand()%30)) {
                    a.drop(s);
                    std::cout << "Student " + s.getName() + " was dropped on retake." << std::endl;
                }
            }
        }
        std::cout << "<------------Lab Employees------------>" << std::endl;
        for (LabEmployee &a : p.lemployees) {
            doDailyStuff(a, "Lab employee");
            a.work();
        }
        std::cout << "<------------Directors------------>" << std::endl;
        for (Director &a : p.directors) {
            doDailyStuff(a, "Director");
            if (!(rand()%3)) {
                a.decreaseStipend(this);
                std::cout << "Stipend is gone... Now it's "+std::to_string(stipend) << std::endl;
            }
        }
        std::cout << "<--------------Admins------------->" << std::endl;
        for (Admin &a : p.admins) {
            doDailyStuff(a, "Admin");
            if (!(rand()%3)) a.breakMoodle();
        }
        std::cout << "University goes sleep. Press Enter to enter a new day";
        std::cin.ignore(std::cin.rdbuf()->in_avail()+1);
        for (int i = 0;i < 100;++i) std::cout << std::endl;

        // if today was emergency, call off emergency status
        if (getEmergencyStatus()) setEmergencyStatus(false);

    }
}
