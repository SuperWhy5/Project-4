#include <iostream>
#include "course.h"


Course::Course(const std::string& id) : id(id) {}

std::string Course::getId() const{
    return id;
}

bool Course::operator == (const Course& other) const{
    return id == other.id;
}

bool Course::operator < (const Course& other) const{
    return id < other.id;
}
