#include <iostream>
#include <stdexcept>

void myFunction() {
    std::cout << "Before throwing exception." << std::endl;
    throw std::runtime_error("An error occurred.");
    std::cout << "After throwing exception." << std::endl; // This line will not be executed
}

// int main() {
//     try {
//         myFunction();
//     } catch (const std::exception& e) {
//         std::cout << "Caught exception: " << e.what() << std::endl;
//     }
//     return 0;
// }