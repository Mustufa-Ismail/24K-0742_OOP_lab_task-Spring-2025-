#include <iostream>
using namespace std;

class Product
{
private:
    int ID;
    string name;
    int quantity;

public:
    Product() : ID(0), name(""), quantity(0) {}
    Product(int id, string name, int quantity) : ID(id), name(name), quantity(quantity) {}

    string getName() { return name; }
    int getID() { return ID; }

    void display()
    {
        cout << "\nID:" << ID << endl;
        cout << "Name:" << name << endl;
        cout << "Quantity:" << quantity << endl;
    }
};

class Inventory
{
private:
    Product products[100];
    int productCount;

public:
    Inventory() : productCount(0) {}

    void addProduct(int id, string name, int quantity)
    {
        if (productCount < 100)
        {
            products[productCount++] = Product(id, name, quantity);
        }
    }

    void sortProduct()
    {
        for (int i = 0; i < productCount; i++)
        {
            for (int j = 0; j < productCount - i - 1; j++)
            {
                if (products[j].getName() > products[j + 1].getName())
                {
                    Product temp = products[j];
                    products[j] = products[j + 1];
                    products[j + 1] = temp;
                }
            }
        }
    }

    void displayProducts()
    {
        cout << "Products:" << endl;
        for (int i = 0; i < productCount; i++)
        {
            products[i].display();
        }
    }

    void searchProduct(int id)
    {
        int flag = 0;
        for (int i = 0; i < productCount; i++)
        {
            if (products[i].getID() == id)
            {
                cout << "Product searched for:" << endl;
                products[i].display();
                flag++;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Product not found";
        }
    }
};

int main()
{
    Inventory inventory;
    inventory.addProduct(5, "Product 5", 10);
    inventory.addProduct(2, "Product 2", 20);
    inventory.addProduct(4, "Product 4", 30);
    inventory.addProduct(3, "Product 3", 40);
    inventory.addProduct(1, "Product 1", 50);

    inventory.displayProducts();
    inventory.searchProduct(3);
    inventory.sortProduct();
    inventory.displayProducts();

    return 0;
}
