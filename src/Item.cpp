#include "item/Item.hpp"

// Plant class implementation
Item::Item(const string &kodeHuruf, const string &name, int price)
    : kodeHuruf(kodeHuruf), name(name), price(price) {}

Item::Item(const Item& other)
    : kodeHuruf(other.kodeHuruf), name(other.name), price(other.price) {}

Item::~Item() {}

string Item::getname() const {
    return name;
}

string Item::getKode() const{
    return kodeHuruf;
}

int Item::getprice() const{
    return price;
}
string Item::getclassname(){
    return "Item";
}

