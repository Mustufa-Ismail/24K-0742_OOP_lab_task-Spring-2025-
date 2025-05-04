#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream file("vehicle.txt");

    string variable;
    if(file.is_open()){
        while(getline(file,variable)){
            cout << variable << endl;
        }
    }
    else{
        cout << "Unable to open file" << endl;
    }

    file.close();
    return 0;
}