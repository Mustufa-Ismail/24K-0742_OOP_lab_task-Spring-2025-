#include "LectureCourse.h"

LectureCourse::LectureCourse(string name, int cr, double gr) : Course(name, cr), lectureGrade(gr){}

    void LectureCourse::calculateGrade()
    {
        cout << "Lecture Grade:" << (lectureGrade * credits) << endl;
    }

    void LectureCourse::displayInfo() const
    {
        cout << "Lecture Course: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Lecture Based Grade: " << lectureGrade << endl;
    }

