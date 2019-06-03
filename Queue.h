#ifndef QUEUE_H
#define QUEUE_H

// Libraries
#include <iostream>
#include <cstdlib>

constexpr size_t MAX_SIZE = 200; // maximum capacity of queue

//FIFO (First in First out)
template <typename T>
class Queue {
private:
	T* qData; // pointer to template data type
	size_t currentSize; // size of queue

public:
	Queue(); // constructor
	Queue(const Queue<T>&); // copy constructor
	~Queue(); // destructor
	Queue<T>& operator= (const Queue<T>&); // assignment operator overloading
	size_t size() const; // returns current size of queue
	void push(T); // inserting element T at the end of queue
	T pop(); // deletes first element of queue(returns deleted element) and decrease size of queue by one
	T front(); // return 1st element of queue
	T back(); // returns last element of queue
	bool empty(); // check for empty queue
	bool full(); // check for full queue
	void print() const; // printing data about queue
};

#include "Queue.cpp"
#endif // !QUEUE_H
