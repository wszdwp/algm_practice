#include <iostream>
#include <stack>
#include <cstdlib>
#include <queue>
#include <time.h>

using namespace std;

//method 1
stack<int> ssort(stack<int> s){
	stack<int> t;
	while(!s.empty()){
		int data = s.top();
		s.pop();
		while(!t.empty() && t.top() < data){
			s.push(t.top());
			t.pop();
		}
		t.push(data);
	}
	return t;
}

//method 2
void qsort(stack<int> &s){
	priority_queue<int, vector<int>, greater<int> > q;
	
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
	while(!q.empty()){
		s.push(q.top());
		q.pop();
	}
}

int main() 
{
	srand((unsigned) time(0));
	stack<int> s;

	for(int i = 0; i < 10; ++i){
		s.push((rand()%100));
		cout << s.top() << " ";
	}
	cout << endl;
	//s = ssort(s);
	qsort(s);
	while(!s.empty()){
		cout << s.top()<<" ";
		s.pop();
	}
	return 0;
}