//
// Created by Ruslan on 29.09.2026.
//
#include <iostream>
#ifndef STUDY_CPP_POLINOM_H
#define STUDY_CPP_POLINOM_H

template <class T> class Polinom {
private:
    T *buffer;
    int size;

public:
    Polinom();
    Polinom(T *buf, int size);

    Polinom(const Polinom &other);

    const void printPolinom();

    ~Polinom();
};
template <typename T>
Polinom<T>::Polinom(T* buf, int s_) : size(s_), buffer(nullptr) {
    while (size > 1 && buf[size - 1] == T(0)) {
        size--;
    }
    buffer = new T[size];
    for (int i = 0; i < size; i++) {
        buffer[i] = buf[i];
    }
}

template <typename T>
Polinom<T>::~Polinom() {
    delete[] buffer;
}

template <typename T>
void Polinom<T>::printPolinom();



#endif //STUDY_CPP_POLINOM_H
