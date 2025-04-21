#include "LabCourse.h"
#include "LectureCourse.h"
using namespace std;

int main()
{
    LectureCourse lecture("Physics", 3, 85.0);
    LabCourse lab("Chemistry", 4, 90.0);

    lecture.displayInfo();
    lecture.calculateGrade();

    lab.displayInfo();
    lab.calculateGrade();

    return 0;
}