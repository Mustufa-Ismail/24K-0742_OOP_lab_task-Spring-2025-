#include <iostream>
using namespace std;

string *allocateMemory(int n)
{
    string *ptr = new string[n];
    return ptr;
}

void userInput(string *ptr, int n)
{
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, ptr[i]);
    }
}

void sort(string *ptr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ptr[j] > ptr[j + 1])
            {
                string temp = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = temp;
            }
        }
    }
}

void displayString(string *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ptr[i] << endl;
    }
}

void deallocateMemory(string *ptr){
    delete[] ptr;
    cout << "Memory has been freed" << endl;
}

int main()
{
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    string *ptr = allocateMemory(n);
    userInput(ptr, n);
    cout << "Unsorted Strings " << endl;
    displayString(ptr, n);
    sort(ptr, n);
    cout << "Sorted Strings" << endl;
    displayString(ptr, n);

    deallocateMemory(ptr);

    return 0;
}