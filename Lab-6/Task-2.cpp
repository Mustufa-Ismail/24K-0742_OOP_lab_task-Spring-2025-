#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string brand;
    int year;
    Vehicle(string brand, int year) : brand(brand), year(year) {}

    void displayDetails()
    {
        cout << "Brand:" << brand << endl;
        cout << "Year:" << year << endl;
    }
};

class Car : protected Vehicle
{
protected:
    int seats;

    Car(string brand, int year, int seats) : Vehicle(brand, year), seats(seats) {}

    void displayDetails()
    {
        cout << "Brand:" << brand << endl;
        cout << "Year:" << year << endl;
        cout << "Seats:" << seats << endl;
    }
};

class ElectricCar : protected Car
{
protected:
    int batteryLife;
    
    public:
    ElectricCar(string brand, int year, int seats, int batteryLife) : Car(brand, year, seats),
                                                                      batteryLife(batteryLife) {}
    void displayDetails()
    {
        cout << "Brand:" << brand << endl;
        cout << "Year:" << year << endl;
        cout << "Seats:" << seats << endl;
        cout << "Battery Life:" << batteryLife << endl;
    }
};

int main(){
    ElectricCar e1("Tesla",2025,4,500);
    e1.displayDetails();
    return 0;
}
