#include <iostream>
#include <string>

using namespace std;

class BankAccount {
    int account_number;
    string account_holder_name;
    int balance;

public:
    BankAccount() {
        account_number = 12345;
        account_holder_name = "Sai"; 
        balance = 10000;
    }

    void display() {
        cout << "Welcome to your account, " << account_holder_name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Your current balance is " << balance << endl;
    }

    void deposit() {
        int x;
        cout << "Enter the deposit amount: " << endl;
        cin >> x;
        balance += x;
        cout << "Successfully deposited" << endl;
        cout << "Updated balance: " << balance << endl;
    }

    void withdraw() {
        int x;
        cout << "Enter the withdrawal amount: " << endl;
        cin >> x;
        if (balance >= x) {
            balance -= x;
            cout << "Successfully withdrawn" << endl;
            cout << "Updated balance: " << balance << endl;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }
};

int main() {
    BankAccount b;
    int choice;

    cout << "Welcome to the Banking System" << endl;
    b.display();

    cout << "Enter your choice:" << endl;
    do {
        cout << "1. Deposit\n2. Withdraw\n3. Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                b.deposit();
                break;
            case 2:
                b.withdraw();
                break;
            case 3:
                cout << "Exiting the program" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 3);

    return 0;
}
