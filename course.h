#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course{
    private:
        string id;
    
    public:
        Course();

        Course(const string& id);
        
        string getId() const;

        bool operator == (const Course& other) const;

        bool operator < (const Course& other) const;

 };

 #endif