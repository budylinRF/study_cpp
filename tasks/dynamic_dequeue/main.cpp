//
// Created by Ruslan on 06.10.2026.
//

#include <deque>
#include <iostream>

using namespace std;

class Dequeue {
private:
    int start = -1;
    int end = -1;
    int size;
    int count = 0;
    int* buffer;

public:

    Dequeue() {}

    Dequeue(int start, int end) {

    }

    int getCount() const {
        return count;
    }

    bool isEmpty() const {
        return !count;
    }

    bool isFull() const {
        return (end + 1)%size == start;
    }

    int back() const {
        if (isEmpty()) {
            return -1;
        }
        return buffer[end];
    }

    void pop_front() {
        if (!isEmpty()) {
            if (start == end) {
                start = end = -1;
            }
            else {
                start = (start + 1) % size;
            }
            count--;
        }
    }

    void pop_back() {
        if (!isEmpty()) {
            if (start == end) {
                end = end = -1;
            }
            else {
                end = (end - 1) % size;
            }
            count--;
        }
    }

    void push_front(int value) {
        if (!isFull()) {
            if (isEmpty()) {
                start = end = 0;
            }
            else {
                start = (start-1 + size)%size;
                buffer[start] = value;
                count++;
            }
        }
    }
};


int main() {
    std::deque<int> numbers = {1, 2, 3, 4, 5};

    /*
    int first = numbers.front();
    int last = numbers.back();
    std::cout << first << std::endl;
    std::cout << last << std::endl;
    */

    std::cout << "Dequeue before resize: " << std::endl;

    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "Dequeue after resize: " << std::endl;

    numbers.resize(10);

    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "Copy num1 dequeue: " << std::endl;
    std::deque<int> numbers2 = numbers;
    for (int n : numbers2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "num2 after resize: " << std::endl;
    numbers2.resize(4);
    for (int n : numbers2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    numbers2.push_front(10); // 10 1 2 3 4, size 5
    numbers2.push_back(3); // 10 1 2 3 4 3, size 6
    numbers2.emplace(numbers2.begin(), 50); // 50 10 1 2 3 4 3, size 7
    std::cout << "size dequeue num2: " << numbers2.size() << std::endl;

    for (int n : numbers2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    numbers.swap(numbers2);
    std::cout << "num after swap: " << std::endl;
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    std::cout << "num2 after swap: " << std::endl;
    for (int n : numbers2) {
        std::cout << n << " ";
    }
}
