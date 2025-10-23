#ifndef QUEUE_FACTORY_HPP
#define QUEUE_FACTORY_HPP

#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"
#include <iostream>

using namespace std;

template <typename T>
class QueueFactory {
    public:
        static Queue<T>* getQueue(int maxSize = 0) {
            if (maxSize <= 0) {
                return new LinkedQueue<T>();
            } else {
                return new ArrayQueue<T>(maxSize);
            }
        }
    
};


#endif
