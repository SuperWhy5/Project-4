#ifndef RECOMMMEND_H
#define RECOMMMEND_H

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include "student.h"

class RecommendationSystem{
    private:
        std::map<std::string, Student> students;

        std::set<std::string> course;

    public:
        void loadData(const std::string& filename);

        std::vector<std::string> generateRecommendationsForStudent(const std::string& studentName) const;

        void outputRecommendations(std::ostream& out) const;

        int getTotalStudents() const;

        int getTotalCourses() const;

        int getTotalRecommendations() const;
        
};

#endif