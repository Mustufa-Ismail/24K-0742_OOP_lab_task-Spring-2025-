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

            if (type == "AutonomousCar")
            {
                size_t n = extraData.find(":");
                string s = extraData.substr(n + 1);
                float f = stof(s);

                cout << f << endl;
            }

            else if (type == "ElectricVehicle")
            {
                int n = extraData.find(":");
                string s = extraData.substr(n + 1);
                int i = stoi(s);

                cout << i << endl;
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