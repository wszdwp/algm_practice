#include <iostream>

using namespace std;

const int STACK_SIZE = 10;
const int STACK_NUM = 3;

class stack{
private:
	int capacity;
	int cur;
	int *buf;

public:
	stack(int cap = STACK_SIZE){
		capacity = cap;
		buf = new int[capacity];
		cur = -1;
	}
	~stack(){
		delete[] buf;
	}

	void push(int val){
		if( cur == capacity-1){
			cout << "stack is full" << endl;
			return;
		}
		buf[++cur] = val;
	}

	void pop(){
		if(cur == -1) {
			cout << "stack is Empty." << endl;
			return;
		}
		buf[cur--] = 0;
	}

	int top(){
		if(cur == -1) {
			cout << "stack is Empty." << endl;
			return 1;
		}
		return buf[cur];
	}

	bool isEmpty(){
		return cur == -1;
	} 

	bool isFull(){
		return cur == capacity - 1;
	}
};
 
class setOfStacks
{
private:
	int numOfStacks;
	stack *p;
	int cur;

public:
	setOfStacks(int num = STACK_NUM){
		numOfStacks = num;
		p = new stack[numOfStacks];
		cur = 0;
	}
	~setOfStacks(){
		delete[] p;
	}

	void push(int val) {
		if(p[cur].isFull()){
			if(cur == numOfStacks-1){
				cout << "stack is full" << endl;
				return;
			}
			else
				++cur;
		}

		p[cur].push(val);
	}

	void pop(){
		if(p[cur].isEmpty()){
			if(cur == 0){
				cout << "stack is empty" << endl;
				return;
			}
			else
				--cur;
		}
		p[cur].pop();
	}

	int top(){
		if(p[cur].isEmpty()){
			if(cur == 0){
				cout << "stack is empty" << endl;
				return 1;
			}
			else
				--cur;
		}
		return p[cur].top();
	}

	bool isEmpty(){
		if(cur == 0 )
			return p[cur].isEmpty();
		else
			return false;
	}

	bool isFull(){
		if(cur == numOfStacks-1)
			return p[cur].isFull();
		else
			return false;
	}

};

int main() 
{
	//Test stacks
	cout << "Test stacks" << endl;
	stack mystack;
	cout << "push the element: ";
	for(int i = 0; i < 10; ++i){
		mystack.push(i);
		cout << mystack.top() << " ";
	}
	cout << endl;
	cout <<"expected(stack is full): ";
	mystack.push(10);
	cout << "pop the element: ";
	for(int i = 0; i < 10; ++i){
		cout << mystack.top() << " ";
		mystack.pop();
	}
	cout << endl;
	cout <<"expected(stack is empty): ";
	mystack.pop();
	
	//Test setOfStacks
	cout << endl;
	cout << "Test setOfStacks" << endl;
	setOfStacks mystks;
	cout << "push the element: ";
	for(int i = 0; i < STACK_SIZE*STACK_NUM; ++i){
		mystks.push(i);
		cout << mystks.top() << " ";
	}
	cout << endl;
	cout <<"expected(stack is full): ";
	mystks.push(31);
	cout << "pop the element: ";
	for(int i = 0; i < STACK_SIZE*STACK_NUM; ++i){
		cout << mystks.top() << " ";
		mystks.pop();
	}
	cout << endl;
	cout <<"expected(stack is empty): ";
	mystks.pop();
	
	return 0;
}