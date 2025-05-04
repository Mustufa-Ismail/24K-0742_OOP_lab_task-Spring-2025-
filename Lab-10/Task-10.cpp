#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    const string filename = "data_records.txt";

    ofstream outFile(filename);
    if (!outFile)
    {
        cerr << "Error creating file." << endl;
        return 1;
    }

    outFile << "Record 1\n";
    outFile << "Record 2\n";
    outFile << "Record 3\n";
    outFile << "Record 4\n";
    outFile.close();
    cout << "File created with multiple records.\n"
         << endl;

    ifstream inFile(filename);
    if (!inFile)
    {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    string line;
    streampos record3_offset = 0;

    for (int i = 0; i < 3; ++i)
    {
        record3_offset = inFile.tellg();
        record3_offset -= 2;
        getline(inFile, line);
    }

    inFile.clear();
    inFile.seekg(record3_offset);

    string record;
    getline(inFile, record);
    cout << "Record read from dynamic offset: " << record << endl;

    inFile.close();
    return 0;
}
