#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream file("vehicle.txt");

    string variable;
    if (file.is_open())
    {
        while (getline(file, variable))
        {
            cout << variable << endl;
            if (variable.empty())
                continue;
            istringstream iss(variable);
            string type, id, name, year, extraData, certification;

            getline(iss, type, ',');
            getline(iss, id, ',');
            getline(iss, name, ',');
            getline(iss, year, ',');
            getline(iss, extraData, ',');
            getline(iss, certification, ',');

            if (type == "HybridTruck")
            {
                size_t c1 = extraData.find(":");
                size_t p = extraData.find("|");
                size_t c2 = extraData.find(":", p);

                string s1 = extraData.substr(c1 + 1, p - c1 - 1);
                int n1 = stoi(s1);

                string s2 = extraData.substr(c2 + 1);
                int n2 = stoi(s2);

                cout << " Cargo Capacity = " << n1 << endl;
                cout << " kg, Battery Capacity = " << n2 << endl;
            }

            else if (type == "AutonomousCar" || type == "ElectricVehicle")
            {
                continue;
            }

            else
            {
                cout << "Unknown vehicle type";
            }
        }
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    file.close();
    return 0;
}