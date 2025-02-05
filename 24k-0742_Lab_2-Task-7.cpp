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

void matrixMultiplication(int **A, int **B, int **C, int row1, int col1, int col2)
{
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < col1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
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
    cout << "Enter number of rows of Matrix 1:";
    cin >> row1;
    cout << "Enter number of columns of Matrix 1:";
    cin >> col1;
    cout << "Enter number of rows of Matrix 2:";
    cin >> row2;
    cout << "Enter number of columns of Matrix 2:";
    cin >> col2;

    if (col1 != row2)
    {
        cout << "Matrices cannot be multiplied" << endl;
        return 0;
    }

    int **A = allocateMemory(row1, col1);
    int **B = allocateMemory(row2, col2);
    int **C = allocateMemory(row1, col2);

    matrixInput(A, row1, col2);
    matrixInput(B, row2, col2);

    cout << "Matrix 1" << endl;
    matrixDisplay(A, row1, col1);
    cout << "Matrix 2" << endl;
    matrixDisplay(B, row2, col2);

    cout << "Matrix 3" << endl;
    matrixMultiplication(A, B, C, row1, col1, col2);
    matrixDisplay(C, row1, col2);

    deallocateMemory(A, row1);
    deallocateMemory(B, row2);
    deallocateMemory(C, row1);

    return 0;
}