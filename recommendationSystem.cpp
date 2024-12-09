#include <iostream>
#include <algorithm>
#include <sstream>
#include "recommendationSystem.h"

void RecommendationSystem::loadData(const std::string& filename){
    std::ifstream myFile(filename);

    std::string line;
    while(std::getline(myFile, line))
        std::istringstream iss(line);
        std::string studentName;
        if(std::getline(iss, studentName, ':')){
            std::string listOfCourses;
            if(std::getline(iss, listOfCourses)){
                Student student(studentName);
                std::istringstream coursesStream(listOfCourses);
                std::string course;
                while(std::getline(coursesStream, course, ',')){
                    course.erase(course.find_last_not_of(" \t\n\r")+1);
                    course.erase(0, course.find_last_not_of(" \t\n\r"));

                    student.addRecommendation(course);
                    this-> course.insert(course);
                }
                students[studentName] = student;
            }
        }
}

std::vector<std::string> RecommendationSystem::generateRecommendationsForStudent(const std::string& studentName) const{
    auto it = student.find(studentName);
    
    const Student& student = it->second;
    std::vector<std::string> studentCourses = student.getRecommendations();
    std::map<std::string, int> coursePopularity;

     for (const auto& pair : students) {
        if (pair.first == studentName) continue; // Skip the current student

        for (const auto& course : pair.second.getRecommendations()) {
            if (std::find(studentCourses.begin(), studentCourses.end(), course) == studentCourses.end()) {
                coursePopularity[course]++;
            }
        }
    }

    std::vector<std::string> recommendations;
    for (const auto& pair : coursePopularity) {
        recommendations.push_back(pair.first);
    }
    std::sort(recommendations.begin(), recommendations.end(), [&coursePopularity](const std::string& a, const std::string& b) {
        if (coursePopularity[a] != coursePopularity[b]) {
            return coursePopularity[a] > coursePopularity[b];
        }
        return a < b; // Alphabetical order for ties
    });

    // Limit to top 3 recommendations
    if (recommendations.size() > 3) {
        recommendations.resize(3);
    }
    return recommendations;
}

void RecommendationSystem::outputRecommendations(std::ostream& out) const{
    int totalRecommendations = 0;

    for (const auto& pair : students) {
        out << pair.first << ": [";
        std::vector<std::string> recommendations = generateRecommendationsForStudent(pair.first);

        for (size_t i = 0; i < recommendations.size(); ++i) {
            out << recommendations[i];
            if (i < recommendations.size() - 1) {
                out << ", ";
            }
        }
        out << "]\n";

        totalRecommendations += recommendations.size();
    }

    out << "Total Students: " << getTotalStudents() << "\n";
    out << "Total Courses: " << getTotalCourses() << "\n";
    out << "Total Recommendations: " << totalRecommendations << "\n";
}

int RecommendationSystem::getTotalStudents() const{
    return students.size();
}

int RecommendationSystem::getTotalCourses() const{
    return course.size()
}

int RecommendationSystem::getTotalRecommendations() const{
    int total = 0;
    for (const auto& pair : students) {
        total += pair.second.getRecommendations().size();
    }
    return total; 
}

