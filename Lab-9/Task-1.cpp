#include <iostream>
using namespace std;

class Patient
{
protected:
    string name, id;

public:
    Patient(string n, string id) : name(n), id(id) {}

    virtual void displayTreatement() = 0;
    virtual void calculateCost() = 0;
};

class InPatient : public Patient
{
public:
    InPatient(string n, string id) : Patient(n, id) {}

    void displayTreatement() override
    {
        cout << "InPatient Treatment for " << name << endl;
    }

    void calculateCost() override
    {
        cout << "Calculating cost for InPatient" << endl;
    }
};

class OutPatient : public Patient
{
public:
    OutPatient(string n, string id) : Patient(n, id) {}

    void displayTreatement() override
    {
        cout << "OutPatient Treatment for " << name << endl;
    }

    void calculateCost() override
    {
        cout << "Calculating cost for OutPatient" << endl;
    }
};

int main(){
    InPatient p1("John Doe", "IP123");
    OutPatient p2("Jane Smith", "OP456");

    p1.displayTreatement();
    p1.calculateCost();
    p2.displayTreatement();
    p2.calculateCost();

    return 0;
}
