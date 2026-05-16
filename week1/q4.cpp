#include <iostream>
#include <vector>
using namespace std;

class Bank {
private:
    string customerName;
    long long accountNumber;
    string accountType;
    long double balance;

public:
    Bank(string name = "", long long accNum = 0, string accType = "", long double bal = 0)
        : customerName(name), accountNumber(accNum), accountType(accType), balance(bal) {}
    void input() {
        cin.ignore();
        cout << "Enter your name: ";
        getline(cin, customerName);

        cout << "Enter your Account Number: ";
        cin >> accountNumber;

        cout << "Enter your Account Type (Savings/Current): ";
        cin >> accountType;

        cout << "Enter the initial deposit amount: ";
        cin >> balance;

        cout << "Account created successfully!\n";
    }

    long long getAccountNumber() const {
        return accountNumber;
    }

    void deposit() {
        long double depositAmount;
        cout << "Enter the amount to deposit: ";
        cin >> depositAmount;

        if (depositAmount > 0) {
            balance += depositAmount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw() {
        long double withdrawAmount;
        cout<<"Balance: "<<balance<<endl;
        cout << "Enter the amount to withdraw: ";
        cin >> withdrawAmount;

        if (withdrawAmount > balance) {
            cout << "Insufficient Balance.\n";
        } else if (withdrawAmount > 0) {
            balance -= withdrawAmount;
            cout << "Amount withdrawn successfully.\n";
        } else {
            cout << "Invalid withdrawal amount.\n";
        }
    }

    void displayDetails() const {
        cout << "-------------------------------\n";
        cout << "Account Holder: " << customerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
        cout << "-------------------------------\n";
    }
};

int findCustomerByAccountNumber(const vector<Bank>& customers, long long accNum) {
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].getAccountNumber() == accNum) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<Bank> customers;
    int choice;
    long long accountNumber;

    while (true) {
        cout << "\nBanking System Menu:\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Display Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting program...\nExited";
            break;
        }

        if (choice == 1) {
            Bank newCustomer;
            newCustomer.input();
            customers.push_back(newCustomer);
            continue;
        }

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        int index = findCustomerByAccountNumber(customers, accountNumber);
        if (index == -1) {
            cout << "Account not found! Please enter a valid account number.\n";
            continue;
        }

        switch (choice) {
            case 2:
                customers[index].deposit();
                break;
            case 3:
                customers[index].withdraw();
                break;
            case 4:
                customers[index].displayDetails();
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}