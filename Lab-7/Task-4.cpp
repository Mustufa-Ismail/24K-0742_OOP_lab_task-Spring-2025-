#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    string contactNumber;

public:
    Person(string n, int a, string c) : name(n), age(a), contactNumber(c) {}
    virtual void displayInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact Number: " << contactNumber << endl;
    }

    virtual void updateInfo(string n, int a, string c)
    {
        name = n;
        age = a;
        contactNumber = c;
    }
};

class Patient : public Person
{
protected:
    int patientID;
    string medicalHistory[10];
    int historyCount;
    string doctorAssigned;

public:
    Patient(string n, int a, string c, int id, string d) : Person(n, a, c), patientID(id), doctorAssigned(d), historyCount(0) {}

    void displayInfo() const override
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Doctor Assigned: " << doctorAssigned << endl;
        cout << "Medical History: ";
        for (int i = 0; i < historyCount; i++)
        {
            cout << medicalHistory[i] << endl;
        }
    }
};

class Doctor : public Person
{
protected:
    string specialization;
    float consultationFee;
    string PatientList[10];
    int patientCount;

public:
    Doctor(string n, int a, string c, string s, float f) : Person(n, a, c), specialization(s), consultationFee(f), patientCount(0) {}

    void updateInfo(string n, int a, string c, string s, float f)
    {
        name = n;
        age = a;
        contactNumber = c;
        specialization = s;
        consultationFee = f;
    }
};

class Nurse : public Person
{
protected:
    string assignedWard;
    string shiftTiming;

public:
    Nurse(string n, int a, string c, string w, string s) : Person(n, a, c), assignedWard(w), shiftTiming(s) {}
    void displayInfo() const override
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Contact Number: " << contactNumber << endl;
        cout << "Assigned Ward: " << assignedWard << endl;
        cout << "Shift Timing: " << shiftTiming << endl;
    }
};

class Adminstration : public Person
{
protected:
    string department;
    float salary;

public:
    Adminstration(string n, int a, string c, string d, float s) : Person(n, a, c), department(d), salary(s) {}
    void updateInfo(string n, int a, string c, string d, float s)
    {
        name = n;
        age = a;
        contactNumber = c;
        department = d;
        salary = s;
    }
};

int main()
{
    Person p1("A", 25, "000");
    p1.displayInfo();
    cout << endl;

    Patient p2("A", 25, "000", 123, "B");
    p2.displayInfo();
    cout << endl;

    Doctor d("A",25, "000", "B", 5000);
    d.displayInfo();
    cout << endl;

    Nurse n("A", 25, "000", "Ward 1", "Morning");
    n.displayInfo();
    cout << endl;

    Adminstration a("A", 35, "000", "HR", 50000);
    a.displayInfo();
    cout << endl;

    return 0;
}