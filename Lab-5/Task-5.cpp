#include <iostream>
using namespace std;

class Doctor
{
private:
    string name;
    string specialization;
    int experience;

public:
    Doctor(string name, string specialization, int experience) : name(name), specialization(specialization),
                                                                 experience(experience) {}

    void displayDetails()
    {
        cout << "\nName: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
};

class Hosiptal
{
private:
    string name;
    Doctor *doctor[10];
    int doctorCount;

public:
    Hosiptal(string name) : name(name), doctorCount(0)
    {
        for (int i = 0; i < 10; i++)
        {
            doctor[i] = NULL;
        }
    }

    void addDoctor(Doctor *d)
    {
        doctor[doctorCount++] = d;
    }

    void display()
    {
        cout << "\nName: " << name << endl;
        cout << "Doctor's list " << endl;
        for (int i = 0; i < doctorCount; i++)
        {
            doctor[i]->displayDetails();
        }
    }
};

int main(){
    Doctor d1("Dr. A", "A", 5);
    Doctor d2("Dr. B", "B", 10);
    Doctor d3("Dr. C", "C", 15);

    Hosiptal h("XYZ Hospital");
    h.addDoctor(&d1);
    h.addDoctor(&d2);
    h.addDoctor(&d3);

    h.display();
    return 0;
}