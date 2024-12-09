#include "recommendationSystem.h"
#include <sstream>
#include <algorithm>
#include <iostream>

void RecommendationSystem::loadData(const std::string& filename) {
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string studentName, coursesPart;

        std::getline(iss, studentName, ':');
        std::getline(iss, coursesPart);

        studentName.erase(0, studentName.find_first_not_of(" \t"));
        studentName.erase(studentName.find_last_not_of(" \t") + 1);

        Student student(studentName);
        std::istringstream coursesStream(coursesPart);
        std::string course;

        while (std::getline(coursesStream, course, ',')) {
            course.erase(0, course.find_first_not_of(" \t"));
            course.erase(course.find_last_not_of(" \t") + 1);
            courses.insert(course); // Correctly updates the set
        }

        students[studentName] = student;
    }
}

std::vector<std::string> RecommendationSystem::generateRecommendationsForStudent(const std::string& studentName) const {
    std::map<std::string, int> coursePopularity;

    for (const auto& [otherStudentName, otherStudent] : students) {
        if (otherStudentName != studentName) {
            auto otherCourses = otherStudent.getRecommendations();
            for (const auto& course : otherCourses) {
                coursePopularity[course]++;
            }
        }
    }

    std::vector<std::string> recommendations;
    for (const auto& [course, count] : coursePopularity) {
        recommendations.push_back(course);
    }

    std::sort(recommendations.begin(), recommendations.end(), [&coursePopularity](const std::string& a, const std::string& b) {
        if (coursePopularity[a] != coursePopularity[b]) {
            return coursePopularity[a] > coursePopularity[b];
        }
        return a < b;
    });

    return recommendations;
}

void RecommendationSystem::outputRecommendations(std::ostream& out) const {
    int totalRecommendations = 0;

    // Iterate over each student
    for (const auto& [name, student] : students) {
        auto recommendations = generateRecommendationsForStudent(name);
        totalRecommendations += recommendations.size();

        // Output the recommendations in the required format
        out << name << ": [";
        for (size_t i = 0; i < recommendations.size(); ++i) {
            out << recommendations[i];
            if (i != recommendations.size() - 1) {
                out << ", ";
            }
        }
        out << "]\n";
    }

    // Output the global summary
    out << "Total Students: " << getTotalStudents() << "\n";
    out << "Total Courses: " << getTotalCourses() << "\n";
    out << "Total Recommendations: " << totalRecommendations << "\n";
}

int RecommendationSystem::getTotalStudents() const {
    return students.size();
}

int RecommendationSystem::getTotalCourses() const {
    return courses.size();
}

int RecommendationSystem::getTotalRecommendations() const {
    int total = 0;
    for (const auto& [_, student] : students) {
        total += student.getRecommendations().size();
    }
    return total;
}
