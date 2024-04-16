#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;



class GameInvalidExc : public exception {
private:
    string message;

public:
    GameInvalidExc(const string& msg) : message(msg) {}

    const char* what() const throw() {
        return message.c_str();
    }
};

#endif
