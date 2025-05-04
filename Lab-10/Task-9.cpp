#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const string filename = "large_log.txt";

    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error creating file." << endl;
        return 1;
    }

    outFile << "This is the first part of the log.\n"
            << "This is the second part of the log.\n"
            << "And the third part.\n";
    outFile.close();
    cout << "File created and written.\n" << endl;

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    char buffer[11] = {}; 

    inFile.read(buffer, 10);
    cout << "First 10 characters: \"" << buffer << "\"" << endl;
    streampos pos1 = inFile.tellg();
    cout << "Position after first read: " << pos1 << endl;

    
    inFile.read(buffer, 10);
    buffer[10] = '\0';
    cout << "Next 10 characters: \"" << buffer << "\"" << endl;
    streampos pos2 = inFile.tellg();
    cout << "Position after second read: " << pos2 << endl;

    inFile.close();
    cout << "\nFile closed." << endl;

    return 0;
}
