#include <iostream>
using namespace std;

class Distance {
private:
    int kilometers;
    int meters;

public:
    Distance(int km = 0, int m = 0) {
    kilometers = km;
    meters = m;
    }
    void inputDistance() {
        cout << "Enter distance (kilometers and meters): ";
        cin >> kilometers >> meters;
    }
    void displayDistance() {
        cout << kilometers << " km " << meters << " m" << endl;
    }
    friend Distance addDistances(const Distance &d1, const Distance &d2);
};

Distance addDistances(const Distance& d1, const Distance& d2){
    int totalKm = d1.kilometers + d2.kilometers;
    int totalM = d1.meters + d2.meters;
    if (totalM >= 1000) {
        totalKm += totalM / 1000;
        totalM = totalM % 1000;
    }
    return Distance(totalKm, totalM);
}

int main() {
    Distance d1, d2, result;
    cout<<"Enter first distance: "<<endl;
    d1.inputDistance();
    cout<<"Enter second distance: "<<endl;
    d2.inputDistance();
    result = addDistances(d1, d2);
    cout<<"Total distance: "<<endl;
    result.displayDistance();
    return 0;
}