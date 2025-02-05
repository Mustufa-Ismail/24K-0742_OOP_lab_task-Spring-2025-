#include <iostream>
using namespace std;

struct employee
{
    string name;
    int hoursWorked;
    float hourlyRate;
};

employee *allocateMemory(int n)
{
    employee *ptr = new employee[n];
    return ptr;
}

void userInput(employee *employees, int n)
{
    cout << "Enter the details of employees" << endl;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cout << "Employee " << i + 1 << endl;
        cout << "Name:";
        getline(cin, employees[i].name);

        cout << "Hours worked:";
        cin >> employees[i].hoursWorked;

        cout << "Hourly Ratr:";
        cin >> employees[i].hourlyRate;
    }
}

float* calculateSalary(employee *employees, int n)
{
    float *salary = new float[n];
    for (int i = 0; i < n; i++)
    {
        salary[i] = employees[i].hoursWorked * employees[i].hourlyRate;
    }
    return salary;
}

void displayEmployee(employee *employees, int n, float *salary)
{
    cout << "Employee details " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Name: " << employees[i].name << endl;
        cout << "Hours worked: " << employees[i].hoursWorked << endl;
        cout << "Hourly rate: " << employees[i].hourlyRate << endl;
        cout << "Salary: " << salary[i] << endl;
    }
}

void deallocateMemory(employee *employees)
{
    delete[] employees;
    cout << "Memory has been freed";
}

int main()
{
    int n;
    cout << "Enter the number of employees:" << endl;
    cin >> n;

    employee *employees = allocateMemory(n);

    userInput(employees, n);

    float *salary = calculateSalary(employees, n);

    displayEmployee(employees,n,salary);

    deallocateMemory(employees);

    return 0;
}