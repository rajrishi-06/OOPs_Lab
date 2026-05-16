#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
    char gender;

public:
    Person(string name, int age, char gen) : name(name), age(age), gender(gen) {}
    void displayPersonInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Vehicle {
protected:
    string vehicleType;
    long long registrationNumber;
    int mileage;
public:
    Vehicle(string vT, long long rN, int m) : vehicleType(vT), registrationNumber(rN), mileage(m) {}
    void displayVehicleInfo() {
        cout << "Vehicle Type: " << vehicleType << endl;
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Mileage: " << mileage << " km/l" << endl;
    }
};

class Driver : public Person, public Vehicle {
private:
    long licenseNumber;
    int experienceYears;
public:
    Driver(string name, int age, char gen, string vT, long long rN, int m, long lN, int eY) 
        : Person(name, age, gen), Vehicle(vT, rN, m), licenseNumber(lN), experienceYears(eY) {}
    void printDriverInfo() {
        cout << "-----------------------" << endl;
        cout << "       DRIVER INFO     " << endl;
        cout << "-----------------------" << endl;
        displayPersonInfo();
        displayVehicleInfo();
        cout << "License Number: " << licenseNumber << endl;
        cout << "Experience: " << experienceYears << " years" << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    Driver d1("John Doe", 35, 'M', "Truck", 987654321, 12, 123456789, 10);
    d1.printDriverInfo();
    return 0;
}