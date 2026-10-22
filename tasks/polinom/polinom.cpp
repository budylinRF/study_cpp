//
// Created by Ruslan on 29.09.2026.
//

#include "polinom.h"

#include <iostream>
#include <ostream>

template <class T>
class Polinom {

private:
    T *buffer = new T[1]();
    int size = 0;

public:

    Polinom() = default;

    Polinom(T *buf, int s_) : size(s_), buffer(nullptr) {
        while (size > 1 && buf[size - 1] == "0") {
            size--;
        }

        buffer = new T[size];
        for (int i = 0; i < size; i++) {
            buffer[i] = buf[i];
        }
        delete[] buf;
    }

    Polinom(const Polinom &other) : size(other.size) {
        while (size > 1 && other.buffer[size - 1] == "0") {
            size--;
        }
        for (int i = 0; i < size; i++) {
            buffer[i] = other.buffer[i];
        }
    }

    void printPolinom() {
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                std::cout << buffer[i] << "*X^" << i;
            }
            std::cout << buffer[i] << "*X^" << i  << " +";
        }
    }

    friend std::ostream & operator<<(std::ostream &os, const Polinom &obj) {
        for (int i = 0; i < obj.size; i++) {
            if (obj.buffer[i] == ) {}
        }
    }

    ~Polinom() {
        delete[] buffer;
    }
};
