#include <iostream>
#include <exception>
using namespace std;

class DimensionMismatchException : public exception
{
public:
    const char *what() const noexcept override
    {
        return " Exception caught Dimension do not match";
    }
};

template <typename T>
class Matrix
{
private:
    T **elements;
    int rows, cols;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        elements = new T *[rows];
        for (int i = 0; i < rows; i++)
        {
            elements[i] = new T[cols];
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] elements[i];
        }
        delete[] elements;
    }

    void Input()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> elements[i][j];
            }
        }
    }

    void Display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T> &other)
    {
        if (rows != other.rows || cols != other.cols)
        {
            throw DimensionMismatchException();
        }
        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.elements[i][j] = elements[i][j] + other.elements[i][j];
            }
        }
        return result;
    }
};

int main()
{
    int r1, c1, r2, c2;
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    Matrix<int> m1(r1, c1);
    Matrix<int> m2(r2, c2);
    cout << "Enter elements for first matrix:" << endl;
    m1.Input();
    cout << "Enter elements for second matrix:" << endl;
    m2.Input();

    try
    {
        Matrix<int> m3 = m1 + m2;
        m3.Display();
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }
}