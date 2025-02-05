#include <iostream>
using namespace std;

struct product
{
    int productID;
    string name;
    int quantity;
    float price;
};

product *allocateMemory(int n)
{
    product *ptr = new product[n];
    return ptr;
}

void userInput(product *item, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Product ID:";
        cin >> item[i].productID;
        cout << "Enter the product name:";
        cin >> item[i].name;
        cout << "Enter the quantity of product:";
        cin >> item[i].quantity;
        cout << "Enter the per unit price:";
        cin >> item[i].price;
        cout << endl;
    }
}

float *calculateInventory(product *item, int n)
{
    float *inventory = new float[n];
    for (int i = 0; i < n; i++)
    {
        inventory[i] = item[i].quantity * item[i].price;
    }
    return inventory;
}

void display(product *item, float *inventory, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Product ID:" << item[i].productID << endl;
        cout << "Product Name:" << item[i].name << endl;
        cout << "Quantity:" << item[i].quantity << endl;
        cout << "Price per unit:" << item[i].price << endl;
        cout << "Total inventory:" << inventory[i] << endl;
        cout << endl;
    }
}

void deallocateMemory(product *item, float *inventory)
{
    delete[] item;
    delete[] inventory;

    cout << "Memory has been freed";
}

int main()
{
    int n;
    cout << "Enter the numeber of products:";
    cin >> n;

    product *item = allocateMemory(n);

    userInput(item, n);
    float *inventory = calculateInventory(item, n);

    display(item, inventory, n);

    deallocateMemory(item, inventory);

    return 0;
}