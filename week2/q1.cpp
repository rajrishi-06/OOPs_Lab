#include <iostream>
using namespace std;

class Shop {
private:
    string customer_name;
    int customer_id;
    int no_of_orders;

public:
    Shop(string name, int id, int orders) {
        customer_name = name;
        customer_id = id;
        no_of_orders = orders;
    }
    ~Shop() {
        cout << "Destructor called for Customer ID: " << customer_id << endl;
    }
    void display() {
        cout << "Customer ID: " << customer_id << ", Name: " << customer_name << ", No. of Orders: " << no_of_orders << endl;
    }
};

int main() {
    Shop customer1("Alice", 101, 5);
    Shop customer2("Bob", 102, 2);
    Shop customer3("Charlie", 103, 7);
    Shop customer4("David", 104, 3);
    Shop customer5("Emma", 105, 4);

    cout << "Customer Details:" << endl;
    customer1.display();
    customer2.display();
    customer3.display();
    customer4.display();
    customer5.display();

    return 0;
}