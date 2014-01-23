/**
*How would you design a stack which, in addition to push 
*and pop, also has a function min 
*which returns the minimum element? 
*Push, pop and min should all operate in O(1) time.
*/

#include <iostream>

using namespace std;

const int MAX_INT = ~(1 << 31);	////2147483647

typedef struct node{
	int val;
	int min;
}node;

class stackWithMin{
public:
	stackWithMin(int size=1000){
		buf = new node[size];
		buf[0].min = MAX_INT; 
		cur = 0;
	}
	~stackWithMin(){
		delete[] buf;
	}

	void push(int val){
		buf[++cur].val = val;
		if(val < buf[cur-1].min)
			buf[cur].min = val;
		else
			buf[cur].min = buf[cur-1].min;
	}

	void pop(){
		--cur;
	}

	int top(){
		return buf[cur].val;
	}

	bool isEmpty(){
		return cur == 0;
	}
	int min(){
		return buf[cur].min;
	}

private:
	int cur;
	node *buf;
};

int main(){
	int n = 10;
	stackWithMin mystack;
	for(int i= 10; i < 20; i++){
		mystack.push(i);
		cout << mystack.top() << " ";
		cout << mystack.min() << endl;
	}
	mystack.push(4);
	mystack.push(6);
	mystack.push(7);
	mystack.push(8);
	for(int i= 10; i < 24; i++){
		mystack.push(i);
		cout << mystack.top() << " ";
		cout << mystack.min() << endl;
	}
}