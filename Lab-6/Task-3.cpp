#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

    Person(string name, int age) : name(name), age(age) {}

    void displayDetails()
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
    }
};

class Teacher : virtual protected Person
{
protected:
    string subject;

    Teacher(string name, int age, string subject) : Person(name, age), subject(subject) {}

    void displayDetails()
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "Subject:" << subject << endl;
    }
};

class Researcher : virtual protected Person
{
protected:
    string researchArea;

    Researcher(string name, int age, string research) : Person(name, age), researchArea(research) {}

    void displayDetails()
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "Research Area:" << researchArea << endl;
    }
};

class Professor : protected Teacher, protected Researcher
{
private:
    int publications;

public:
    Professor(string name, int age, string research, string subject, int publication) : Person(name, age), Teacher(name, age, subject), Researcher(name, age, research), publications(publication) {}

    void displayDetails()
    {
        cout << "Name:" << name << endl;
        cout << "Age:" << age << endl;
        cout << "Research Area:" << researchArea << endl;
        cout << "Subject:" << subject << endl;
        cout << "Publication:" << publications << endl;
    }
};

int main()
{
    Professor p("Ali", 40, "AI", "cs", 12);
    p.displayDetails();
    return 0;
}