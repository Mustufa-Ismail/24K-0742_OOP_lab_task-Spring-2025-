#include <iostream>
using namespace std;

int *allocateMemory(int n)
{
    int *ptr = new int[n];
    return ptr;
}

void userInput(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter number " << i + 1 << ": ";
        cin >> ptr[i];
    }
}

int sum(int *ptr, int n)
{
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum += ptr[i];
    }
    return sum;
}

void displayArray(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ptr[i] << endl;
    }
}

void deallocateMemory(int *ptr)
{
    delete[] ptr;
    cout << "Memory has been freed";
}

int main()
{
    int n;
    cout << "Enter the number of integers: ";
    cin >> n;

    int *ptr = allocateMemory(n);

    userInput(ptr, n);
    displayArray(ptr, n);
    cout << "Sum of the array is: " << sum(ptr, n) << endl;

    deallocateMemory(ptr);

    return 0;
}