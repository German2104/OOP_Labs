#pragma once  // говорит компилятору что данный файл должен быть включен только один раз

#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>


class Five {
private:
    unsigned char *data_;
    size_t size_;
    size_t capacity_;

public:
    Five();

    Five(const size_t &n, unsigned char t = '0');

    Five(const std::string& other);

    Five(const Five &other);

    Five(std::initializer_list<unsigned char> &other);

    Five(Five &&other) noexcept;

    Five &operator=(const Five &other);

    Five &operator=(Five &&other);

    size_t Size() const noexcept;

    size_t Capacity() const noexcept;

    void Clear() noexcept;

    Five operator+(const Five &other) const;

    Five operator-(const Five &other) const;

    bool operator>(const Five &other) const;

    bool operator<(const Five &other) const;

    bool operator==(const Five &other) const;


    virtual ~Five() noexcept;
};
