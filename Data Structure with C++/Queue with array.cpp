#include <iostream>
using namespace std;
//queue using linear array
template <class t> //declares queue class as template : means we can put char/int/float nything
class queue
{
	int front, rear, capacity; // 'front' & 'rear' hold index of front & rear of queue..
	t * array;		//queue itself
	public:
		queue(int m)
		{
			capacity = m;
			array = new t[capacity];
			front = rear = 0;
		}
		void enqueue(t k);  // enters element in queue ..last in
		void dequeue() ;	// deletes element from queue.. from beginning
		t peek();			// displays 1st element of the queue
		void display();		//displays whole queue
		
};

template <class t>
void queue<t>::enqueue(t k)
{
	try{
		if(rear == capacity)	// if reached capacity limit, can't add anymore
			throw 1;
		else					// add at rear index otherwise
		{
			this->array[rear] = k;
			++rear;				// then increment rear index
		}
	}
	catch (int e)
	{
		if (e == 1)
		cout<<"Queue full"<<endl;
	}
}

template <class t>
void queue<t>:: dequeue ()
{
	try{
		if(rear == front)			//can't deequeue if queue is empty
			throw 1;
		else						//shift elements 1 position towards left.. thus dequeuing 1st element
		{
			for(int i = 0; i<rear; i++)
			{
				array[i]= array[i+1];
			}
			rear--;					// rear index decremented 1 index
		}
	}
	catch (int e)
	{
		if (e == 1)
		cout<<"Queue Empty"<<endl;
	}
}

template <class t>
t queue <t>:: peek()				
{
	return array[front];
}

template <class t>
void queue <t> :: display ()
{
	if (front==rear)
		cout<<"Nothing to show.. Queue empty"<<endl;
	for(int i = 0; i<rear; i++)		//simply loop over the whole queue and display
	{
		cout<<array[i]<<"<- ";
	}
	cout<<endl;	
	
}	

int main()
{
	queue <char> q(5);
	q.enqueue('s');
	q.enqueue('t');
	q.enqueue('a');
	q.enqueue('r');
	q.enqueue('k');
	q.enqueue('t');			//Queue Full
	q.enqueue('t');			//Queue Full
	q.display(); 			//stark
	q.dequeue();			//tark
	cout<<q.peek()<<endl;	//t
	q.dequeue();			//ark
	q.dequeue();			//rk
	q.enqueue('t');			//rkt
	q.enqueue('e');			//rkte
	q.display();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();			//Queue Empty
	q.display();			//Nothing to show
}

