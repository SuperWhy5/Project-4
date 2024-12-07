#ifndef COURSE_H
#define COURSE_H

#include <iostream>

class Course{
    private:
        std::string id;
    
    public:
        Course(const std::string& id);
        
        std::string getId() const;

        bool operator == (const Course& other) const;

        bool operator < (const Course& other) const;

 };

 #endif