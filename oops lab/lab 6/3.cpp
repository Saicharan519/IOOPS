#include <iostream>
#include <stdexcept>
#include <string>
#include <cctype> // for std::isdigit
using namespace std;

// Custom exceptions
class NegativeDepositException : public invalid_argument {
public:
    NegativeDepositException() : invalid_argument("Deposit amount cannot be negative") {}
};

class InsufficientBalanceException : public runtime_error {
public:
    InsufficientBalanceException() : runtime_error("Insufficient balance for withdrawal") {}
};

class InvalidAccountNumberException : public invalid_argument {
public:
    InvalidAccountNumberException() : invalid_argument("Invalid account number format") {}
};

class BankAccount {
private:
    double balance;
    string accountNumber;

public:
    BankAccount(string accNum) : balance(0.0) {
        if (accNum.length() < 10 || !isAccountNumberValid(accNum)) {
            throw InvalidAccountNumberException();
        }
        accountNumber = accNum;
    }

    void deposit(double amount) {
        if (amount < 0) {
            throw NegativeDepositException();
        }
        balance += amount;
        cout << "Successfully deposited $" << amount << ". New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientBalanceException();
        }
        balance -= amount;
        cout << "Successfully withdrew $" << amount << ". New balance: $" << balance << endl;
    }

    double getBalance() const {
        return balance;
    }

    static bool isAccountNumberValid(const string& accNum) {
        for (char c : accNum) {
            if (!isdigit(c)) {
                return false; // Account number must be numeric
            }
        }
        return true; // All characters are digits
    }
};

int main() {
    string accountNumber;
    cout << "Enter your account number (minimum 10 digits): ";
    cin >> accountNumber;

    BankAccount account(accountNumber);
    
    int choice;
    double amount;

    while (true) {
        cout << "\nBasic Bank Account Management System" << endl;
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
        } catch (const NegativeDepositException& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (const InsufficientBalanceException& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (const InvalidAccountNumberException& e) {
            cerr << "Error: " << e.what() << endl;
            return 0; // Exit the program if the account number is invalid
        } catch (const exception& e) {
            cerr << "An unknown error occurred: " << e.what() << endl;
        }
    }

    return 0;
}
