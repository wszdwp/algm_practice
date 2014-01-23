#include <iostream>

using namespace std;


//create a loop linkedlist at the m position in a length of n;
//m < n
node* looplistinit(int a[], int n, int m) {
	node *head, *p, *q;
	for(int i = 0; i < n; i++) {
		node *nnode = new node();
		p->data = a[i];
		if(i == 0) {
			p = nd;
			head = p;
			continue;
		} 
		if(i == m) {
			q = nd;
		}
		p->next = nd;
		p = nd;
	}
	p->next = q;

	return head; 
}