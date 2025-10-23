#include <string>

template <typename T>
LinkedQueue<T>::LinkedQueue() {
    head = nullptr;
    last = nullptr;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    if (this->length > 0) {
        return last->value;
    }
    throw string ("back: error, queue is empty, cannot access the back");
}

template <typename T>
void LinkedQueue<T>::clear() {
    Node* curr = head;
    while(curr != nullptr) {
        Node* old = curr;
        curr = curr->next;
        delete old;
    }
    this->length = 0;
    head = nullptr;
    last = nullptr;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    this->length = copyObj.length;
    if (this->length >= 1) {
        Node* curr = copyObj.head;
        Node* curr2 = new Node(curr->value);
        head = curr2;
        while (curr->next != nullptr) {
            Node* newNode = new Node(curr->next->value);
            curr2->next = newNode;
            curr = curr->next;
            curr2 = curr2->next;
        }
        last = curr2;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    if (this->length == 0) {
        throw string("dequeue: error, queue is empty");
    }
    if (this->length == 1) {
        delete head;
        head = nullptr;
        last = nullptr;
        this->length -= 1;
        return;
    } else {

        Node* old = head;
        head = head->next;
        delete old;
        this->length -= 1;
    }

}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    if (this->length == 0) {
        head = new Node(elem);
        last = head;
    } else {
        Node* newNode = new Node(elem);
        last->next = newNode;
        last = newNode;
    }
    this->length += 1; 
}

template <typename T>
T LinkedQueue<T>::front() const {
    if (this->length > 0) {
        return head->value;
    }
    throw string ("front: error, queue is empty, cannot access the front");
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
ostream& operator<<(ostream &out, const LinkedQueue<T> &c)
{
    if (c.isEmpty()) {
        out << "EMPTY LIST";
    } else {
        typename LinkedQueue<T>::Node * curr = c.head;
        while (curr != nullptr) {
            out << curr->value; 
            if (curr->next != nullptr) {
                out << "-";
            }
            curr = curr->next;
        }
    }
    return out;
}