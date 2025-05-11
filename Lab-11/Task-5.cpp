#include <iostream>
#include <exception>
using namespace std;

class NegativeStockException : public exception
{
};

class OverCapacityException : public exception
{
};

template <typename T>
class Inventory
{
private:
    T capacity;
    T stock;

public:
    Inventory(T c, T s) : capacity(c), stock(s) {}

    void setStock(T amount)
    {
        if (amount < 0)
        {
            throw NegativeStockException();
        }
        if (stock + amount > capacity)
        {
            throw OverCapacityException();
        }
        stock += amount;
    }
};

int main()
{
    Inventory<int> inv(100, 50);
    try
    {
        inv.setStock(200);
    }
    catch (const NegativeStockException &e)
    {
        cout << "Caught NegativeStockException -what() " << e.what() << endl;
    }
    catch (const OverCapacityException &e)
    {
        cout << "Caught OverCapacityException -what() " << e.what() << endl;
    }

    return 0;
}