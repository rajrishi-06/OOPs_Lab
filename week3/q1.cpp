#include <iostream>
using namespace std;

class RectangleType {
protected:
    double length;
    double width;

public:
    // Constructor
    RectangleType(double l = 1.0, double w = 1.0) : length(l), width(w) {}

    // Getter for area
    double area() const {
        return length * width;
    }

    // Unary Operators (++ and --)
    RectangleType &operator++() { // Pre-increment
        ++length;
        ++width;
        return *this;
    }

    RectangleType operator++(int) { // Post-increment
        RectangleType temp = *this;
        ++(*this);
        return temp;
    }

    RectangleType &operator--() { // Pre-decrement
        if (length > 1 && width > 1) {
            --length;
            --width;
        } else {
            cout << "Dimensions cannot be negative or zero." << endl;
        }
        return *this;
    }

    RectangleType operator--(int) { // Post-decrement
        RectangleType temp = *this;
        --(*this);
        return temp;
    }

    // Binary Operator (-)
    RectangleType operator-(const RectangleType &rect) const {
        if (length - rect.length > 0 && width - rect.width > 0) {
            return RectangleType(length - rect.length, width - rect.width);
        } else {
            cout << "Subtraction results in invalid dimensions." << endl;
            return *this;
        }
    }

    // Relational Operators (== and !=)
    bool operator==(const RectangleType &rect) const {
        return this->area() == rect.area();
    }

    bool operator!=(const RectangleType &rect) const {
        return !(*this == rect);
    }

    // Comparison Operators (>, <, >=, <=)
    bool operator>(const RectangleType &rect) const {
        return this->area() > rect.area();
    }

    bool operator<(const RectangleType &rect) const {
        return this->area() < rect.area();
    }

    bool operator>=(const RectangleType &rect) const {
        return !(*this < rect);
    }

    bool operator<=(const RectangleType &rect) const {
        return !(*this > rect);
    }

    // Input/Output Operators (>> and <<)
    friend ostream &operator<<(ostream &out, const RectangleType &rect) {
        out << "Length: " << rect.length << ", Width: " << rect.width << ", Area: " << rect.area();
        return out;
    }

    friend istream &operator>>(istream &in, RectangleType &rect) {
        cout << "Enter length: ";
        in >> rect.length;
        cout << "Enter width: ";
        in >> rect.width;
        if (rect.length <= 0 || rect.width <= 0) {
            cout << "Invalid dimensions. Resetting to default (1.0)." << endl;
            rect.length = 1.0;
            rect.width = 1.0;
        }
        return in;
    }
};

int main() {
    RectangleType rect1(5, 4), rect2(3, 2), result;

    // Demonstrate Unary Operators
    cout << "Original Rectangle 1: " << rect1 << endl;
    ++rect1;
    cout << "After Pre-increment: " << rect1 << endl;
    rect1++;
    cout << "After Post-increment: " << rect1 << endl;
    --rect1;
    cout << "After Pre-decrement: " << rect1 << endl;
    rect1--;
    cout << "After Post-decrement: " << rect1 << endl;

    // Demonstrate Binary Operator (-)
    cout << "Original Rectangle 2: " << rect2 << endl;
    result = rect1 - rect2;
    cout << "After Subtraction (rect1 - rect2): " << result << endl;

    // Demonstrate Relational Operators
    if (rect1 == rect2) {
        cout << "rect1 and rect2 have the same area." << endl;
    } else {
        cout << "rect1 and rect2 have different areas." << endl;
    }

    if (rect1 != rect2) {
        cout << "rect1 and rect2 are not equal." << endl;
    }

    // Demonstrate Comparison Operators
    if (rect1 > rect2) {
        cout << "rect1 is greater than rect2." << endl;
    }

    if (rect1 < rect2) {
        cout << "rect1 is smaller than rect2." << endl;
    }

    // Demonstrate Input/Output Operators
    RectangleType rect3;
    cin >> rect3;
    cout << "You entered: " << rect3 << endl;

    return 0;
}