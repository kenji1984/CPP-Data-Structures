#include <iostream>

template <typename T>
class ArrayBasedQueue 
{
	private:
		T* elements; // array to hold elements
		int head;  // index of the first item 
		int tail;  //index of the last item
		int numElements;  // num of elements in array
		int capacity;  //maximum capacity of array
		
		/**
		*   allocate elements with some spaces the heap with newLength
		*   copy each element from original array to elements, starting from head
		*/
		void resize(int newLength);
						
	public:	
		ArrayBasedQueue();
		ArrayBasedQueue(ArrayBasedQueue& other);
		ArrayBasedQueue& operator=(const ArrayBasedQueue& rhs);
		~ArrayBasedQueue();
		
		/**
		*   add an item to elements at the tail % capacity position
		*   tail will go back to starting after reaching the end
		*   if numElements reach maximum capacity, resize array by 2x
		*/
		void enqueue(const T& item);
		
		/**
		*   removes an item from elements at head % capacity position and returns it
		*   if elements is empty, return NULL
		*   if size is equal to capacity / 4. resize elements by 1/2
		*/
		T dequeue();
		
		/**
		*   check whether numElements == 0
		*/
		bool isEmpty();		
};

template <typename T>
ArrayBasedQueue<T>::ArrayBasedQueue()
	: head(0), tail(0), numElements(0), capacity(1) 
{
	elements = new T[1];
}

template <typename T>
ArrayBasedQueue<T>::ArrayBasedQueue(ArrayBasedQueue<T>& other) : head(other.head), 
	tail(other.tail), numElements(other.numElements), capacity(other.capacity)
{
	T* original = elements;
	elements = new T[numElements];
	for (int i = 0; i < numElements; i++)
	{
		elements[i] = other.elements[i];
	}
	delete[] original;
}

template <typename T>
ArrayBasedQueue<T>& ArrayBasedQueue<T>::operator=(const ArrayBasedQueue<T>& rhs)
{
	head = rhs.head;
	tail = rhs.tail;
	numElements = rhs.numElements;
	capacity = rhs.capacity;
	
	T* original = elements;
	elements = new T[numElements];
	for (int i = 0; i < numElements; i++)
	{
		elements[i] = rhs.elements[i];
	}
	delete[] original;
	return *this;	
}

template <typename T>
ArrayBasedQueue<T>::~ArrayBasedQueue() 
{
	delete[] elements;
}

template <typename T>
void ArrayBasedQueue<T>::resize(int newLength)
{
	T* copy = elements;
	elements = new T[newLength];
	
	for (int i = 0; i < numElements ; i++)
	{
		elements[i] = copy[head++];
		head %= capacity;
	}
	delete[] copy;
	head = 0;
	tail = numElements;
	capacity = newLength;
}

template <typename T>
void ArrayBasedQueue<T>::enqueue(const T& item)
{
	if (numElements == capacity) resize(2 * numElements);
	tail %= capacity;
	elements[tail++] = item;
	++numElements;
}

template <typename T>
T ArrayBasedQueue<T>::dequeue()
{
	if (numElements > 0 && numElements <= (capacity / 4)) 
	{ 
		resize(capacity / 2);
	}
	if (isEmpty()) return NULL;
	
	head %= capacity;
	T item = elements[head];
	elements[head++] = NULL;
	--numElements;
	
	return item;
}

template <typename T>
bool ArrayBasedQueue<T>::isEmpty()
{
	return numElements == 0;
}

int main() { 
	ArrayBasedQueue<std::string> q;
	q.enqueue("hello");
	q.enqueue("world");
	
	ArrayBasedQueue<std::string> w(q);
	ArrayBasedQueue<std::string> x = w = q;
	return 0; 
}