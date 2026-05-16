#include <iostream>
#include <utility>
using namespace std;

template <typename T>
void findMinMax(T a, T b, pair<T, T>& result) {
    if (a < b) {
        result.first = a;
        result.second = b;
    } else {
        result.first = b;
        result.second = a;
    }
}
int main() {
    pair<int, int> intResult;
    findMinMax(10, 20, intResult);
    cout << "Min: " << intResult.first << ", Max: " << intResult.second << endl;

    pair<double, double> doubleResult;
    findMinMax(5.5, 2.3, doubleResult);
    cout << "Min: " << doubleResult.first << ", Max: " << doubleResult.second << endl;

    pair<char, char> charResult;
    findMinMax('z', 'a', charResult);
    cout << "Min: " << charResult.first << ", Max: " << charResult.second << endl;

    return 0;
}
