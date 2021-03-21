#include "guest.h"

Guest::Guest(std::string name) : User(name, AccessLevel::Level::blue)
{
    addPhrase("Wow!");
}

void Guest::lookThoroughly()
{
    std::cout << "*Looking thoroughly*" << std::endl;
}
