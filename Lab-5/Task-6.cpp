#include <iostream>
using namespace std;

class Level
{
private:
    int ID;
    string name;
    string difficulty;

public:
    Level() : ID(0), name(""), difficulty("") {}
    Level(int ID, string name, string difficulty) : ID(ID), name(name), difficulty(difficulty) {}

    void displayDetails()
    {
        cout << "\nID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Difficulty: " << difficulty << endl;
    }
};

class VideoGame
{
private:
    string title;
    string genre;
    Level levels[10];
    int levelCount;

public:
    VideoGame(string title, string genre) : title(title), genre(genre), levelCount(0) {}

    void addLevel(int ID, string name, string difficulty)
    {
        if (levelCount < 10)
        {
            levels[levelCount++] = Level(ID, name, difficulty);
        }
        else
        {
            cout << "Cannot add more level" << endl;
        }
    }

    void display()
    {
        cout << "\nTitle: " << title << endl;
        cout << "Genre: " << genre << endl;
        cout << "Level's list " << endl;
        for (int i = 0; i < levelCount; i++)
        {
            levels[i].displayDetails();
        }
    }
};

int main()
{
    VideoGame vg("GTA V", "Action");
    vg.addLevel(1, "Level 1", "Easy");
    vg.addLevel(2, "Level 2", "Medium");
    vg.addLevel(3, "Level 3", "Hard");
    vg.display();
    return 0;
}