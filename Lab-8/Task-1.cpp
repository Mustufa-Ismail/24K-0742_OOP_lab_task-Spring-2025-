#include <iostream>
using namespace std;

class Device
{
protected:
    int deviceID;
    string deviceName;
    bool status;
    string location;

public:
    Device(int id, string n, bool s, string l) : deviceID(id), deviceName(n), status(s), location(l) {}

    virtual void turnOn() { status = true; }
    virtual void turnOff() { status = false; }
    virtual void getStatus() const
    {
        cout << "Status:" << (status ? "On" : "Off") << endl;
    }

    virtual void display() const
    {
        cout << "Device ID: " << deviceID << endl;
        cout << "Device Name: " << deviceName << endl;
        getStatus();
        cout << "Location:" << location << endl;
    }
};

class Light : public Device
{
protected:
    string brightnessLevel;
    string colorMode;

public:
    Light(int id, string n, bool s, string l, string b, string c) : Device(id, n, s, l), brightnessLevel(b), colorMode(c) {}

    void display() const
    {
        cout << "Device ID: " << deviceID << endl;
        cout << "Device Name: " << deviceName << endl;
        getStatus();
        cout << "Location:" << location << endl;
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device
{
protected:
    float temperature;
    bool mode;
    float targetTemperature;

public:
    Thermostat(int id, string n, bool s, string l, float t, bool m, float tt) : Device(id, n, s, l), temperature(t), mode(m), targetTemperature(tt) {}

    void getStatus() const
    {
        cout << "Status:" << (status ? "On" : "Off") << endl;
        cout << "Mode:" << (mode ? "Cooling" : "Heating") << endl;
    }
};

class SecurityCamera : public Device
{
private:
    int resolution;
    bool recordingStatus;
    bool nightVisionEnabled;

public:
    SecurityCamera(int id, string n, bool s, string l, int r, bool rs, bool nve) : Device(id, n, s, l), resolution(r), recordingStatus(rs), nightVisionEnabled(nve) {}

    void turnOn()
    {
        status = true;
        recordingStatus = true;
    }
};

class SmartPlug : public Device
{
private:
    float powerConsumption;
    bool timerSetting;

public:
    SmartPlug(int id, string n, bool s, string l, float pc, bool ts) : Device(id, n, s, l), powerConsumption(pc), timerSetting(ts) {}

    void turnOff()
    {
        status = false;
        cout << "Power Consumption: " << powerConsumption << endl;
    }
};

int main()
{
    Device d(1, "Device", false, "A");
    d.display();

    Light l(2, "Light", false, "A", "High", "RGB");
    l.display();

    Thermostat t(3, "Thermostat", false, "A", 25.0, true, 20.0);
    t.display();

    SecurityCamera s(4, "Security Camera", false, "A", 1080, false, true);
    s.display();

    SmartPlug sp(5, "Smart Plug", false, "A", 100.0, true);
    sp.display();

    return 0;
}