#include <iostream>
#include <vector>
using namespace std;

class Plant {
protected:
    string name, type;
    double growthRate;
public:
    Plant(string n, string t, double g) : name(n), type(t), growthRate(g) {}
    virtual void display() const {
        cout << name << " (" << type << ") - Growth Rate: " << growthRate << " cm/year\n";
    }
    virtual ~Plant() {}
};

class FloweringPlant : public Plant {
protected:
    string flowerColor;
public:
    FloweringPlant(string n, double g, string c) : Plant(n, "Flowering", g), flowerColor(c) {}
    void display() const {
        Plant::display();
        cout << "Flower Color: " << flowerColor << endl;
    }
};

class NonFloweringPlant : public Plant {
protected:
    bool hasSpores;
public:
    NonFloweringPlant(string n, double g, bool s) : Plant(n, "Non-Flowering", g), hasSpores(s) {}
    void display() const {
        Plant::display();
        cout << "Reproduces via Spores: " << (hasSpores ? "Yes" : "No") << endl;
    }
};

class Rose : public FloweringPlant { public: Rose() : FloweringPlant("Rose", 30, "Red") {} };
class Sunflower : public FloweringPlant { public: Sunflower() : FloweringPlant("Sunflower", 150, "Yellow") {} };
class Fern : public NonFloweringPlant { public: Fern() : NonFloweringPlant("Fern", 50, true) {} };
class Moss : public NonFloweringPlant { public: Moss() : NonFloweringPlant("Moss", 5, true) {} };

int main() {
    vector<Plant*> plants;
    plants.push_back(new Rose());
    plants.push_back(new Sunflower());
    plants.push_back(new Fern());
    plants.push_back(new Moss());

    for (size_t i = 0; i < plants.size(); i++) {
        plants[i]->display();
        cout << endl;
        delete plants[i];
    }
    
    return 0;
}