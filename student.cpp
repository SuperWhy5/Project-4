
#include "student.h"
#include <string>
#include <vector>
#include <algorithm>

Student::Student() : name("") {}

Student::Student(const string& name) : name(name) {
    recommendedCourses = vector<string>();
}
std::string Student::getName() const {
    return name;
}

void Student::addRecommendation(const std::string& course) {
    if (std::find(recommendedCourses.begin(), recommendedCourses.end(), course) == recommendedCourses.end()) {
        recommendedCourses.push_back(course);
    }
}

std::vector<std::string> Student::getRecommendations() const {
    return recommendedCourses;
}



