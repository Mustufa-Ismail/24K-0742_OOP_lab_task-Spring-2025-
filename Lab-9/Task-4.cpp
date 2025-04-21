#include <iostream>
using namespace std;

class WeatherSensor
{
protected:
    int id;

public:
    WeatherSensor(int id) : id(id) {}
    virtual void readData() = 0;
    virtual void displayReport() = 0;
};

class Thermometer : public WeatherSensor
{
public:
    Thermometer(int id) : WeatherSensor(id) {}

    void readData() override
    {
        cout << "Thermometer is reading Data" << endl;
    }

    void displayReport() override
    {
        cout << "ID: " << id << endl;
        cout << "Thermometer is Reporting" << endl;
    }
};

class Barometer : public WeatherSensor
{
public:
    Barometer(int id) : WeatherSensor(id) {}

    void readData() override
    {
        cout << "Barometer is reading Data" << endl;
    }

    void displayReport() override
    {
        cout << "ID: " << id << endl;
        cout << "Barometer is Reporting" << endl;
    }
};

int main()
{
    Thermometer t1(1);
    Barometer b1(2);

    t1.readData();
    t1.displayReport();

    b1.readData();
    b1.displayReport();

    return 0;
}