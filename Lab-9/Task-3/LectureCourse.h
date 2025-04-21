#ifndef LectureCourse_H
#define LECTURECOURSE_H

#include "Course.h"
#include <iostream>

class LectureCourse : public Course
{
protected:
    double lectureGrade;

public:
    LectureCourse(string name, int cr, double gr);

    void calculateGrade() override ;
    void displayInfo() const override ;
};

#endif