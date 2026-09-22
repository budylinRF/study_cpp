//
// Created by Ruslan on 22.09.2026.
//
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack s1;
    s1.push(5);
    s1.push(5);
    s1.push(5);
    s1.push(5);
    cout << "stack size: " << s1.getSize() << endl;
    cout << "stack top: " << s1.getTop() << endl;
    s1.printStack();
    return 0;
}
