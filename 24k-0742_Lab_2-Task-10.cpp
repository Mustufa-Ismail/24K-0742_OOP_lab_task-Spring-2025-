#include <iostream>
using namespace std;

int ***allocateMemory(int x, int y, int z)
{
    int ***ptr = new int **[x];
    for (int i = 0; i < x; i++)
    {
        ptr[i] = new int *[y];
        for (int j = 0; j < y; j++)
        {
            ptr[i][j] = new int[z];
        }
    }
    return ptr;
}

void userInput(int ***ptr, int x, int y, int z)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Element[" << i + 1 << "][" << j + 1 << "][" << k + 1 << "]";
                cin >> ptr[i][j][k];
            }
        }
    }
}

void display(int ***ptr, int x, int y, int z)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << ptr[i][j][k] << "";
            }
            cout << endl;
        }
        cout << endl;
    }
}

void deallocateMemory(int ***ptr, int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            delete[] ptr[i][j];
        }
        delete[] ptr[i];
    }
    delete[] ptr;
}

int main()
{
    int x, y, z;
    cout << "Enter the first dimension:";
    cin >> x;
    cout << "Enter the second dimension:";
    cin >> y;
    cout << "Enter the third dimension:";
    cin >> z;

    int ***ptr = allocateMemory(x, y, z);
    userInput(ptr, x, y, z);
    display(ptr, x, y, z);
    deallocateMemory(ptr, x, y);

    return 0;
}