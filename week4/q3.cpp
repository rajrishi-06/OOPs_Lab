#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
void computeGeometricSeries(T& result, T ratio, int terms) {
    result = 0;
    for (int i = 0; i < terms; ++i) {
        result += pow(ratio, i);
    }
}

int main() {
    double result;
    computeGeometricSeries(result, 2.0, 5);
    cout << "Geometric series sum (double): " << result << endl;
    float resultFloat;
    computeGeometricSeries(resultFloat, 1.5f, 4);
    cout << "Geometric series sum (float): " << resultFloat << endl;
    int resultInt;
    computeGeometricSeries(resultInt, 2, 3);
    cout << "Geometric series sum (int): " << resultInt << endl;
    return 0;
}