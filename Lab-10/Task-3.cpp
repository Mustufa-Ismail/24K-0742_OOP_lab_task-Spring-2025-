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
            int i_year;

            getline(iss, type, ',');
            getline(iss, id, ',');
            getline(iss, name, ',');
            getline(iss, year, ',');
            getline(iss, extraData, ',');
            getline(iss, certification, ',');

            i_year = stoi(year);

            cout << "Year: " << year << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    file.close();
    return 0;
}