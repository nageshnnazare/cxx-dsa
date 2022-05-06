#include <iostream>
#include <string>

// #define SIMPLE_CAR
#define LUXURY_CAR

class Tyre {
protected:
    std::string name;
    int pressure;
public:
    Tyre(std::string name, int pressure) : name{ name }, pressure{ pressure } {};
    std::string getName() { return name; }
    int getPressure() { return pressure; }
};

class SimpleTyre : public Tyre {
public:
    SimpleTyre() : Tyre("Simple-Tyre", 50) {};
};

class LuxuryTyre : public Tyre {
public:
    LuxuryTyre() : Tyre("Luxury-Tyre", 80) {};
};

class Body {
protected:
    std::string name;
    int strength;
public:
    Body(std::string name, int strength) : name{ name }, strength{ strength } {};
    std::string getName() { return name; }
    int getStrength() { return strength; }
};

class SimpleBody : public Body {
public:
    SimpleBody() : Body("Simple-Body", 55) {};
};

class LuxuryBody : public Body {
public:
    LuxuryBody() : Body("Luxury-Body", 85) {};
};

class Car {
protected:
    std::string name;
    Tyre* tyre;
    Body* body;
public:
    Car(std::string name) : name{ name } {};

    void setTyre(Tyre* t) { tyre = t; };
    void setBody(Body* b) { body = b; };
    void printDetails() {
        std::cout << "Car : " << name << std::endl
            << "Tyre : " << tyre->getName() << std::endl
            << "Pressure : " << tyre->getPressure() << std::endl
            << "Body : " << body->getName() << std::endl
            << "Strength : " << body->getStrength() << std::endl;
    }
};

class CarFactory {
private:
    Car* car;
protected:
    virtual Tyre* buildTyre() = 0;
    virtual Body* buildBody() = 0;
public:
    virtual Car* buildWholeCar() = 0;
};

class SimpleCarFactory : public CarFactory {
    Tyre* buildTyre() {
        return new SimpleTyre();
    }
    Body* buildBody() {
        return new SimpleBody();
    }
    Car* buildWholeCar() {
        Car* car = new Car("SimpleCar");
        car->setTyre(buildTyre());
        car->setBody(buildBody());
        return car;
    }
};

class LuxuryCarFactory : public CarFactory {
    Tyre* buildTyre() {
        return new LuxuryTyre();
    }
    Body* buildBody() {
        return new LuxuryBody();
    }
    Car* buildWholeCar() {
        Car* car = new Car("LuxuryCar");
        car->setTyre(buildTyre());
        car->setBody(buildBody());
        return car;
    }
};


int main(int argc, char const* argv[]) {
#ifdef SIMPLE_CAR
    CarFactory* factory = new SimpleCarFactory;
#else 
    CarFactory* factory = new LuxuryCarFactory;
#endif

    Car* car = factory->buildWholeCar();
    car->printDetails();

    return 0;
}
