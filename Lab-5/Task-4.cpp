#include<iostream>
using namespace std;

class AlarmSystem{
    private:
        string securityLevel;

    public:
    AlarmSystem(string securityLevel) : securityLevel(securityLevel){}

    void display(){
        cout << "Security Level: " << securityLevel << endl;
    }
};

class SmartHome{
    private:
        string name;
        AlarmSystem alarmSystem;
    
        public:
        SmartHome(string name, string securityLevel) : name(name), alarmSystem(securityLevel){}


        void display(){
            cout << "Name: " << name << endl;
            alarmSystem.display();  
        }
};

int main(){
    SmartHome smartHome("Home", "High");
    smartHome.display();
    return 0;
}