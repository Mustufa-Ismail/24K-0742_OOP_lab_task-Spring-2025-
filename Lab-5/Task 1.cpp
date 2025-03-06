#include <iostream>
#include <cstring>
using namespace std;

class Apartments
{
private:
    int ID;
    string address;
    char *onwer_name;

public:
    Apartments(int ID, string address, string name) : ID(ID), address(address)
    {
        onwer_name = new char[strlen(name.c_str()) + 1];
        strcpy(onwer_name, name.c_str());
    }

    Apartments(const Apartments &a1)
    {
        ID = a1.ID;
        address = a1.address;
        onwer_name = new char[strlen(a1.onwer_name) + 1];
        strcpy(onwer_name, a1.onwer_name);
    }

    ~Apartments()
    {
        delete[] onwer_name;
    }

    void display()
    {
        cout << "ID: " << ID << endl;
        cout << "Address: " << address << endl;
        cout << "Owner Name: " << onwer_name << endl;
    }
};

int main()
{
    Apartments a1(1, "A", "Ali");
    a1.display();
    cout << endl;
    Apartments a2 = a1;
    a2.display();
    return 0;
}
