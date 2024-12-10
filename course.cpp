#include "course.h"
#include <string>
#include <algorithm>
#include <cctype>

// Helper function to trim whitespace/newline
std::string trimString(const std::string& str) {
    size_t start = str.find_first_not_of(" \n\r\t");
    size_t end = str.find_last_not_of(" \n\r\t");

    if (start == std::string::npos || end == std::string::npos) {
        return "";
    }

    return str.substr(start, end - start + 1);
}

Course::Course() : id("") {}

Course::Course(const std::string& id) : id(trimString(id)) {}

std::string Course::getId() const { return id; }

bool Course::operator==(const Course& other) const { 
    return id == other.id;
}

bool Course::operator<(const Course& other) const { 
    return id < other.id;
}
