#include "Queue.h"
#include <string>

/* Testing of Queue class */

int main() {
	std::cout << "\t\t\t\t\t ***  Testing Queue implementation  ***";
	std::cout << std::string(3, '\n');

		/* Test for char data type */
	std::cout << "Testing for char data type" << "\n\n";

	// char data type, initialization, constructor is called
	Queue<char> Q;

	// testing push function
	char ch;
	for (ch = 'a'; ch <= 'f'; ++ch) {
		std::cout << "Pushing: " << ch << '\n';
		Q.push(ch);
	}
	std::cout << '\n';

    // testing size function
	std::cout << "Size of queue is: " << Q.size() << '\n';
	
	// testing copy constructor
	Queue<char> Q1(Q);
	Q1.print();

	//testing front and back functions
	std::cout << "First element in queue Q: " << Q.front() << '\n';
	std::cout << "Last element in queue Q: " << Q.back() << '\n';

	// testing assignment operator
	std::cout << "Assignment operator: ";
	Queue<char> Q2;
	std::cout << "Assigning happening and printing elements of newly created queue: ";
	Q2 = Q;
	Q2.print();
	std::cout << '\n';

	// testing pop function
	while (!Q.empty()) {
		std::cout << "Popping: " << Q.front() << '\n';
		Q.pop();
	}
	std::cout << '\n';

	// check for full
	Q.full() ? std::cout << "Queue is full" : std::cout << "Queue is not full";
	std::cout << '\n';

	// check for empty
	Q.empty() ? std::cout << "Queue is empty" : std::cout << "Queue is not empty";
	std::cout << std::string(3, '\n');

	/*********************************************************************** END FOR CHAR*/

	/* Test for int data type */
	std::cout << "Testing for int data type" << "\n\n";
	
	// int data type, initialization, constructor is called
	Queue<int> q;

	// testing push
	for (int i = 0; i <= 5; ++i) {
		std::cout << "Pushing: " << i << '\n';
		q.push(i);
	}
	std::cout << '\n';

	// testing size function
	std::cout << "Size of queue is: " << q.size() << '\n';

	// testing copy constructor
	Queue<int> q1(q);
	q1.print();

	//testing front and back functions
	std::cout << "First element in queue Q: " << q.front() << '\n';
	std::cout << "Last element in queue Q: " << q.back() << '\n';

	// testing assignment operator
	std::cout << "Assignment operator: ";
	Queue<int> q2;
	std::cout << "Assigning happening and printing elements of newly created queue: ";
	q2 = q;
	q2.print();
	std::cout << '\n';

	// testing pop function
	while (!q.empty()) {
		std::cout << "Popping: " << q.front() << '\n';
		q.pop();
	}
	std::cout << '\n';

	// check for full
	q.full() ? std::cout << "Queue is full" : std::cout << "Queue is not full";
	std::cout << '\n';

	// check for empty
	q.empty() ? std::cout << "Queue is empty" : std::cout << "Queue is not empty";

	/************************************************************************* END FOR INT*/

	std::cin.get(); // in order to prevent console closing when running program
	return 0;
}