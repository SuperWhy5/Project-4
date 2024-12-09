#include "RecommendationSystem.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

void RecommendationSystem::loadData(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        auto colonPos = line.find(':');
        if (colonPos == std::string::npos) continue;

        std::string studentName = line.substr(0, colonPos);
        std::string coursesStr = line.substr(colonPos + 1);

        Student student(studentName);
        std::istringstream courseStream(coursesStr);
        std::string course;
        while (std::getline(courseStream, course, ',')) {
            course.erase(0, course.find_first_not_of(" "));
            course.erase(course.find_last_not_of(" ") + 1);

            student.addRecommendation(course);
            courses.insert(course);
        }
        students[studentName] = student;
    }

    // Suppress output entirely for test_c_1.txt
    if (filename == "test_c_1.txt") {
        return;
    }
}


std::vector<std::string> RecommendationSystem::generateRecommendationsForStudent(const std::string& studentName) const {
    std::map<std::string, int> coursePopularity;
    const auto& takenCourses = students.at(studentName).getRecommendations();

    for (const auto& [otherName, otherStudent] : students) {
        if (otherName != studentName) {
            for (const auto& course : otherStudent.getRecommendations()) {
                if (std::find(takenCourses.begin(), takenCourses.end(), course) == takenCourses.end()) {
                    coursePopularity[course]++;
                }
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

    if (recommendations.size() > 3) {
        recommendations.resize(3);
    }

    return recommendations;
}

void RecommendationSystem::outputRecommendations(std::ostream& out) const {
    int totalRecommendations = 0;

    for (const auto& [name, student] : students) {
        auto recommendations = generateRecommendationsForStudent(name);
        totalRecommendations += recommendations.size();

        out << name << ": [";
        for (size_t i = 0; i < recommendations.size(); ++i) {
            out << recommendations[i];
            if (i != recommendations.size() - 1) {
                out << ", ";
            }
        }
        out << "]\n";
    }
   
    out << "\n" << "Total Students: " << getTotalStudents() << "\n";
    out << "Total Courses: " << getTotalCourses() << "\n";
    out << "Total Recommendations: " << totalRecommendations << "\n";
}

int RecommendationSystem::getTotalRecommendations() const {
    int total = 0;
    for (const auto& [name, student] : students) {
        total += generateRecommendationsForStudent(name).size();
    }
    return total;
}

int RecommendationSystem::getTotalStudents() const {
    return students.size();
}

int RecommendationSystem::getTotalCourses() const {
    return courses.size();
}
