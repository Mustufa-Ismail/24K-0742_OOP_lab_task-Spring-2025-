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

    car(const car &obj)
    {
        brand = obj.brand;
        model = obj.model;
        rentalprice = obj.rentalprice;
        availbility = obj.availbility;
    }

    ~car()
    {
        cout << "\nObject has been destroyed" << endl;
    }

    void update_car(string brand_n, string model_n, float rentalprice_n)
    {
        brand = brand_n;
        model = model_n;
        rentalprice = rentalprice_n;
    }

    void displayDetails()
    {
        cout << "\nBrand:" << brand << endl;
        cout << "Model:" << model << endl;
        cout << "Rental price:" << rentalprice << endl;
        cout << "Available:" << (availbility ? "Yes" : "No")<< endl;
    }
};

int main()
{
    car c1("Toyota", "yaris", 500.26, 1);
    car c2(c1);

    c1.displayDetails();
    c2.displayDetails();

    c1.update_car("Honda", "civic", 100.56);
    cout << "\nAfter updating" << endl;
    c1.displayDetails();
    c2.displayDetails();
}
