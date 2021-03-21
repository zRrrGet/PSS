#include "director.h"

Director::Director(std::string name) : User(name, AccessLevel::Level::yellow)
{
    addPhrase("Need more money.");
}

void Director::decreaseStipend(University *u)
{
    u->stipend/=2;
}
