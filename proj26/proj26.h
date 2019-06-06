#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include<stack>

using namespace std;

// Stack template
template <class T>
class Queue
{
private:
	struct QueueNode
	{
		
		T value;        
		int head;   
		int tail;   	
		int capacity;
		int currentSize;
		int currentPeek;

	};

	QueueNode *buffer;

	// Private member functions
	void growBufferIfNecessary(QueueNode *);

public:
	// Constructor
	Queue()
	{
		string queueArray[10];

		buffer->queueArray[0]; 
		tail=0;
		head =0;
		int capacity=10;
		int currentSize=0;
		int currentPeek=0;

	}

	copyQueue(T)
	{



	}

	// Destructor
	~Queue();

	void insertNode(T);
	bool searchNode(T);
	void remove(T);
	void getPath(T);

	void add(T);

	void remove();

	int peek();

	void peekReset()
	{

	}

	void peekHasNext()
	{

	}

	void peekNext()
	{

	}

};

template <class T>
void Queue<T>::add(T item)
{

	buffer*[++tail] = item;
	currentSize++;

}

template <class T>
void Queue<T>::remove()
{

	buffer*[currentSize--];
	++head;

}

template <class T>
int Queue<T>::peek()
{

	return head;

}

#endif