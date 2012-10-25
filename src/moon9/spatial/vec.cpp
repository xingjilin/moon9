#include <iostream>

#include "vec.hpp"

std::ostream &operator<<( std::ostream &os, const moon9::vec3 &v )
{
    os << '{' << v.x << ',' << v.y << ',' << v.z << '}';
    return os;
}