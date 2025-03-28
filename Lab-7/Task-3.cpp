#include <iostream>
using namespace std;

class Ticket
{
protected:
    int ticketID;
    string passengerName;
    float price;
    string date;
    string destination;

public:
    Ticket(int id, string n, float p, string d, string des) : ticketID(id), passengerName(n), price(p), date(d), destination(des) {}

    virtual void reserve()
    {
        cout << "Ticket Reserved" << endl;
    }

    virtual void cancel()
    {
        cout << "Ticket Cancelled" << endl;
    }

    virtual void displayTicketInfo() const
    {
        cout << "Ticket ID:" << ticketID << endl;
        cout << "Passenger Name:" << passengerName << endl;
        cout << "Price:" << price << endl;
        cout << "Date:" << date << endl;
        cout << "Destination:" << destination << endl;
    }
};

class FlightTicket : public Ticket
{
protected:
    string airlineName;
    int flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string n, float p, string d, string des, string a, int f, string s) : Ticket(id, n, p, d, des), airlineName(a), flightNumber(f), seatClass(s) {}
    void displayTicketInfo() const override
    {
        cout << "Ticket ID:" << ticketID << endl;
        cout << "Passenger Name:" << passengerName << endl;
        cout << "Price:" << price << endl;
        cout << "Date:" << date << endl;
        cout << "Destination:" << destination << endl;
        cout << "Airline Name:" << airlineName << endl;
        cout << "Flight Number:" << flightNumber << endl;
        cout << "Seat Class:" << seatClass << endl;
    }
};

class TrainTicket : public Ticket
{
protected:
    int trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string n, float p, string d, string des, int t, string c, string dt) : Ticket(id, n, p, d, des), trainNumber(t), coachType(c), departureTime(dt) {}
    void reserve() override
    {
        cout << "Train seat has been auto assigned" << endl;
    }
};

class BusTicket : public Ticket
{
protected:
    string busCompany;
    int seatNumber;

public:
    BusTicket(int id, string n, float p, string d, string des, string bc, int sn) : Ticket(id, n, p, d, des), busCompany(bc), seatNumber(sn) {}
    void cancel() override
    {
        cout << "Ticket Cancelled\n your refund is:" << price << endl;
    }
};

class ConcertTicket : public Ticket
{
protected:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string n, float p, string d, string des, string a, string v, string s) : Ticket(id, n, p, d, des), artistName(a), venue(v), seatType(s) {}
    void displayTicketInfo() const override
    {
        cout << "Ticket ID:" << ticketID << endl;
        cout << "Passenger Name:" << passengerName << endl;
        cout << "Price:" << price << endl;
        cout << "Date:" << date << endl;
        cout << "Destination:" << destination << endl;
        cout << "Artist Name:" << artistName << endl;
        cout << "Venue:" << venue << endl;
        cout << "Seat Type:" << seatType << endl;
    }
};

int main()
{
    FlightTicket flight(101, "John Doe", 500.0, "2025-04-10", "New York", "AirwaysX", 2345, "Business");
    flight.displayTicketInfo();
    flight.reserve();
    flight.cancel();

    TrainTicket train(102, "Alice Smith", 120.0, "2025-04-11", "Chicago", 567, "Sleeper", "10:30 AM");
    train.displayTicketInfo();
    train.reserve();
    train.cancel();

    BusTicket bus(103, "Bob Johnson", 50.0, "2025-04-12", "Los Angeles", "ExpressBus", 12);
    bus.displayTicketInfo();
    bus.reserve();
    bus.cancel();

    ConcertTicket concert(104, "Eve Adams", 75.0, "2025-04-15", "Madison Square Garden", "Rock Band", "Madison Square Garden", "VIP");
    concert.displayTicketInfo();
    concert.reserve();
    concert.cancel();

    return 0;
}