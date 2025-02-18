#include <iostream>
using namespace std;

class car
{
private:
    string brand;
    string model;
    float rentalprice;
    bool availbility;

public:
    car()
    {
        brand = "Unknown";
        model = "Generic";
        rentalprice = 0.0;
        availbility = true;
    }

    void update_car(string brand_n, string model_n, float rentalprice_n)
    {
        brand = brand_n;
        model = model_n;
        rentalprice = rentalprice_n;
    }

    void rentCar(string brand_n, string model_n)
    {
        if (availbility == false)
        {
            cout << "Car is not avalible" << endl;
            return;
        }
        else
        {
            availbility = false;
            cout << "Car has been rented to you " << endl;
            return;
        }
    }

    void displayDetails()
    {
        cout << "\nBrand:" << brand << endl;
        cout << "Model:" << model << endl;
        cout << "Rental price:" << rentalprice << endl;
        cout << "Available:" << (availbility ? "Yes" : "No") << endl;
    }
};

int main()
{
    car c1;
    car c2;
    car c3;

    c1.update_car("Toyota", "yaris", 500.26);
    c2.update_car("Honda", "civic", 100.56);

    c1.rentCar("Toyota", "yaris");
    c1.displayDetails();
    c1.rentCar("Toyota", "yaris");
    c1.displayDetails();
    c2.displayDetails();
    c3.displayDetails();
}
