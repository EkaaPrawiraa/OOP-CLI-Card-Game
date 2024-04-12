#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
using namespace std;
class Item {
    public:
        Item(const string &kodeHuruf,const string &name, int price);
        Item(const Item&);
        ~Item();
        virtual string getclassname(){
            return "Item";
        }
        string getname() const;
        string getKode() const;
        int getprice() const;

    protected:
        string kodeHuruf;
        string name;
        int price;
};


#endif