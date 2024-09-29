#include "../include/solution.h"
#include <string>
#include <cstring>
#include <stdexcept>


Five::Five() : size_{0}, data_{nullptr}, capacity_{0} {
    std::cout << "Default constructor" << std::endl;
}

Five::Five(const size_t &n, unsigned char t) : size_{n}, data_{new unsigned char [n]}, capacity_{n} {
    for (size_t i{0}; i < size_; ++i) {
        data_[i] = t;
    }
}

Five::Five(const std::string &other) : size_{other.size()}, data_{new unsigned char [other.size()]},
                                       capacity_{other.size()} {
    size_t temp = size_ - 1;
    for (size_t i = 0; i < other.size(); ++i) {
        if (other[i] < '0' || other[i] > '4') {
            throw std::invalid_argument("Некорректный пятеричный символ.");
        }
        data_[temp--] = other[i];
    }
}


Five::Five(const std::initializer_list<unsigned char> &other)
    : size_{other.size()}, capacity_{other.size()}, data_{new unsigned char [other.size()]} {
    size_t i = 0;
    for (const unsigned char &val : other) {
        data_[i++] = val + '0';
    }
}


Five::Five(const Five &other) : data_(new unsigned char[other.Size()]), size_(other.Size()),
                                capacity_(other.Capacity()) {
    std::uninitialized_copy(other.data_, other.data_ + other.size_, data_);
    size_ = other.size_;
    capacity_ = other.capacity_;
}

Five::Five(Five &&other) noexcept : data_(other.data_), size_(other.size_), capacity_(other.capacity_) {
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}


Five &Five::operator=(const Five &other) {
    if (this != &other) {
        delete[] data_;
        capacity_ = other.capacity_;
        size_ = other.size_;
        data_ = new unsigned char[capacity_];
        std::memcpy(data_, other.data_, size_);
    }
    return *this;
}


Five &Five::operator=(Five &&other) {
    if (this != &other) {
        delete[] data_;
        capacity_ = other.capacity_;
        size_ = other.size_;
        data_ = new unsigned char[capacity_];
        std::memcpy(data_, other.data_, size_);
        other.data_ = nullptr;
        other.capacity_ = 0;
        other.size_ = 0;
    }
    return *this;
}


size_t Five::Size() const noexcept {
    return size_;
}

std::string Five::toString() const {
    std::string result;
    result.reserve(size_); // Резервируем память для повышения эффективности
    for (size_t i = size_; i > 0; --i) {
        result += static_cast<char>(data_[i - 1]);
    }
    return result;
}

Five Five::operator+(const Five &other) const {
    Five result;
    size_t sizeMax = std::max(size_, other.size_);  // Максимальный размер между двумя числами
    result.capacity_ = sizeMax + 1;  // Резервируем место для возможного переноса в следующий разряд
    result.data_ = new unsigned char[result.capacity_];
    result.size_ = 0;
    unsigned char carry = 0;  // Перенос для пятеричной системы

    for (size_t i = 0; i < sizeMax || carry; ++i) {
        unsigned char sum = carry;  // Добавляем перенос от предыдущего разряда
        if (i < size_) {
            sum += data_[i] - '0';  // Добавляем текущий разряд первого числа
        }
        if (i < other.size_) {
            sum += other.data_[i] - '0';  // Добавляем текущий разряд второго числа
        }

        carry = sum >= 5;  // Если сумма больше или равна 5, переносим 1 в следующий разряд
        result.data_[result.size_++] = (sum % 5) + '0';  // Остаток от деления на 5 — это текущий разряд
    }

    return result;
}


Five Five::operator-(const Five &other) const {
    if (*this < other) {
        throw std::invalid_argument("Результат вычитания не может быть отрицательным.");
    }

    Five result;
    result.capacity_ = size_;
    result.data_ = new unsigned char[result.capacity_];
    result.size_ = 0;
    unsigned char borrow = 0;  // Переменная для заема при необходимости

    for (size_t i = 0; i < size_; ++i) {
        // Вычитаем текущий разряд и заем
        unsigned char diff = (data_[i] - '0') - borrow;

        // Если есть соответствующий разряд в other, вычитаем его
        if (i < other.size_) {
            diff -= (other.data_[i] - '0');
        }

        // Если результат отрицательный, берем заем из следующего разряда
        if (diff >= 5) {
            borrow = 1;
            diff += 5;  // Добавляем 5, чтобы получить корректную цифру в пятеричной системе
        } else {
            borrow = 0;
        }

        // Записываем результат в массив, преобразуя обратно в символ
        result.data_[result.size_++] = diff + '0';
    }

    // Удаление ведущих нулей
    while (result.size_ > 1 && result.data_[result.size_ - 1] == '0') {
        result.size_--;
    }

    return result;
}



bool Five::operator<(const Five &other) const {
    if (size_ != other.size_) return size_ < other.size_;
    for (size_t i = size_; i-- > 0;) {
        if (data_[i] != other.data_[i]) return data_[i] < other.data_[i];
    }
    return false;
}

bool Five::operator>(const Five &other) const {
    if (size_ != other.size_) return size_ > other.size_;
    for (size_t i = size_; i-- > 0;) {
        if (data_[i] != other.data_[i]) return data_[i] > other.data_[i];
    }
    return false;
}

bool Five::operator==(const Five &other) const {
    if (size_ != other.size_) return false;
    return std::equal(data_, data_ + size_, other.data_);
}

bool Five::operator!=(const Five &other) const {
    return !(*this == other);
}

void Five::Clear() noexcept {
    delete[] data_;
    data_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

size_t Five::Capacity() const noexcept {
    return capacity_;
}


void Five::push_back(unsigned char digit) {
    if (size_ == capacity_) {
        size_t newCapacity = capacity_ == 0 ? 1 : capacity_ * 2;
        unsigned char *newDigits = new unsigned char[newCapacity];
        if (data_) {
            std::memcpy(newDigits, data_, size_);
            delete[] data_;
        }
        data_ = newDigits;
        capacity_ = newCapacity;
    }
    data_[size_++] = digit + '0';
}


Five::~Five() noexcept {
    delete[] data_;
}
