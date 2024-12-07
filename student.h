#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>

class Student {
    private:
        std::string name;

        std::vector<std::string> recommendedCourses;
    
    public:
        Student(const std::string& name);

        std::string getName() const;

        void addRecommendation(const std::string& course);

        std::vector<std::string> getRecommendations() const;
        
};

#endif