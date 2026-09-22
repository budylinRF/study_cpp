//
// Created by Ruslan on 22.09.2026.
//

#ifndef STUDY_CPP_STACK_H
#define STUDY_CPP_STACK_H


class Stack {
private:
    int* buffer;
    int size;
    int top;

public:
    Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);

    void push(int val_);
    int pop();
    void printStack() const;

    int getTop() const;
    int getSize() const;

    ~Stack();
};


#endif //STUDY_CPP_STACK_H
