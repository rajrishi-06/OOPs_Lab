#include <iostream>
using namespace std;

inline double volume(double length, double breadth, double height) {
    return length * breadth * height;
}

int main() {
    double length, breadth, height;
    cout << "Enter length, breadth, and height of the cuboid: ";
    cin >> length >> breadth >> height;
    cout << "Volume of the cuboid: " << volume(length, breadth, height) << endl;
    return 0;
}