#include <Product.hpp>
#include <stdexcept>


Product::Product(std::string kodehuruf, const std::vector<ProductConfig>& vec) {
    bool found = false;
    for (const auto& config : vec) {
        if (config.kodeHuruf == kodehuruf) {
            found = true;
            this->kodeHuruf = config.kodeHuruf;
            this->name = config.name;
            this->tipe = config.type;
            this->origin = config.origin;
            this->added_weight = config.addedWeight;
            this->price = config.price;
            break;
        }
    }
    if (!found) {
        throw std::invalid_argument("ProductConfig with kodeHuruf " + kodehuruf + " not found");
    }
}