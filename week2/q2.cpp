#include <iostream>
using namespace std;

class Car {
protected:
    string model;
    int year;
public:
    Car(string mod, int yr) : model(mod), year(yr) {}
    void displayCarInfo() {
        cout << "Model: " << model << ", Year: " << year << endl;
    }
};

class ElectricCar : public Car {
protected:
    int battery_capacity;
    int charging_time;
public:
    ElectricCar(string mod, int yr, int battery, int chargeTime) : Car(mod, yr), battery_capacity(battery), charging_time(chargeTime) {}
    void get_battery_status() {
        cout << "Battery Capacity: " << battery_capacity << " kWh, Charging Time: " << charging_time << " hours" << endl;
    }
};

class SmartElectricCar : public ElectricCar {
private:
    bool isAutonomous;
    bool wifiConnectivity;

public:
    SmartElectricCar(string mod, int yr, int battery, int chargeTime, bool autonomous, bool wifi) : ElectricCar(mod, yr, battery, chargeTime), isAutonomous(autonomous), wifiConnectivity(wifi) {}
    void self_drive() {
        if (isAutonomous)
            cout << model << " is driving autonomously!" << endl;
        else
            cout << model << " does not support self-driving." << endl;
    }
    void remote_control() {
        if (wifiConnectivity)
            cout << model << " can be controlled remotely via Wi-Fi." << endl;
        else
            cout << model << " does not have remote control functionality." << endl;
    }
    void displaySmartCarInfo() {
        displayCarInfo();
        get_battery_status();
        cout << "Autonomous Driving: " << (isAutonomous ? "Yes" : "No") << endl;
        cout << "Wi-Fi Connectivity: " << (wifiConnectivity ? "Enabled" : "Disabled") << endl;
    }
};

int main() {
    SmartElectricCar mySmartCar("Tesla Model S", 2023, 100, 1, true, true);
    cout << "Car Details:\n";
    mySmartCar.displaySmartCarInfo();
    mySmartCar.self_drive();
    mySmartCar.remote_control();
    return 0;
}