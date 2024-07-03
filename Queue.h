#ifndef queue_h
#define queue_h

#include "Node.h"

class Queue {
    NodePtr headPtr, tailPtr;
    int size;

public:
    Queue();
    ~Queue();
    void enqueue(int);
    int dequeue();
};

Queue::Queue() {
    size = 0;
    headPtr = NULL;
    tailPtr = NULL;
}

Queue::~Queue() {
    while (headPtr != NULL) {
        NodePtr temp = headPtr;
        headPtr = headPtr->get_next();
        delete temp;
    }
}

void Queue::enqueue(int x) {
    NodePtr new_node = new NODE(x);
    if (new_node) {
        if (size == 0) {
            headPtr = new_node;
        } else {
            tailPtr->set_next(new_node);
        }
        tailPtr = new_node;
        size++;
    }
}

int Queue::dequeue() {
    if (headPtr != NULL) {
        NodePtr t = headPtr;
        int value = t->get_value();
        headPtr = headPtr->get_next();
        delete t;
        size--;
        if (headPtr == NULL) {
            tailPtr = NULL;
        }
        return value;
    }
    cout << "The queue is empty" << endl;
    return -1;
}

#endif
