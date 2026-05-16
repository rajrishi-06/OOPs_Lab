#include <iostream>
using namespace std;

class SimpleInterestCalculator {
private:
    double principal;
    double rate;
    int time;

public:
    SimpleInterestCalculator(double p, double r = 10.0, int t = 5) {
        principal = p;
        rate = r;
        time = t;
    }
    double calculateInterest() {
        return (principal * rate * time) / 100;
    }
    void display() {
        cout << "Principal Amount: " << principal << endl;
        cout << "Rate of Interest: " << rate << "%" << endl;
        cout << "Time Period: " << time << " years" << endl;
        cout << "Simple Interest: " << calculateInterest() << endl;
    }
};

int main() {
    double principal, rate;
    int time;
    char choice;

    cout << "Enter Principal Amount: ";
    cin >> principal;

    cout << "Do you want to enter Rate of Interest and Time Period? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Enter Rate of Interest (%): ";
        cin >> rate;
        cout << "Enter Time Period (years): ";
        cin >> time;
        SimpleInterestCalculator obj(principal, rate, time);
        obj.display();
    } else {
        SimpleInterestCalculator obj(principal);
        obj.display();
    }

    return 0;
}