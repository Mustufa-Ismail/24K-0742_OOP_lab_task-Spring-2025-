#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const int len = 5; 
    const string filename = "config.txt";

    ofstream outFile(filename);
    if (!outFile) {
        cout << "File not opened for writing." << endl;
        return 1;
    }

    outFile << "AAAAA" << "BBBBB" << "CCCCC";
    outFile.close();
    cout << "Initial configuration written to file." << endl;

    fstream ioFile(filename, ios::in | ios::out);
    if (!ioFile) {
        cout << "File not opened for read/write." << endl;
        return 1;
    }

    ioFile.seekp(len * 1, ios::beg);
    cout << "Current put position: " << ioFile.tellp() << endl;

    ioFile << "XXXXX";
    ioFile.close();
    cout << "Second block updated with 'XXXXX'." << endl;

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening config file for verification." << endl;
        return 1;
    }

    string content, line;
    while (getline(inFile, line)) {
        content += line;
    }

    cout << "\nFinal file content:\n" << content << endl;
    cout << "Verification complete." << endl;

    return 0;
}
