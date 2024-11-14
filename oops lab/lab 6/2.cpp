#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0.0) {}

    // Function to deposit money
    void deposit(double amount) {
        if (amount < 0) {
            throw invalid_argument("Deposit amount cannot be negative");
        }
        balance += amount;
        cout << "Successfully deposited $" << amount << ". New balance: $" << balance << endl;
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount < 0) {
            throw invalid_argument("Withdrawal amount cannot be negative");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient funds for withdrawal");
        }
        balance -= amount;
        cout << "Successfully withdrew $" << amount << ". New balance: $" << balance << endl;
    }

    // Function to get the current balance
    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account;
    int choice;
    double amount;

    while (true) {
        cout << "\nSimple Bank Transaction System" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    account.deposit(amount);
                    break;
                case 2:
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    account.withdraw(amount);
                    break;
                case 3:
                    cout << "Current balance: $" << account.getBalance() << endl;
                    break;
                case 4:
                    cout << "Exiting..." << endl;
                    return 0;
                default:
                    cout << "Invalid choice! Please select a valid option." << endl;
            }
        } catch (const invalid_argument& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (const runtime_error& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (...) {
            cerr << "An unknown error occurred." << endl;
        }
    }

    return 0;
}
