//
// Created by Ruslan on 20.10.2026.
//

#ifndef STUDY_CPP_DEQUEUE_H
#define STUDY_CPP_DEQUEUE_H


class Dequeue {
private:
    int start;
    int end;
    int count;
    int size;
    int *buffer;
public:
    Dequeue() {}

    Dequeue(int start, int end) {}

    Dequeue(const Dequeue & other) {}

    Dequeue & operator=(const Dequeue & other) {}

    int getCount() const;
    bool isEmpty() const;
    bool isFull() const;
    int back() const;
    void pop_front();
    void pop_back();
    void push_front(int value);
    void push_back(int value);
};


#endif //STUDY_CPP_DEQUEUE_H
