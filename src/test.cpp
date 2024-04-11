#include <iostream>
#include <string>

std::string createHeader(std::string type) {
    int width = (6 * type.length()) + 1;
    int ladangWidth = width - 6; // 20 is the length of "[ Ladang ]"
    int equalSignsWidth = (ladangWidth -4 ) / 2; // Deducting two '=' for [ and ] brackets
    std::string header = std::string(equalSignsWidth, '=') + "[ Ladang ]" + std::string(equalSignsWidth, '=') + std::string(width % 2, '=');
    return header;
}

int main() {
    std::string n;
    std::cin>>n; // Example value for n
    std::string header = createHeader(n);
    std::cout << header << std::endl;

    return 0;
}