#include <vector>
#include <iostream>
using namespace std;

// abstract class
class Observer {
    public:
        virtual notify() = 0;
        virtual ~Observer() = 0;
}

// concrete observer
class Cat {
    Mouse * subject;
    public:
        Cat(Mouse * subject) : subject{subject} {
            subject->attach(this);
        }
        notify() override {
            cout << "MEOW! " << subject->getState() << endl;
        }
        ~Cat() {
            subject->detach(this);
        }
}

// abstract class
class Subject {
    vector<Observer *> observers;

    public:
        Subject();
        virtual notifyObservers() {
            for (auto &ob : observers) {
                ob->notify();
            }
        }
        virtual attach(Observer * ob) {
            observers.emplace_back(ob);
        };
        virtual detach(Observer * ob) {
            for (auto it = observers.begin; it != observers.end()) {
                if (*it == ob) {
                    it.erase(it);
                } else {
                    ++it;
                }
            }
        };
        virtual ~Subject() = 0;

}

// concrete class
class Mouse : public Subject {
    public:
        Mouse() {};
        string getState() {
            return "Mouse is running! SQUEAK!" << endl;
        }
        ~Mouse() {}
}