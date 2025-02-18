#include <iostream>
using namespace std;

class car
{
private:
    string brand;
    string model;
    float rentalprice;
    bool availbility;
    double revenue;
    int carID;

public:
    car()
    {
        brand = "Unknown";
        model = "Generic";
        rentalprice = 0.0;
        availbility = true;
        revenue = 0.0;
    }
    car(string brand_n, string model_n, float rentalprice_n, bool available, int id) : carID(id)
    {
        brand = brand_n;
        model = model_n;
        rentalprice = rentalprice_n;
        availbility = available;
        revenue = 0.0;
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
            cout << "Car is not avalible" << endl;
            return;
        }
        else
        {
            availbility = false;
            cout << "Car has been rented to you " << endl;
        }

        float discount = 1;
        if (days > 5 && days <= 10)
        {
            discount = 0.95;
            cout << "\nDiscount :" << (1 - discount) * 100 << "%" << endl;
        }
        else if (days > 10)
        {
            discount = 0.90;
            cout << "\nDiscount" << (1 - discount) * 100 << "%" << endl;
        }
        cout << "\nRenting for " << days << " days" << endl;
        double cost = (rentalprice * days) * discount;
        cout << "Cost:" << cost << endl;
        this->revenue += cost;
    }

    void displayDetails()
    {
        cout << "\nCar ID:" << carID << endl;
        cout << "Brand:" << brand << endl;
        cout << "Model:" << model << endl;
        cout << "Rental price:" << rentalprice << endl;
        cout << "Available:" << (availbility ? "Yes" : "No") << endl;
        cout << "Revenue:" << this->revenue << endl;
    }
};

int main()
{
    car c1("Toyota", "yaris", 500.26, 1, 10);
    car c2("Honda", "civic", 100.56, 1, 20);
    car c3("Kia", "Sportage", 149.99, 1, 30);

    c1.rentCar(15);
    c2.rentCar(6);
    c3.rentCar(2);
    c1.displayDetails();
    c2.displayDetails();
    c3.displayDetails();
}
