#include "student.h"

Student::Student(const std::string& name) : name(name) {}

std::string Student::getName() const {
    return name;
}

void Student::addRecommendation(const std::string& course) {
    if (recommendedCourses.size() < 3) {
        recommendedCourses.push_back(course);
    }
}

std::vector<std::string> Student::getRecommendations() const {
    return recommendedCourses;
}
