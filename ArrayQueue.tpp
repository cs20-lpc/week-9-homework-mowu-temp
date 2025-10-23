#include <string>

template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    buffer = new T[i];
    maxSize = i;
    frontIndex = 0;
    backIndex = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    if (this->length == 0) {
        throw string("back: error, queue is empty, cannot access the back");
    }
    return buffer[(backIndex-1 + maxSize) % maxSize];
}

template <typename T>
void ArrayQueue<T>::clear() {
    this->length = 0;
    frontIndex = 0;
    backIndex = 0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    this->length = copyObj.length;
    maxSize = copyObj.maxSize;
    frontIndex = copyObj.frontIndex;
    backIndex = copyObj.backIndex;
    buffer = new T[maxSize];
    for (int i = 0; i < this->length; i++) {
        buffer[(i + frontIndex) % maxSize] = copyObj.buffer[(i + frontIndex) % maxSize];
    }
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if (this->length == 0) {
        throw string("dequeue: error, queue has no elements, cannot dequeue");
    }
    frontIndex = (frontIndex + 1) % maxSize;
    this->length -= 1;

}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (this->length == maxSize) {
        throw string("enqueue: error, queue is at max size, cannot enqueue");
    }
    buffer[backIndex] = elem;
    backIndex = (backIndex + 1) % maxSize;

    this->length += 1;
}

template <typename T>
T ArrayQueue<T>::front() const {
    if (this->length == 0) {
        throw string("front: error, queue is empty, cannot access the front");
    }
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
ostream& operator<<(ostream &out, const ArrayQueue<T> &c) {
    out << "[";
    for (int i = 0; i < c.getLength(); i++) {
        out << c.buffer[(i + c.frontIndex) % c.maxSize];
        if (i != c.getLength()-1) {
            out << ",";
        }
    }
    out << "]";
    return out;
}
