#include "accesslevel.h"

void AccessLevel::setLevel(const AccessLevel::Level &value)
{
    level = value;
}

AccessLevel::AccessLevel(AccessLevel::Level l) : level(l)
{

}

AccessLevel::Level AccessLevel::getLevel() const
{
    return level;
}
