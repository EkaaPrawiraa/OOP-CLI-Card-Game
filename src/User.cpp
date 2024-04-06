#include "User.hpp"

// Constructor implementation
User::User(string username, float weight, int uang) : Role(username, weight, uang) {}

// Destructor implementation
User::~User() {}

// Virtual function implementations
void User::next() {}
void User::membeli() {}
void User::menjual() {}
int User::calculate_tax() {
    // Implementation of tax calculation goes here
    return 0; // Placeholder return value
}

// Non-virtual function implementations
void User::CetakLadang(){}
void User::Tanam(){
    
}
void User::Memanen(){}
