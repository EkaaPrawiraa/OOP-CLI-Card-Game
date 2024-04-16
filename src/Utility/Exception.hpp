#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;


class GameException : public exception {
public:
    /* Pure virtual method */
    virtual const char* what() const throw() = 0;
};

/* Exception Children */
class GameInvalidExc : public GameException {
private:
    string message;

public:
    GameInvalidExc(const string& msg) : message(msg) {}

    const char* what() const throw() {
        return message.c_str();
    }
};

#endif
