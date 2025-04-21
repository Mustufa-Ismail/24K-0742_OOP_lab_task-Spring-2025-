#include "LabCourse.h"

    LabCourse::LabCourse(string name, int cr, double gr) : Course(name, cr), labGrade(gr) {};

    void LabCourse::calculateGrade() 
    {
        cout << "Lab Grade:" << (labGrade * credits) << endl;
    }

    void LabCourse::displayInfo() const
    {
        cout << "Lab Course: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Lab Based Grade: " << labGrade << endl;
    }
