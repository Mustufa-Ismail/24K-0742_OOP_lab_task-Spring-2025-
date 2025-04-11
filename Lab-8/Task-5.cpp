#include <iostream>
using namespace std;

class Character
{
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int l, int h, string w) : characterID(id), name(n), level(l), healthPoints(h), weaponType(w) {}

    virtual void attack()
    {
        cout << "Attacking" << endl;
    }

    virtual void defend()
    {
        cout << "Defending" << endl;
    }

    virtual void displayStats() const
    {
        cout << "Character ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoints << endl;
        cout << "Weapon Type: " << weaponType << endl;
    }
};

class Warrior : public Character
{
protected:
    int armorStrenght;
    int meleeDamage;

public:
    Warrior(int id, string n, int l, int h, string w, int a, int m) : Character(id, n, l, h, w), armorStrenght(a), meleeDamage(m) {}

    void attack() override
    {
        cout << "Melee Attack" << endl;
    }
};

class Mage : public Character
{
protected:
    int manaPower;
    int spellPower;

public:
    Mage(int id, string n, int l, int h, string w, int s, int m) : Character(id, n, l, h, w), manaPower(m), spellPower(s) {}

    void defend() override
    {
        cout << "Using magical Barrier" << endl;
    }
};

class Archer : public Character
{
protected:
    int ArrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int l, int h, string w, int a, int r) : Character(id, n, l, h, w), ArrowCount(a), rangedAccuracy(r) {}

    void attack() override
    {
        cout << "Long-Range Attack" << endl;
    }
};

class Rougue : public Character
{
protected:
    int stealthLevel;
    int agility;

public:
    Rougue(int id, string n, int l, int h, string w, int s, int a) : Character(id, n, l, h, w), stealthLevel(s), agility(a) {}

    void displayStats() const override
    {
        cout << "Character ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoints << endl;
        cout << "Weapon Type: " << weaponType << endl;
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main()
{
    Warrior w(1, "Warrior", 10, 100, "Sword", 50, 20);
    Mage m(2, "Mage", 10, 100, "Staff", 50, 20);
    Archer a(3, "Archer", 10, 100, "Bow", 50, 20);
    Rougue r(4, "Rougue", 10, 100, "Dagger", 50, 20);

    w.displayStats();
    w.attack();
    w.defend();

    m.displayStats();
    m.attack();
    m.defend();

    a.displayStats();
    a.attack();
    a.defend();

    r.displayStats();
    r.attack();
    r.defend();

    return 0;
}