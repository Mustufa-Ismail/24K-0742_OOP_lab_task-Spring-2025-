#include <iostream>
#include <exception>

using namespace std;

class QueueOverflowException : public exception
{
};

class QueueUnderflowException : public exception
{
};

template <typename T>
class Queue
{
private:
    T data[10];
    int count;

public:
    Queue() : count(0) {}

    void enqueue(T value)
    {
        if (count < 10)
        {
            data[count++] = value;
        }
        else
        {
            throw QueueOverflowException();
        }
    }

    void dequeue()
    {
        if (count > 0)
        {
            for (int i = 0; i < count - 1; i++)
            {
                data[i] = data[i + 1];
            }
            count--;
        }
        else
        {
            throw QueueUnderflowException();
        }
    }
};

int main()
{
    Queue<int> q1;
    Queue<int> q2;
    try
    {
        q1.enqueue(1);
        q1.enqueue(2);
        q1.enqueue(3);
        q1.enqueue(4);
        q1.enqueue(5);
        q1.enqueue(6);
        q1.enqueue(7);
        q1.enqueue(8);
        q1.enqueue(9);
        q1.enqueue(10);
        q1.enqueue(11);

        q2.dequeue();
    }
    catch (QueueOverflowException &e)
    {
        cout << "Exception caught Queue overflow error" << endl;
    }
    catch (QueueUnderflowException &e)
    {
        cout << "Exception caught Queue underflow error" << endl;
    }

    return 0;
}