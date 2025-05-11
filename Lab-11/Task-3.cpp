#include <iostream>
#include <exception>

using namespace std;

class InvalidTemperatureException : public exception
{
};

template <typename T>
T convertToFahrenheit(T celsius)
{
    T const minimum = -273.15;
    cout << "Trying to convert " << celsius << "C" << endl;
    if (celsius < minimum)
    {
        throw InvalidTemperatureException();
    }
    return (celsius * 9.0 / 5.0) + 32;
}

int main()
{
    try
    {
        convertToFahrenheit(-300);
    }
    catch (const exception &e)
    {
        cout << "Caught InvalidTemperatureException" << endl;
    }
}