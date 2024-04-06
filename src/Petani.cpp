#include "Role/Petani.hpp"

Petani::Petani(string username, float weight, int uang, inventory item) : Role(username, weight, uang, item) {}

// Destructor implementation
Petani::~Petani(){}

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
        for(int j =0; j < col; j++){

        }
    }
}
void Petani::Tanam(){
    
}
void Petani::Memanen(){

}
void Petani::setMatrix(Matrix P){
    for(int i =0; i < plant.size(); i++){
        pair<char, int> index = plant.at(i).getColumnAndRowIndex(plant.at(i).getlocation());
    
    }
}
