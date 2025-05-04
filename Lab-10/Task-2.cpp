#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main(){
    ifstream file("vehicle.txt");

    string variable;
    if(file.is_open()){
        while(getline(file,variable)){
            cout << variable << endl;
            if(variable.empty()) continue;
            istringstream iss(variable);
            string type, id, name, year, extraData, certification;

            getline(iss, type, ',');
            getline(iss, id, ',');
            getline(iss, name, ',');
            getline(iss, year, ',');
            getline(iss, extraData, ',');
            getline(iss, certification, ',');

            cout << "Type: " << type << endl;
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Year: " << year << endl;
            cout << "Extra Data: " << extraData << endl;
            cout << "Certification: " << certification << endl;
            cout << endl;
        }
    }
    else{
        cout << "Unable to open file" << endl;
    }

    file.close();
    return 0;
}