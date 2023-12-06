#include <string>
using namespace std;

class Pizza {
    public:
        virtual float price() const = 0;
        virtual string desc() const = 0;
        virtual ~Pizza();
};

class CrustAndSauce : public Pizza {
    public:
        float price() const override {
            return 5.99;
        }
        string desc() const override {
            return "Pizza";
        }
};

class Decorator : public Pizza {
    protected:
        Pizza *component;
    public:
        Decorator(Pizza * component) : component{component} {}
        virtual ~Decorator() {
            delete component;
        }
};

class Pepperoni : public Decorator {
    public:
        Pepperoni(Pizza * component): Decorator{component} {}
        float price() const override {
            return component->price() + 2;
        }
        string desc() const override {
            return component->desc() + " with pepperoni";
        }
};

class StuffedCrust : public Decorator {
    public:
        StuffedCrust(Pizza * component) : Decorator{component} {}
        float price() const override {
            return component->price() + 1.5;
        }
        string desc() const override {
            return component->desc() + " with stuffed crust";
        }
};