#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

//Initializing member variables
template <typename T>
Queue<T>::Queue() :
	qData(nullptr),
	currentSize(0)
{
	std::cout << "Constructor called for queue" << '\n';
}

template <typename T>
Queue<T>::Queue(const Queue<T>& theOther) {
	size_t _size = theOther.size();
	qData = new T[_size];

	//copying
	for (size_t i = 0; i < _size; ++i)
		qData[i] = theOther.qData[i];
	currentSize = _size;

	std::cout << "Copy constructor called: ";
}

template <typename T>
Queue<T>::~Queue() {
	// avoiding memory leakage
	currentSize = 0;
	delete[] qData;
	qData = nullptr;
}

template <typename T>
Queue<T>& Queue<T>::operator= (const Queue<T>& theOther) {
	// self assignment checking
	if (this == &theOther)
		return *this;
	size_t _size = theOther.size();
	T *temp = new T[_size]; // avoiding allocation fail, first allocate, after delete
	delete[] qData;
	qData = temp;
	for (size_t j = 0; j < _size; ++j)
		qData[j] = theOther.qData[j];
	currentSize = _size;
	return *this;
}

template <typename T>
inline size_t Queue<T>::size() const {
	return currentSize;
}

template <typename T>
inline bool Queue<T>::empty() {
	// if size is zero will return true, otherwise false
	return size() == 0;
}

template <typename T>
inline bool Queue<T>::full() {
	// if size of current queue is equal to capacity of queue, function will return true, otherwise false
	return size() == MAX_SIZE;
}

template <typename T>
void Queue<T>::push(T value) {
	// check for queue overflow
	if (full()) {
		std::cerr << "Queue Overflow happened, can not push element to the queue" << '\n';
		exit(EXIT_FAILURE);
	}
	// creating temporary pointer
	T *temp;
	temp = new T[currentSize + 1]; // memory allocation for temp

	//copying original data to the newly allocated memory segment
	for (size_t i = 0; i < currentSize; ++i)
		temp[i] = qData[i];
	temp[currentSize] = value;

	//if not null, then free
	if (qData != nullptr)
		delete[] qData;

	qData = temp;

	// increasing size of queue by one
	currentSize++;
}

template <typename T>
T Queue<T>::pop() {
	//temporary pointer and value to be returned
	T* temp;
	T poppedElement;

	// check for queue underflow
	if (empty()) {
		std::cerr << "Queue undeflow happened, no element in queue for popping" << '\n';
		exit(EXIT_FAILURE);
	}

	// store first element
	poppedElement = qData[0];
	size_t j = 0; //loop variable

	// queue is not empty
	if (currentSize) {
		temp = new T[currentSize - 1];

		// copy original data to newly allocated memory block
		for (size_t i = 1; i < currentSize; ++i)
			temp[j++] = qData[i];

		// memory releasing
		if (qData != nullptr)
			delete[] qData;

		// temp -> qData
		qData = temp;

		// decreasing curren size
		currentSize--;
	}
	// queue is empty
	else {
		if (qData != nullptr)
			delete[] qData;
		qData = nullptr;
	}
	return poppedElement;
}

template <typename T>
inline T Queue<T>::front() {
	if (!empty())
		return qData[0];
	else {
		std::cerr << "Queue is empty" << '\n';
		exit(EXIT_FAILURE);
	}
}

template <typename T>
inline T Queue<T>::back() {
	if (!empty())
		return qData[currentSize - 1];
	else {
		std::cerr << "Queue is empty" << '\n';
		exit(EXIT_FAILURE);
	}
}

template <typename T>
void Queue<T>::print() const {
	for (size_t i = 0; i < currentSize; ++i)
		std::cout << qData[i] << " ";
	std::cout << '\n';
}
#endif // !QUEUE_CPP

