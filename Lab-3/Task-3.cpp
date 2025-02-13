#include <iostream>
using namespace std;

class library
{
private:
    string bookList[100];
    int avaliableBooks[100];
    int bookCount;

public:
    library()
    {
        bookCount = 0;
        for (int i = 0; i < 100; i++)
        {
            avaliableBooks[i] = 1;
        }
    }

    void addBook(string book_name)
    {
        if (bookCount >= 100)
        {
            cout << "Book list is full" << endl;
            return;
        }
        bookList[bookCount] = book_name;
        bookCount++;
        cout << "Book:" << book_name << " has been added succesfully" << endl;
    }

    void lendBook(string book_name)
    {
        int flag = 0;
        for (int i = 0; i < 100; i++)
        {
            if (bookList[i] == book_name)
            {
                if (avaliableBooks[i] == 1)
                {
                    avaliableBooks[i] = 0;
                    cout << "Book:" << bookList << " has been issued successfully" << endl;
                    flag = 1;
                }
            }
        }
    }
};