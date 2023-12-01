#ifndef CAT_H
#define CAT_H

#include <string>
#include <iostream>
using namespace std;

// abstract class
class Cat {
    protected:
        string name;
    public:
        virtual string personality() = 0;
        virtual ~Cat();
};

// concrete class
class OrangeCat: public Cat {
    public:
    string personality() override {
        cout << name << " is a silly cat." << endl;
    }
};

#endif