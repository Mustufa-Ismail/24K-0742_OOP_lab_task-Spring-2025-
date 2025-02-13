#include <iostream>
using namespace std;

class wallet
{
private:
    string onwername;
    double totalBalance;
    string transactionHistory[100];
    int transactionCounter;

public:
    wallet(string name, double balance)
    {
        onwername = name;
        totalBalance = balance;
        transactionCounter = 0;
        transactionHistory[transactionCounter] = "Added $" + to_string(balance);
        transactionCounter++;
    }

    void addMoney(double money)
    {
        totalBalance += money;
        transactionHistory[transactionCounter] = "Added $" + to_string(money);
        transactionCounter++;
    }

    void spendMoney(double money)
    {
        totalBalance -= money;
        transactionHistory[transactionCounter] = "Spent $" + to_string(money);
        transactionCounter++;
        notification();
    }

    void displayTransactionHistory()
    {
        cout << "Transaction History:" << endl;
        for (int i = 0; i < transactionCounter; i++)
        {
            cout << transactionHistory[i] << endl;
        }
    }

    void displayBalance()
    {
        cout << "Total Balance:$" << totalBalance << endl;
    }

    void notification()
    {
        if (totalBalance < 0)
        {
            cout << "You are low in balance:" << endl;
            displayBalance();
        }
    }
};

int main()
{
    wallet Saad("saad", 150.99);
    Saad.addMoney(49.65);
    Saad.spendMoney(50.75);
    Saad.displayTransactionHistory();
    Saad.displayBalance();
}
