#include <iostream>
using namespace std;

class BankAccount
{
private:
    string name;
    int accountNumber;
    double balance;

public:
    void createAccount()
    {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Initial Balance: ";
        cin >> balance;

        cout << "\nAccount Created Successfully!\n";
    }

    void deposit()
    {
        double amount;
        cout << "Enter deposit amount: ";
        cin >> amount;

        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully!\n";
        }
        else
        {
            cout << "Invalid amount!\n";
        }
    }

    void withdraw()
    {
        double amount;
        cout << "Enter withdraw amount: ";
        cin >> amount;

        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful!\n";
        }
        else
        {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void display()
    {
        cout << "\n===== Account Details =====\n";
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account;
    int choice;

    do
    {
        cout << "\n===== Banking Management System =====";
        cout << "\n1. Create Account";
        cout << "\n2. Deposit Money";
        cout << "\n3. Withdraw Money";
        cout << "\n4. Display Account";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            account.createAccount();
            break;

        case 2:
            account.deposit();
            break;

        case 3:
            account.withdraw();
            break;

        case 4:
            account.display();
            break;

        case 5:
            cout << "Thank you for using Banking System!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}