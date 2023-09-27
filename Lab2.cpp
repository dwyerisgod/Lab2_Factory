#include <iostream>
#include <string>

using namespace std;

class Coffee {
public:
    virtual string getName() = 0;
    virtual void makeCoffee() = 0;
    virtual ~Coffee () {}
};

class Espresso : public Coffee {
public:
    string getName() override {
        return "Espresso";
    }

    void makeCoffee() override {
        cout << "We're preparing espresso coffee!" << endl;
    }

    ~Espresso() {}
};

class Americano : public Coffee {
public:
    string getName() override {
        return "Americano";
    }

    void makeCoffee() override {
        cout << "We're preparing american coffee!" << endl;
    }

    ~Americano () {}
};

class Latte : public Coffee {
public:
    string getName() override {
        return "Latte";
    }

    void makeCoffee() override {
        cout << "We're preparing latte coffee!" << endl;
    }

    ~Latte () {}
};

class Cappuchino : public Coffee {
public:
    string getName() override {
        return "Cappuchino";
    }

    void makeCoffee() override {
        cout << "We're preparing cappuchino coffee!" << endl;
    }

    ~Cappuchino () {}
};

class CoffeeFactory {
public:
    virtual Coffee* createCoffee() = 0; // Добавлено виртуальное объявление
    virtual ~CoffeeFactory () {}
};

class EspressoCoffee : public CoffeeFactory {
public:
    virtual Coffee* createCoffee() override {
        return new Espresso();
    }

    ~EspressoCoffee () {}
};

class AmericanoCoffee : public CoffeeFactory {
public:
    virtual Coffee* createCoffee() override {
        return new Americano();
    }
    
    ~AmericanoCoffee () {}
};

class LatteCoffee : public CoffeeFactory {
public:
    virtual Coffee* createCoffee() override {
        return new Latte();
    }

    ~LatteCoffee () {}
};

class CappuchinoCoffee : public CoffeeFactory {
public:
    virtual Coffee* createCoffee() override {
        return new Cappuchino();
    }

    ~CappuchinoCoffee () {}
};

int main() {
    EspressoCoffee espressoHouse;
    AmericanoCoffee americanoHouse;
    LatteCoffee latteHouse;
    CappuchinoCoffee cappuchinoHouse;
    
    Coffee* coffee1 = espressoHouse.createCoffee();
    Coffee* coffee2 = americanoHouse.createCoffee();
    Coffee* coffee3 = latteHouse.createCoffee();
    Coffee* coffee4 = cappuchinoHouse.createCoffee();

    coffee1 -> makeCoffee();
    cout << "Напиток: " << coffee1 -> getName() << endl;

    coffee2 -> makeCoffee();
    cout << "Напиток: " << coffee2 -> getName() << endl;

    coffee3 -> makeCoffee();
    cout << "Напиток: " << coffee3 -> getName() << endl;

    coffee4 -> makeCoffee();
    cout << "Напиток: " << coffee4 -> getName() << endl;

    delete coffee1;
    delete coffee2;
    delete coffee3;
    delete coffee4;

    return 0;
}
