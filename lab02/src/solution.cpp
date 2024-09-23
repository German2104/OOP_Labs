#include "../include/solution.h"
#include <string>

Five::Five() : size_{0}, data_{nullptr}, capacity_{0} {
    std::cout << "Default constructor" << std::endl;
}

Five::Five(const size_t& n, unsigned char t) : size_{n}, data_{new unsigned char [size_]}, capacity_{n} {
    for (size_t i{0}; i < size_; ++i) {
        data_[i] = t;
    }
}

Five::Five(const std::string& other) : size_{other.size()}, data_{new unsigned char [size_]}, capacity_{size_} {
    for (size_t i{0}; i < size_; ++i) {
        data_[i] = other[i];
    }
}


