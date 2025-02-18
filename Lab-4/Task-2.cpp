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
    car(string brand_n, string model_n, float rentalprice_n, bool available)
    {
        brand = brand_n;
        model = model_n;
        rentalprice = rentalprice_n;
        availbility = available;
    }

    void update_car(string brand_n, string model_n, float rentalprice_n)
    {
        brand = brand_n;
        model = model_n;
        rentalprice = rentalprice_n;
    }

    void rentCar(int days)
    {
        if (availbility == false)
        {
            cout << "\nCar is not avalible" << endl;
            return;
        }
        else
        {
            availbility = false;
            cout << "\nCar has been rented to you " << endl;
            displayDetails();
            float discount = 1;
            if (days > 5 && days <= 10)
            {
                discount = 0.05;
                cout << "\nDiscount :" << discount * 100 << "%" << endl;
            }
            else if (days > 5)
            {
                discount = 0.1;
                cout << "\nDiscount" << discount * 100 << "%" << endl;
            }
            cout << "\nRenting for " << days << " days" << endl;
            cout << "Cost:" << (rentalprice * days) * discount << endl;
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
    car c1("Toyota", "yaris", 500.26, 1);
    car c2("Honda", "civic", 100.56, 1);
    car c3("Kia", "Sportage", 150.99, 0);

    c1.rentCar(5);
    c2.rentCar(10);
    c3.rentCar(15);
    c1.displayDetails();
    c2.displayDetails();
    c3.displayDetails();

}
