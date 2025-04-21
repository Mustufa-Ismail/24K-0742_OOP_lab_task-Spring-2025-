#include <iostream>
using namespace std;

class MenuItem
{
protected:
    string name;
    double price;

public:
    MenuItem(string n, double p) : name(n), price(p) {}

    virtual void showDetails() = 0;
    virtual double prepare() = 0;
};

class Appetizer : public MenuItem
{
public:
    Appetizer(string n, double p) : MenuItem(n, p) {}

    void showDetails() override
    {
        cout << "Appetizer: " << name << endl;
        cout << "Price: " << price << endl;
    }

    double prepare() override
    {
        cout << "Preparing appetizer" << endl;
        return price;
    }
};

class MainCourse : public MenuItem
{
public:
    MainCourse(string n, double p) : MenuItem(n, p) {}

    void showDetails() override
    {
        cout << "Main Course: " << name << endl;
        cout << "Price: " << price << endl;
    }

    double prepare() override
    {
        cout << "Preparing Main Course" << endl;
        return price;
    }
};

int main()
{
    Appetizer a1("Spring Rolls", 5.99);
    MainCourse m1("Grilled Chicken", 12.99);

    a1.showDetails();
    a1.prepare();
    m1.showDetails();
    m1.prepare();

    return 0;
}