#ifndef CAT_H
#define CAT_H

#include <string>

struct Cat {
    std::string name;
    std::string colour;
    std::string * toyArray;
    int length;
    
    Cat(std::string name, std::string colour);
    Cat(const Cat &other);
    Cat(Cat &&other);
    Cat &operator=(const Cat &other);
    Cat &operator=(Cat &&other);
    ~Cat();

    void giveToy(std::string toy);

};

#endif