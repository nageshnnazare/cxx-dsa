#include <iostream>
#include <string>

class Toy {
protected:
    std::string name;
    float price;

public:
    virtual void prepareParts() = 0;
    virtual void combineParts() = 0;
    virtual void assembleParts() = 0;
    virtual void applyLabel() = 0;
    virtual void showProduct() = 0;
};

class Car : public Toy {
public:
    void prepareParts() {
        std::cout << "Preparing Car" << std::endl;
    }
    void combineParts() {
        std::cout << "Combining Car parts" << std::endl;
    }
    void assembleParts() {
        std::cout << "Assembling Car parts" << std::endl;
    }
    void applyLabel() {
        std::cout << "Adding Car Label" << std::endl;
        name = "car-1";
        price = 10;
    }
    void showProduct() {
        std::cout << "Car Name : " << name << std::endl
            << "Price : " << price << std::endl;
    }
};

class Bike : public Toy {
public:
    void prepareParts() {
        std::cout << "Preparing Bike" << std::endl;
    }
    void combineParts() {
        std::cout << "Combining Bike parts" << std::endl;
    }
    void assembleParts() {
        std::cout << "Assembling Bike parts" << std::endl;
    }
    void applyLabel() {
        std::cout << "Adding Bike Label" << std::endl;
        name = "bike-2";
        price = 20;
    }
    void showProduct() {
        std::cout << "Bike Name : " << name << std::endl
            << "Price : " << price << std::endl;
    }
};

class Plane : public Toy {
public:
    void prepareParts() {
        std::cout << "Preparing Plane" << std::endl;
    }
    void combineParts() {
        std::cout << "Combining Plane parts" << std::endl;
    }
    void assembleParts() {
        std::cout << "Assembling Plane parts" << std::endl;
    }
    void applyLabel() {
        std::cout << "Adding Plane Label" << std::endl;
        name = "plane-1";
        price = 30;
    }
    void showProduct() {
        std::cout << "Plane Name : " << name << std::endl
            << "Price : " << price << std::endl;
    }
};

class ToyFactory {
public:
    static Toy* createToy(int type) {
        Toy* toy = nullptr;
        switch (type) {
        case 1:
            toy = new Car;
            break;
        case 2:
            toy = new Bike;
            break;
        case 3:
            toy = new Plane;
            break;

        default:
            std::cout << "Invalid choice " << std::endl;
            return nullptr;
            break;
        }

        toy->prepareParts();
        toy->combineParts();
        toy->assembleParts();
        toy->applyLabel();

        return toy;
    }
};

int main(int argc, char const* argv[]) {

    int type = 0;
    while (true) {
        std::cout << "\nEnter Type of toy or '0' to exit : " << std::endl;
        std::cin >> type;
        if (!type) {
            break;
        }
        Toy* t = ToyFactory::createToy(type);
        if (t) {
            t->showProduct();
            delete t;
        }
    }
    std::cout << "Exiting... " << std::endl;

    return 0;
}
