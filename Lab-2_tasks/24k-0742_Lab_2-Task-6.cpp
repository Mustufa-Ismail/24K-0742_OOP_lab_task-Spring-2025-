#include <iostream>
using namespace std;

struct student
{
    string name;
    int roll_no;
    int marks[3];
};

student *allocateMemory(int n)
{
    student *ptr = new student[n];
    return ptr;
}

void userInput(student *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Student name: ";
        cin >> students[i].name;
        cout << "Roll no: ";
        cin >> students[i].roll_no;
        for (int j = 0; j < 3; j++)
        {
            cout << "Subject " << j + 1 << " marks:";
            cin >> students[i].marks[j];
        }
    }
}

int *average(student *students, int n)
{
    int *avg = new int[n];

    for (int i = 0; i < n; i++)
    {
        avg[i] = 0;
        for (int j = 0; j < 3; j++)
        {
            avg[i] += students[i].marks[j];
        }
        avg[i] /= 3;
    }
    return avg;
}

void display(student *students, int n, int *avg)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Roll-no: " << students[i].roll_no << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "Subject: " << j + 1 << ":" << students[i].marks[j] << endl;
        }
        cout << "Average marks: " << avg[i] << endl;
    }
}

void deallocateMemory(student *students, int *avg)
{
    delete[] students;
    delete[] avg;
    cout << "Memory has been freed";
}

int main()
{
    int n;
    cout << "Enter the number of students:";
    cin >> n;

    student *students = allocateMemory(n);

    userInput(students, n);

    int *avg = average(students, n);

    display(students, n, avg);

    deallocateMemory(students, avg);

    return 0;
}