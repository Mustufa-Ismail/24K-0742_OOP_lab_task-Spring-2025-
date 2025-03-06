#include <iostream>
#include <string> 
using namespace std;

class Apartments
{
private:
    int ID;
    string address;
    string onwer_name; 

public:
    Apartments(int ID, string address, string name)
        : ID(ID), address(address), onwer_name(name) {} 

    Apartments(const Apartments &a1)
        : ID(a1.ID), address(a1.address), onwer_name(a1.onwer_name) {}

    ~Apartments() {}

    void display() const
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