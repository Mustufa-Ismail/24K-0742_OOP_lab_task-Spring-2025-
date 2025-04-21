#include<iostream>
using namespace std;

class Shipment{
    protected:
        string trackingID;
        double weight;

    public:
        Shipment(string id, double w) : trackingID(id), weight(w) {}
        virtual void estimateDeliveryTime() = 0;
        virtual void showDetails() = 0;
};

class AirFreight : public Shipment{
    public:
    AirFreight(string id, double w) : Shipment(id, w) {}

    void estimateDeliveryTime(){
        cout << "AirFreight estimated delivery time begin calculated " << endl;
    }

    void showDetails(){
        cout << "AirFreight ID: " << trackingID << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

class GroundShipment : public Shipment{
    public:
    GroundShipment(string id, double w) : Shipment(id, w) {}

    void estimateDeliveryTime(){
        cout << "GroundShipment estimated delivery time begin calculated " << endl;
    }

    void showDetails(){
        cout << "GroundShipment ID: " << trackingID << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }
};

int main(){
    AirFreight air("1", 10.5);
    GroundShipment ground("2", 20.0);

    air.estimateDeliveryTime();
    air.showDetails();

    ground.estimateDeliveryTime();
    ground.showDetails();

    return 0;
}