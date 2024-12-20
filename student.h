#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

class Student {
    private:
        std::string name;

        std::vector<std::string> recommendedCourses;
    
    public:
        Student();

        Student(const std::string& name);

        std::string getName() const;

        void addRecommendation(const std::string& course);

        std::vector<std::string> getRecommendations() const;
        
};

#endif