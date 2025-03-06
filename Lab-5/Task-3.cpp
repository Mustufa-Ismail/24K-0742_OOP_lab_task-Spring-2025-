#include <iostream>
using namespace std;

class Project;

class Employee
{
private:
    string name;
    string desgination;
    Project *projects[10];
    int projectCount;

public:
    Employee(string name, string desgination) : name(name), desgination(desgination)
    {
        projectCount = 0;
        for (int i = 0; i < 10; i++)
        {
            projects[i] = NULL;
        }
    }
    void addProject(Project *p)
    {
        projects[projectCount++] = p;
    }
    void displayDetail()
    {
        cout << "Name: " << name << endl;
        cout << "Desgination: " << desgination << endl;
    }
};

class Project
{
private:
    string title;
    string deadline;
    Employee *employees[10];
    int employeeCount;

public:
    Project(string title, string deadline) : title(title), deadline(deadline)
    {
        employeeCount = 0;
        for (int i = 0; i < 10; i++)
        {
            employees[i] = NULL;
        }
    }
    void addEmployee(Employee *e)
    {
        employees[employeeCount++] = e;
    }
    void display()
    {
        cout << "\nTitle: " << title << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "Employees: " << endl;
        for (int i = 0; i < employeeCount; i++)
        {
           employees[i]->displayDetail();
        }
    }
};

int main(){
    Employee e1("Ali", "Manager");
    Employee e2("Ahmed", "Developer");
    Project p1("Project-1", "1-1-2025");
    Project p2("Project-2", "1-1-2025");
    e1.addProject(&p1);
    e2.addProject(&p2);
    p1.addEmployee(&e1);
    p2.addEmployee(&e2);
    p1.display();
    p2.display();
    return 0;
}