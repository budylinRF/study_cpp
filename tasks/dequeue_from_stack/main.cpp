//
// Created by Ruslan on 20.10.2026.
//

#include <iostream>
#include <stack>

using namespace std;

template <class T>
class Dequeue {
    stack <T> left;
    stack <T> right;
    stack <T> print;

    int getRightSize() {
        return right.size();
    }

    int getLeftSize() {
        return left.size();
    }

    T leftTop(T value) {
        return left.top();
    }

    T rightTop(T value) {
        return right.top();
    }

public:
    Dequeue();

    Dequeue(stack <T> left_, stack <T> right_) {
        while (!left_.empty()) {
            left.push(left_.top());
            left_.pop();
        }
        while (!right_.empty()) {
            right.push(right_.top());
            right_.pop();
        }
    }

    void push_front(T value) {
        left.push(value);
    }

    void push_back(T value) {
        right.push(value);
    }

    void pop_back() {
        if (right.empty()) {
            while (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        }
        if (!right.empty()) right.pop();
    }

    void pop_front() {
        if (left.empty()) {
            while (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        }
        if (!left.empty()) left.pop();
    }

    int getSize() {
        return left.size() + right.size();
    }

    void printDq() {
        while (!right.empty()) {
            print.push(right.top());
            right.pop();
        }
        while (!print.empty()) {
            cout << print.top() << endl;
            right.push(print.top());
            print.pop();
        }

        while (!left.empty()) {
            cout << left.top() << endl;
            print.push(left.top());
            left.pop();
        }
        while (!print.empty()) {
            left.push(print.top());
            print.pop();
        }

        cout << "right stack: " << getRightSize() << ", left stack: " << getLeftSize() << endl;
    }

    friend ostream& operator<<(ostream& os, const Dequeue& dq) {
        stack<T> left = dq.left;
        stack<T> right = dq.right;
        stack<T> print;
        while (!right.empty()) {
            print.push(right.top());
            right.pop();
        }
        while (!print.empty()) {
            cout << print.top() << endl;
            right.push(print.top());
            print.pop();
        }

        while (!left.empty()) {
            cout << left.top() << endl;
            print.push(left.top());
            left.pop();
        }
        while (!print.empty()) {
            left.push(print.top());
            print.pop();
        }
        return os;
    }

};

int main() {

    stack <int> s1;
    stack <int> s2;

    s1.push(3);
    s1.push(2);
    s1.push(1);
    s2.push(4);
    s2.push(5);
    s2.push(6);

    Dequeue <int> dq1(s1, s2);
    //dq1.pop_back();
    //cout << dq1.getSize() << endl;
    //dq1.pop_front();
    //cout << dq1.getSize() << endl;

    //dq1.printDq();

    cout << dq1;

    return 0;
}
