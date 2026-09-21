//
// Created by Ruslan on 21.09.2026.
//
#include  <iostream>
#include "words.h"
using namespace std;

int main() {

    const char str[] = "word dog peace dog cat turtle time";
    const char target[] = "dog";

    const int count = countWords(str, target);

    cout << "word " << target << "count " << count << " times in string" << endl;

    return 0;
}