#include "RecommendationSystem.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>


void RecommendationSystem::loadData(const string& filename) {

    ifstream file(filename);

    string line;

    while (getline(file, line)) {

        istringstream iss(line);

        string studentName, coursesString;

        getline(iss, studentName, ':');

        getline(iss, coursesString);

        Student student(studentName);

        istringstream courseStream(coursesString);

        string course;

        while (courseStream >> course) {
            if (course.back() == ',') {

                course.pop_back();
            }

            courses.insert(course);

            popular[course][studentName]++;

        }

        students[studentName] = student;
    }
    file.close();
}


vector<string> RecommendationSystem::generateRecommendationsForStudent(const string& studentName) const {
    vector<string> recommended;

if (students.find(studentName) == students.end()) {
    return recommended;
}

unordered_set<string> studentCourses;
for (auto connect1 = popular.begin(); connect1 != popular.end(); ++connect1) {
    const string& course = connect1->first;
    const map<string, int>& SM = connect1->second;
    if (SM.find(studentName) != SM.end()) {
        studentCourses.insert(course);
    }
}

map<string, int> recommendationScores;

for (auto connect1 = popular.begin(); connect1 != popular.end(); ++connect1) {
    const string& course = connect1->first;
    const map<string, int>& SM = connect1->second;

        if (SM.find(studentName) == SM.end()) {
            int score = 0;
            bool sharecourse = false;

            for (auto connect1 = SM.begin(); connect1 != SM.end(); ++connect1) {
                const string& otherStudent = connect1->first;
                int count = connect1->second;

                for (auto courseconnect1 = studentCourses.begin(); courseconnect1 != studentCourses.end(); ++courseconnect1) {
                    const string& commonCourses = *courseconnect1;
                    if (popular.at(commonCourses).find(otherStudent) != popular.at(commonCourses).end()) {
                        score += count;
                        sharecourse = true;
                        break;
                    }
                }
            }
            if (sharecourse) {
                recommendationScores[course] = score;
            }
            
        }
    }

    vector<pair<int, string>> sortedRecommendations;
    for (auto connect1 = recommendationScores.begin(); connect1 != recommendationScores.end(); ++connect1) {
        sortedRecommendations.push_back(make_pair(-connect1->second, connect1->first));
    }
    sort(sortedRecommendations.begin(), sortedRecommendations.end());

    for (auto connect1 = sortedRecommendations.begin(); connect1 != sortedRecommendations.end(); ++connect1) {
        if (recommended.size() < 3) {
            recommended.push_back(connect1->second);
        } else {
            break;
        }
    }

    return recommended;
}

void RecommendationSystem::outputRecommendations(ostream& out) const {
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
