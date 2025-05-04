#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ofstream logFile("sensor_log.txt");

    if (!logFile.is_open())
    {
        cout << "Could not open file" << endl;
        return 1;
    }

    cout << "Initial file position: " << logFile.tellp() << endl;

    logFile << "Temperature: 25.5 C\n";
    cout << "Position after first write: " << logFile.tellp() << endl;
    
    logFile << "Temperature: 91.8 %RH\n";
    cout << "Position after second write: " << logFile.tellp() << endl;

    logFile.close();

    return 0;
}