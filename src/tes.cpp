#include <iostream>
#include <typeinfo>

class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {
};

int main() {
    Base* basePtr = new Derived();

    if (typeid(*basePtr) == typeid(Base)) {
        std::cout << "basePtr points to an object of type Base\n";
    } else if (typeid(*basePtr) == typeid(Derived)) {
        std::cout << "basePtr points to an object of type Derived\n";
    }

    delete basePtr;
    return 0;
}