#ifndef RECOMMMEND_H
#define RECOMMMEND_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include "Student.h"
#include "Course.h"

class RecommendationSystem{
    private:
        std::map<std::string, Student> students;

        std::set<std::string> courses;

        std::map<std::string,std::map<std::string, int>> popular;

    public:
        void loadData(const std::string& filename);

        std::vector<std::string> generateRecommendationsForStudent(const std::string& studentName) const;

        void outputRecommendations(std::ostream& out) const;

        int getTotalStudents() const;

        int getTotalCourses() const;

        int getTotalRecommendations() const;
        

        
};

#endif