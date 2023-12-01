#include "cat.h"
#include <utility>
using namespace std;

Cat::Cat(string name, string colour) : name{name}, colour{colour}, toyArray{new string [5]}, length{0} {}

Cat::Cat(const Cat &other) : name{other.name}, colour{other.name}, toyArray{new string [5]}, length(other.length) {
    for (int i = 0; i < other.length; i++) {
        toyArray[i] = other.toyArray[i];
    }
}

Cat::Cat(Cat &&other) : name{other.name}, colour{other.colour}, toyArray{other.toyArray}, length(other.length) {
    other.toyArray = nullptr;
}

Cat & Cat::operator=(const Cat &other) {
    if (this == &other) {
        return *this;
    } else {
        name = other.name;
        colour = other.colour;
        length = other.length;
        delete [] toyArray;
        toyArray = new string [5];
        for (int i = 0; i < length; i++) {
            toyArray[i] = other.toyArray[i];
        }
        return *this;
    }
}

Cat & Cat::operator=(Cat &&other) {
    swap(name, other.name);
    swap(colour, other.colour);
    swap(length, other.length);
    swap(toyArray, other.toyArray);
    return *this;
}

Cat::~Cat() {
    delete [] toyArray;
}

void Cat::giveToy(string toy) {
    toyArray[length] = toy;
    length++;
}