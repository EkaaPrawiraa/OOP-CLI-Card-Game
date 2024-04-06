#include "Petani.hpp"

// Constructor implementation
Petani::Petani(string username, float weight, int uang) : Role(username, weight, uang) {}

// Destructor implementation
Petani::~Petani() {}

// Virtual function implementations
void Petani::next() {}
void Petani::membeli() {}
void Petani::menjual() {}
int Petani::calculate_tax() {
    // Implementation of tax calculation goes here
    return 0; // Placeholder return value
}

// Non-virtual function implementations
void Petani::CetakLadang(int row, int col){
    for(int i = 0; i < row;i++){
        
    }
}
void Petani::Tanam(){
    
}
void Petani::Memanen(){

}
