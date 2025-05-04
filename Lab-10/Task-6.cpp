#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class InventoryItem
{
private:
    int itemID;
    char itemName[20];

public:
    InventoryItem() : itemID(0)
    {
        itemName[0] = '\0';
    }

    InventoryItem(int id, const string &name) : itemID(id)
    {
        setName(name);
    }

    int getID() const { return itemID; }
    string getName() const { return string(itemName); }

    void setID(int id) { itemID = id; }
    void setName(const string &name)
    {
        strncpy(itemName, name.c_str(), sizeof(itemName) - 1);
        itemName[sizeof(itemName) - 1] = '\0';
    }

    bool saveToFile(const string &filename) const
    {
        ofstream outFile(filename, ios::binary);
        if (!outFile.is_open())
        {
            cout << "Could not create file for writing" << endl;
            return false;
        }

        outFile.write((char*)&itemID, sizeof(itemID));
        outFile.write(itemName, sizeof(itemName));
        
        return true;
    }

    bool loadFromFile(const string &filename)
    {
        ifstream inFile(filename, ios::binary);
        if (!inFile.is_open())
        {
            cout << "Error: Could not open file for reading" << endl;
            return false;
        }

        inFile.read((char*)&itemID, sizeof(itemID));
        inFile.read(itemName, sizeof(itemName));
        
        return true;
    }

    void display() const
    {
        cout << "Inventory Item:" << endl;
        cout << "ID: " << itemID << endl;
        cout << "Name: " << itemName << endl;
    }
};

int main()
{
    InventoryItem itemToSave(1, "ABC");
    if (!itemToSave.saveToFile("inventory.dat"))
    {
        cout << "Failed to save item" << endl;
        return 1;
    }

    InventoryItem itemToLoad;
    if (!itemToLoad.loadFromFile("inventory.dat"))
    {
        cout << "Failed to load item" << endl;
        return 1;
    }

    itemToLoad.display();
    return 0;
}