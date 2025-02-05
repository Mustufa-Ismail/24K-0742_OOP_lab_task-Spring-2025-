#include <iostream>
using namespace std;

struct Book
{
    string title;
    string author;
    int year;
};

Book *allocateMemory(int n)
{
    Book *ptr = new Book[n];
    return ptr;
}

void userInput(Book *Books, int n)
{
    cout << "Enter the details for Books" << endl;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cout << "Book " << i + 1 << endl;
        cout << "Title of the Book:";
        getline(cin, Books[i].title);

        cout << "Name of the Author of the Book:";
        getline(cin, Books[i].author);

        cout << "Year of publication of the Book:";
        cin >> Books[i].year;
    }
}

void displayBook(Book *Books, int n)
{
    int searchYear;
    cout << "\nEnter the year of Publication:";
    cin >> searchYear;

    for (int i = 0; i < n; i++)
    {
        if (searchYear < Books[i].year)
        {
            cout << "Name: " << Books[i].title << endl;
            cout << "Author: " << Books[i].author << endl;
            cout << "Publication year: " << Books[i].year << endl;
        }
    }
}

void deallocate(Book *Books)
{
    delete[] Books;
    cout << "Memory has been freed";
}

int main()
{
    int n;
    cout << "Enter the number of books:";
    cin >> n;

    Book *Books = allocateMemory(n);

    userInput(Books, n);
    displayBook(Books, n);
    deallocate(Books);

    return 0;
}
