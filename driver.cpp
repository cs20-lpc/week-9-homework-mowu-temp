// g++ -Wall -Wextra *.cpp -o main

#include "QueueFactory.hpp"
#include <string>
#include <iostream>

using namespace std;

int main () {

    Queue<int> * linkedQueue = QueueFactory<int>::getQueue();
    cout << linkedQueue->getLength() << endl;
    try {
        linkedQueue->front();
    } catch (string e) {
        cout << e << endl;
    }
    try {
        linkedQueue->back();
    } catch (string e) {
        cout << e << endl;
    }
    for (int i = 0; i < 10; i++) {
        linkedQueue->enqueue(i*100);
    }
    cout << linkedQueue->getLength() << endl;
    cout << linkedQueue->front() << endl;
    cout << linkedQueue->back() << endl;
    for (int i = 0; i < 5; i++) {
        cout << "dequeuing " << linkedQueue->front() << endl;
        linkedQueue->dequeue();
        cout << linkedQueue->getLength() << endl;
        cout << "next " << linkedQueue->front() << endl;
    }
    cout << "back " << linkedQueue->back() << endl;
    linkedQueue->enqueue(2000);
    cout << "back " << linkedQueue->back() << endl;
    linkedQueue->clear();
    cout << linkedQueue->getLength() << endl;
    try {
        linkedQueue->front();
    } catch (string e) {
        cout << e << endl;
    }
    try {
        linkedQueue->back();
    } catch (string e) {
        cout << e << endl;
    }

    delete linkedQueue;
    linkedQueue = nullptr;

    Queue<int> * arrayQueue = QueueFactory<int>::getQueue(10);
    cout << arrayQueue->getLength() << endl;
    try {
        cout << arrayQueue->front() << endl;
    } catch (string e) {
        cout << e << endl;
    }
    try {
        cout << arrayQueue->back() << endl;
    } catch (string e) {
        cout << e << endl;
    }
    for (int i = 0; i < 10; i++) {
        arrayQueue->enqueue(i+900);
    }
    try {
        arrayQueue->enqueue(-1);
    } catch (string e) {
        cout << e << endl;
    }
    arrayQueue->dequeue();
    arrayQueue->dequeue();
    cout << arrayQueue->getLength() << endl;
    cout << arrayQueue->front() << endl;
    cout << arrayQueue->back() << endl;
    arrayQueue->enqueue(1);
    arrayQueue->enqueue(3);
    try {
        arrayQueue->enqueue(-1);
    } catch (string e) {
        cout << e << endl;
    }
    cout << arrayQueue->back() << endl;
    arrayQueue->clear();
    cout << arrayQueue->getLength() << endl;
    try {
        cout << arrayQueue->front() << endl;
    } catch (string e) {
        cout << e << endl;
    }
    try {
        cout << arrayQueue->back() << endl;
    } catch (string e) {
        cout << e << endl;
    }


    delete arrayQueue;

    return 0;

}