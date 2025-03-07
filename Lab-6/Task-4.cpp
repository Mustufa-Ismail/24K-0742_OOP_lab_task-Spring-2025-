#include<iostream>
using namespace std;

class Account{
    protected:
    int accountNumber;
    float balance;

    Account(int accountNumber,float balance) : accountNumber(accountNumber) , balance(balance) {}

    void displayDetails(){
        cout << "Account Number:" << accountNumber << endl;
        cout << "Balance:" << balance << endl;
    }
};

class SavingsAccount : protected Account{
    protected:
    float interestRate;

    public:
    SavingsAccount(int accountNumber,float balance, float interestRate) : Account(accountNumber,balance) ,interestRate(interestRate) {} 

    void displayDetails(){
        cout << "\nAccount Number:" << accountNumber << endl;
        cout << "Balance:" << balance << endl;
        cout << "Interest Rate" << interestRate << endl;
    }
};

class CheckingAccount : protected Account{
    protected:
    float overDraftLimit;

    public:
    CheckingAccount(int accountNumber,float balance, float overDraftLimit) : Account(accountNumber,balance) , overDraftLimit(overDraftLimit) {}

    void displayDetails(){
        cout << "\nAccount Number:" << accountNumber << endl;
        cout << "Balance:" << balance << endl;
        cout << "Over Draft Limit:" << overDraftLimit << endl;
    }
};

int main(){
    SavingsAccount sa(123,500.00,50.5);
    CheckingAccount ca(123,500.00,15000);

    sa.displayDetails();
    ca.displayDetails();
}