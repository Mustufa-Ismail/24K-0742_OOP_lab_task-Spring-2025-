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
        cout << "\nBook:" << book_name << " has been added succesfully" << endl;
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
                    cout << "\nBook:" << bookList[i] << "  has been issued successfully" << endl;
                    flag = 1;
                }
                else
                {
                    cout << "Book is not avalible" << endl;
                }
            }
        }
    }

    void returnBook(string book_name)
    {
        int flag = 0;
        for (int i = 0; i < bookCount; i++)
        {
            if (bookList[i] == book_name)
            {
                flag = 1;
                if (avaliableBooks[i] == 0)
                {
                    avaliableBooks[i] = 1;
                    cout << "\nBook:" << bookList[i] << " has been returned" << endl;
                }
                else
                {
                    cout << "\nThe book hasn't been borrowed" << endl;
                }
            }
        }
        if (flag == 0)
        {
            cout << "Books is not in the Book List" << endl;
        }
    }

    void displayBooks()
    {
        for (int i = 0; i < bookCount; i++)
        {
            cout << "\nBook:" << bookList[i] << endl;
            if (avaliableBooks[i] == 1)
            {
                cout << "Book is avalible" << endl;
            }
            else
            {
                cout << "Book is not avalible" << endl;
            }
        }
    }
};

int main()
{
    library l1;
    l1.addBook("Harry Potter");
    l1.addBook("Great Gatsby");
    l1.addBook("1986");

    l1.displayBooks();
    l1.lendBook("Harry Potter");
    l1.lendBook("1986");
    l1.displayBooks();

    l1.returnBook("1986");
    l1.displayBooks();
}
