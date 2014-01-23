#include <iostream>

using namespace std;

const int SIZE = 10;
const int NUM = 2;
const int IN = 0;
const int OUT = 1;

class Stack
{
private:
	int cur;
	int *buf;
	int size;

public:
	Stack(int size = SIZE){
		this->size = size;
		buf = new int[SIZE];
		cur = -1;
	}
	~Stack(){
		delete[] buf;
	}

	void push(int val){
		if(isFull()){
			cout << "full. push failed" << endl;
			return ;
		}else{
			buf[++cur] = val;
		}
	}

	void pop(){
		if(isEmpty()){
			cout << "Empty.pop failed" << endl;
			return ;
		}else{
			buf[cur--] = 0;
		}
	}

	int top(){
		if(isEmpty()){
			cout << "Empty. top failed" << endl;
			return -1;
		}
		return buf[cur];
	}

	bool isFull(){
		return cur == size - 1;
	}

	bool isEmpty(){
		return cur == -1;
	}

};

class MyQueue
{
private:
	Stack *qbuf;
	int elem;

public:
	MyQueue(){
		qbuf = new Stack[NUM];
		elem = 0;
	}
	~MyQueue(){
		delete[] qbuf;
	}

	void enqueue(int val){
		while(!qbuf[OUT].isEmpty()){
			qbuf[IN].push(qbuf[OUT].top());
			qbuf[OUT].pop();
		}
		qbuf[IN].push(val);
	}

	int dequeue(){
		//cout << qbuf[IN].isEmpty() << endl;
		while(!qbuf[IN].isEmpty()){
			qbuf[OUT].push(qbuf[IN].top());
			qbuf[IN].pop();
			//cout << "pushInOut" << endl;
		}
		elem = qbuf[OUT].top();
		qbuf[OUT].pop();
		return elem;

	}
};



int main()
{
	/* Test stack
	Stack sk1;
	//cout << "after push" << endl;
	for(int i = 0; i < SIZE; i++){
		sk1.push(i);
		//cout << sk1.top() << " ";
		//sk1.pop();
	}
	//cout << endl;
	//sk1.pop();
	//sk1.top();
	*/

	//Test myqueue
	MyQueue q1;
	//cout << "enqueue ";
	for(int i = 0; i < SIZE; i++){
		q1.enqueue(i);
		cout << "enqueue "<< i << endl;
		//cout << "dequeue " << q1.dequeue() << endl;
	}
	q1.enqueue(3);
	cout << endl;
	for(int i = 0; i < SIZE; i++){
		
		cout << "dequeue " << q1.dequeue()<< endl;
	}
	q1.dequeue();

}