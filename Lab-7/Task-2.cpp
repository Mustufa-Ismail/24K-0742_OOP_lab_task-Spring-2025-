#include <iostream>
using namespace std;

class Product
{
protected:
    int productID;
    string productName;
    float price;

public:
    Product(int id, string n, float p) : productID(id), productName(n), price(p) {}

    virtual void applyDiscount()
    {
        price *= 0.95;
    }

    virtual double calculateTotalPrice(int quantity)
    {
        return price * quantity;
    }

    virtual void displayProductInfo() const
    {
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: " << price << endl;
    }

    Product operator+ (const Product &o) const {
        return Product(0,"Bulk Purchase", price + o.price);
    }

    friend ostream& operator<<(ostream& os, const Product& p){
        os << "Product ID: " << p.productID << endl;
        os << "Product Name: " << p.productName << endl;
        os << "Price: " << p.price << endl;
        return os;
    }
};

class Electronic : public Product
{
protected:
    string warrantyPeriod;
    string brand;

public:
    Electronic(int id, string n, float p, string w, string b) : Product(id, n, p), warrantyPeriod(w), brand(b) {}

    void displayProductInfo() const
    {
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Warranty Period: " << warrantyPeriod << endl;
        cout << "Brand: " << brand << endl;
    }
};

class Clothing : public Product
{
protected:
    string size;
    string color;
    string fabricMaterial;

public:
    Clothing(int id, string n, float p, string s, string c, string f) : Product(id, n, p), size(s), color(c), fabricMaterial(f) {}
    void applyDiscount() override
    {
        price *= 0.9;
        cout << "After seasonal discounted price is: " << price << endl;
    }
};

class FoodItem : public Product
{
protected:
    string expiryDate;
    int calories;

public:
    FoodItem(int id, string n, float p, string e, int c) : Product(id, n, p), expiryDate(e), calories(c) {}
    double calculateTotalPrice(int quantaity) override
    {
        double totalprice;
        totalprice = price * quantaity;
        return totalprice*0.9;
    }
};

class Book : public Product{
    protected:
        string author;
        string genre;
    
    public:
    Book(int id, string n, float p, string a, string g) : Product(id, n, p), author(a), genre(g) {}

    void displayProductInfo() const {
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Author:" << author << endl;
        cout << "Genre:" << genre << endl;
    }
};

int main(){
    Product p1(1, "Product 1", 100);
    Product p2(2, "Product 2", 200);
    Product p3 = p1 + p2;
    cout << p3 << endl;

    Electronic e(3, "TV", 300, "1 year", "Samsung");
    e.displayProductInfo();

    Clothing c(4, "T-shirt", 40, "M", "Red", "Cotton");
    c.applyDiscount();

    FoodItem f(5, "Pizza", 50, "1/1/2025", 100);
    cout << "Total Price: " << f.calculateTotalPrice(2) << endl;

    Book b(6, "Harry Potter", 600, "JKR", "fantasy");
    b.displayProductInfo();

    return 0;
}


