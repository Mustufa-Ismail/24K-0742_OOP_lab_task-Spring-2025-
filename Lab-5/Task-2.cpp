#include <iostream>

using namespace std;

class Student
{
private:
    int ID;
    string name;
    int *examScores;
    int examCount;

public:
    Student(int id, string name, int count) : ID(id), name(name), examCount(count)
    {
        examScores = new int[examCount];
        for (int i = 0; i < examCount; i++)
        {
            examScores[i] = 0;
        }
    }

    Student(const Student &s1)
    {
        ID = s1.ID;
        name = s1.name;
        examCount = s1.examCount;
        examScores = new int[examCount];
        for (int i = 0; i < examCount; i++)
        {
            examScores[i] = s1.examScores[i];
        }
    }

    ~Student()
    {
        delete[] examScores;
    }

    void display()
    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Exam Scores: ";
        for (int i = 0; i < examCount; i++)
        {
            cout << examScores[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Student s1(1, "Ali", 3);
    s1.display();
    cout << endl;
    Student s2(s1);
    s2.display();
    return 0;
}