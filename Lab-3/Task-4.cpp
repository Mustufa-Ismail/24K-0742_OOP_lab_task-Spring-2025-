#include <iostream>
using namespace std;

class car
{
private:
    string brand;
    string model;
    int fuelCapcity;
    float fuelLevel;
    int fuelAverage;

public:
    car(string brandname, string modelname, int Capcity, float Level, int Average)
    {
        brand = brandname;
        model = modelname;
        fuelCapcity = Capcity;
        fuelLevel = Level;
        fuelAverage = Average;
    }

    void driving(float distance)
    {
        fuelLevel -= (distance / fuelAverage);
        CheckFuelStatus();
    }

    void refuelTank(float fuel)
    {
        if (fuelLevel + fuel >= fuelCapcity)
        {
            fuelLevel = fuelCapcity;
            cout << "Fuel tank is full";
        }
        else
        {
            fuelLevel += fuel;
        }
        CheckFuelStatus();
    }

    bool fuelStatus()
    {
        return fuelLevel >= 5;
    }

    void CheckFuelStatus()
    {
        cout << "\nFuel Level:" << fuelLevel << endl;
        if (fuelStatus())
        {
            cout << "Fuel level is normal" << endl;
        }
        else
        {
            cout << "Fuel level is low" << endl;
        }
    }
};

int main()
{
    car car1("Toyota", "Corolla", 50, 45, 10);
    car1.driving(430);
    car1.refuelTank(15);
}