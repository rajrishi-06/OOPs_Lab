#include <iostream>
using namespace std;

class Rectangle {
private:
    double breadth;
    double length;

public:
    Rectangle(double l = 0, double b = 0) : length(l), breadth(b) {}
    void input() {
        cout << "Enter length and breadth: ";
        cin >> length >> breadth;
    }
    void displayPerimeter() {
        cout << "Perimeter of the rectangle: " << calcPerimeter(*this) << endl;
    }
    friend double calcPerimeter(const Rectangle& obj);
};
inline double calcPerimeter(const Rectangle& obj) {
    return (obj.breadth * 2) + (obj.length * 2);
}
int main() {
    Rectangle object; 
    object.input();   
    object.displayPerimeter(); 
    return 0;
}