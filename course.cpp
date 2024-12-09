#include "course.h"
#include <string>

Course::Course() : id("") {}

Course::Course(const std::string& id) : id(id) {}

std::string Course::getId() const { return id; }

bool Course::operator==(const Course& other) const { 
if (id == other.id) {
		return true;
	}
	else {
		return false;
	}    }

bool Course::operator<(const Course& other) const { 
	if (id < other.id) {
		return true;
	}
	else {
		return false;
	}    }



