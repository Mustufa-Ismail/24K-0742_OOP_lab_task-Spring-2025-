#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course
{
protected:
    string courseName;
    int credits;

public:
    Course(string name, int cr) : courseName(name), credits(cr) {}

    virtual void calculateGrade() = 0;
    virtual void displayInfo() const = 0;
};

#endif