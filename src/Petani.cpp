#include "Role\\Petani.hpp"

Petani::Petani(string username, float weight, int uang, Matrix item, vector<Plant> p, Matrix P) : Role(username, weight, uang, item), plant(p), P(P){}

// Destructor implementation
Petani::~Petani(){}

// Virtual function implementations
void Petani::next(){}
void Petani::membeli() {}
void Petani::menjual() {}
int Petani::calculate_tax() {
    // Implementation of tax calculation goes here
    return 0; // Placeholder return value
}

// Non-virtual function implementations
void Petani::CetakLadang(){
    P.display("Ladang");
}
void Petani::Tanam(){
    
}
void Petani::Memanen(){

}
void Petani::setMatrix(){
    for(int i =0; i < plant.size(); i++){
        pair<char, int> index = plant.at(i).getColumnAndRowIndex(plant.at(i).getlocation());
        P.set(index.first, index.second, plant.at(i).getKode());
    }
}
