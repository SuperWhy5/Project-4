#include <iostream>
#include "recommendationSystem.h"

int main() {
    RecommendationSystem rs;
    rs.loadData("Test_c_1.txt");

    std::cout << "Total Students: " << rs.getTotalStudents() << std::endl;
    std::cout << "Total Courses: " << rs.getTotalCourses() << std::endl;

    rs.outputRecommendations(std::cout);
    return 0;
}
