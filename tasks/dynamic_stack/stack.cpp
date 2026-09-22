//
// Created by Ruslan on 22.09.2026.
//
#include <iostream>
#include "stack.h"

Stack::Stack() : buffer(nullptr), size(0), top(-1) {}
Stack::Stack(const Stack& other) : size(other.size), top(other.top) {
    buffer = new int[size];
    if (top != -1) {
        for (int i = 0; i < top + 1; i++) buffer[i] = other.buffer[i];
    }
}

Stack &Stack::operator=(const Stack &other) {
    if (this != &other) {
        int* newBuffer = new int[other.size];
        for (int i = 0; i <= other.top; ++i) newBuffer[i] = other.buffer[i];

        delete[] buffer;

        buffer = newBuffer;
        size   = other.size;
        top    = other.top;
    }
    return *this;
}

void Stack::push(int value) {
    if (top + 1 >= size) {
        int newSize = (size == 0) ? 1 : size * 2;
        int* newBuffer = new int[newSize];
        for (int i = 0; i <= top; ++i) newBuffer[i] = buffer[i];
        delete[] buffer;
        buffer = newBuffer;
        size = newSize;
    }
    buffer[++top] = value;
}

int Stack::pop() {
    if (top == -1) {

        return 0;
    }
    return buffer[top--];
}

int Stack::getTop() const {
    return buffer[top];
}

int Stack::getSize() const {
    return top + 1;
}

void Stack::printStack() const {
    if (top == -1) {
        return;
    }
    for (int i = top; i >= 0; i--) std::cout << buffer[i] << std::endl;
}

Stack::~Stack() {
    delete[] buffer;
}
