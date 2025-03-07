#include <iostream>
using namespace std;

class Device
{
protected:
    int deviceID;
    bool status;

    Device(int deviceID, bool status) : deviceID(deviceID), status(status) {}

    void displayDetails()
    {
        cout << "Device ID:" << deviceID << endl;
        cout << "Status:" << (status ? "ON" : "Off") << endl;
    }
};

class smartPhone : virtual protected Device
{
protected:
    float screenSize;

    smartPhone(int deviceID, bool status, float screenSize) : Device(deviceID, status), screenSize(screenSize) {}

    void displayDetails()
    {
        cout << "Device ID:" << deviceID << endl;
        cout << "Status:" << (status ? "ON" : "Off") << endl;
        cout << "Screen Size:" << screenSize << endl;
    }
};

class smartWatch : virtual protected Device
{
protected:
    bool heartRateMoniter;

    smartWatch(int deviceID, bool status, bool heartRateMonitor) : Device(deviceID, status), heartRateMoniter(heartRateMoniter) {}

    void displayDetails()
    {
        cout << "Device ID:" << deviceID << endl;
        cout << "Status:" << (status == 1 ? "ON" : "Off") << endl;
        cout << "Heart Rate Monitor:" << (heartRateMoniter ? "ON" : "Off") << endl;
    }
};

class smartWearable : protected smartPhone, smartWatch
{
protected:
    int stepCounter;

public:
    smartWearable(int deviceID, bool status, float screenSize, bool heartRateMonitor, int stepCounter) : Device(deviceID, status), smartPhone(deviceID, status, screenSize), smartWatch(deviceID, status, heartRateMoniter), stepCounter(stepCounter) {}

    void displayDetails()
    {
        cout << "Device ID:" << deviceID << endl;
        cout << "Status:" << (status == 1 ? "ON" : "Off") << endl;
        cout << "Screen Size:" << screenSize << endl;
        cout << "Heart Rate Monitor:" << (heartRateMoniter == 1 ? "ON" : "Off") << endl;
        cout << "Step Counter:" << stepCounter << endl;
    }
};

int main()
{
    smartWearable s1(123, 1, 6.5, 0, 100);
    s1.displayDetails();
    return 0;
}