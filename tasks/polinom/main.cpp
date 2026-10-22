//
// Created by Ruslan on 29.09.2026.
//

#include <iostream>
#include "polinom.h"

using namespace std;

int main() {
    int A1[] = {-20, 10, -4, 5};
    Polinom<int> p1(A1, sizeof(A1)/sizeof(int));

    p1.printPolinom();
    //cout << p1; // 5 * x^3 - 4*x^2 + 10*x - 20

    return 0;
}