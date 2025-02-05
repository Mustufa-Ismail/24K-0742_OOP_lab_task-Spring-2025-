#include <iostream>
using namespace std;

int **allocateMemory(int row, int col)
{
    int **ptr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        ptr[i] = new int[col];
    }
    return ptr;
}

void matrixInput(int **ptr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Row " << i + 1 << " Column " << j + 1 << " :";
            cin >> *(*(ptr + i) + j);
        }
    }
}

void matrixDisplay(int **ptr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        cout << " | ";
        for (int j = 0; j < col; j++)
        {
            cout << *(*(ptr + i) + j) << " | ";
        }
        cout << endl;
    }
    cout << endl;
}

void matrixAddition(int **ptr1, int **ptr2, int **ptr3, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ptr3[i][j] = ptr1[i][j] + ptr2[i][j];
        }
    }
}

void matrixSubtraction(int **ptr1, int **ptr2, int **ptr3, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ptr3[i][j] = ptr1[i][j] - ptr2[i][j];
        }
    }
}

void deallocateMemory(int **ptr, int row)
{
    for (int i = 0; i < row; i++)
    {
        delete[] ptr[i];
    }
    delete ptr;
    cout << "Memeory has been freed" << endl;
}

int main()
{
    int row1, col1, row2, col2;

    cout << "Enter the number of rows of matrix 1:";
    cin >> row1;
    cout << "Enter the number of colums of matrix 1:";
    cin >> col1;
    cout << "Enter the number of rows of matrix 2:";
    cin >> row2;
    cout << "Enter the number of columns of matrix 1:";
    cin >> col2;

    if (row1 != row2 || col1 != col2)
    {
        cout << "Addition and Subtraction cannot be performed";
        return 0;
    }

    int **ptr1 = allocateMemory(row1, col1);
    int **ptr2 = allocateMemory(row2, col2);
    int **ptr3 = allocateMemory(row1, col1);

    matrixInput(ptr1, row1, col1);
    matrixInput(ptr2, row2, col2);

    cout << "Matrix 1" << endl;
    matrixDisplay(ptr1, row1, col1);
    cout << "Matrix 2" << endl;
    matrixDisplay(ptr2, row2, col2);

    matrixAddition(ptr1, ptr2, ptr3, row1, col1);
    cout << "Addition of Matrices" << endl;
    matrixDisplay(ptr3, row1, col1);

    matrixSubtraction(ptr1, ptr2, ptr3, row1, col1);
    cout << "subtraction of Matrices" << endl;
    matrixDisplay(ptr3, row1, col1);

    deallocateMemory(ptr1, row1);
    deallocateMemory(ptr2, row2);
    deallocateMemory(ptr3, row1);

    return 0;
}
