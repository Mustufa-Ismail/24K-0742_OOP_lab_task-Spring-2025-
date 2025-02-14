#include<iostream>
using namespace std;

class car{
    private:
        string brand;
        string model;
        float rentalprice;
        bool availbility;

    public:
        car(){
            brand = "Unknown";
            model = "Generic";
            rentalprice = 0.0;
            availbility = true;
        }

        car(string brand_n,string model_n,float rentalprice_n,bool availbility_n){
            brand = brand_n;
            model = model_n;
            rentalprice = rentalprice_n;
            availbility = availbility_n;
        }

        void update_car(string brand_n,string model_n,float rentalprice_n){
            brand = brand_n;
            model = model_n;
            rentalprice = rentalprice_n;
        }

        void rentCar(string brand_n,string model_n){
            if(availbility == false){
                cout << "Car is not avalible" << endl;
                return;
            }
            else{
                availbility = false;
                cout << "Car has been rented to you " << endl;
                return;
            }
        }

        float applyDiscount(string brand_n,string model_n,int days){
            float discount = 1;
            if(days >= 5){
                discount = 0.05;
            }
            else if(days >= 10){
                discount = 0.1;
            }
        }
};

int main(){
    car c1;
    car c2;
    car c3;

    c1.update_car("Toyota","yaris",500.26);
    c2.update_car("Honda","civix",100.56);

    c1.rentCar("Toyota","yaris");
    c1.rentCar("Toyota","yaris");
}