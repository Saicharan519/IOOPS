#include<iostream>

using namespace std;

class Bankaccount{
    int account_number;
    int balance;
    public:
    Bankaccount(){
        account_number = 12345;
        balance = 10000;
    }
    void account(){
            cout << "Welcome to your account" << endl;
            cout << "Account Number: " << account_number << endl;
            cout << "Your current balance is " << balance << endl;
    }
    void deposit(){
        int x;
        cout << "enter the deposit amount"<<endl;
        cin >> x;
        balance += x;
        cout << "successfully deposit"<<endl;
        cout << "Updated balance: " << balance << endl;
    }
    void withdraw(){
        int x;
        cout << "enter the withdraw amount"<<endl;
        cin >> x;
        if(balance >= x){
            balance -= x;
            cout << "Successfully withdrawn" << endl;
            cout << "Updated balance: " << balance << endl;
        }
        else{
            cout << "Insufficient balance" << endl;
        }
    }
};

int main(){
    Bankaccount b;
    int choice;
    cout << "Welcome to Banking System" << endl;
    b.account();
    cout << "Enter the options"<<endl;
    do{
        cout << "1. deposit \n2. withdraw\n3.exit"<<endl;
        cin >> choice;
        switch(choice){
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
    }while(choice != 3);
    return 0;
}

