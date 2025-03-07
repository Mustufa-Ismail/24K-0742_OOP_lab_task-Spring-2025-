#include <iostream>
using namespace std;

class Employee
{
protected:
    string name;
    float salary;

    Employee(string name, float salary) : name(name), salary(salary) {}

    void displayDetails()
    {
        cout << "Name:" << name << endl;
        cout << "Salary:" << salary << endl;
    }
};

class Manager : protected Employee
{
private:
    float bonus;

public:
    Manager(string name, float salary, float bonus) : Employee(name, salary), bonus(bonus) {}

    void displayDetails()
    {
        cout << "Name:" << name << endl;
        cout << "Salary:" << salary << endl;
        cout << "Bonus: " << bonus << endl;
    }
};

int main()
{
    Manager m1("Ali", 50000, 5000);
    m1.displayDetails();
    return 0;
}