#include <iostream>
#include <stdexcept>

using namespace std;

class Calculator {
public:
    double divide(double numerator, double denominator) {
        if (denominator == 0)
            throw runtime_error("Division by zero is not allowed.");
        return numerator / denominator;
    }
};

int main() {
    Calculator calc;
    double num, den;

    while (true) {
        cout << "Enter numerator: ";
        if (!(cin >> num)) {
            cout << "Invalid input! Please enter numeric values.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cout << "Enter denominator: ";
        if (!(cin >> den)) {
            cout << "Invalid input! Please enter numeric values.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        try {
            double result = calc.divide(num, den);
            cout << "Result: " << result << endl;
            break;
        } catch (runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}