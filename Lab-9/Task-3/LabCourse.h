#ifndef LABCOURSE_H
#define LABCOURSE_H

#include "Course.h"
#include <iostream>

class LabCourse : public Course
{
protected:
    double labGrade;

public:
    LabCourse(string name, int cr, double gr);

    void calculateGrade() override ;

    void displayInfo() const override ;
};

#endif