#include <iostream>

using namespace std;

typedef struct node
{
	/* data */
	int data;
	node *next;
}node;

node* init(int a[], int n) {
	node *head, *p;

	for(int i = 0; i < n; i++) {
		node *nnode = new node();
		nnode->data = a[i];
		if( i == 0) {
			p = nnode;
			head = nnode;
			continue; 
		}
		p->next = nnode;
		p = nnode;
	}
	return head;
}

void print(node *head) {
	while(head) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

node* findNback(node *head, int n) {
	if(n < 1 || head == NULL){
		cout << "error" << endl;
		return NULL;
	}
	
	node *hd = head, *tl = head;
	
	while(n>0 && tl) {
		tl = tl->next;
		n--;
	}

	if(n > 0) {
		cout << "n is greater than the length of list." << endl;
		return NULL;
	}
	
	while(tl) {
		tl = tl->next;
		hd = hd->next;
	}

	return hd;
}


int main()
{
	int n = 10;
	int a[] = { 4, 3, 5, 3, 5, 6, 8, 9, 10, 11};
	node *head = init(a, n);
	print(head);

	node *n8 = findNback(head, 8);
	node *n11 = findNback(head, 11);
	node *n1 = findNback(head, 1);
	node *n4 = findNback(head, 4);
	node *n3 = findNback(head, 3);
	node *n5 = findNback(head, 5);
	if(n8)
		cout << "expected(5) " << n8->data << endl;
	if(n11)
		cout << "expected(length..) " << n11->data << endl;
	if(n1)
		cout << "expected(11) " << n1->data << endl;
	if(n4)
		cout << "expected(8) " << n4->data << endl;
	if(n3)
		cout << "expected(6) " << n3->data << endl;
	if(n5)
		cout << "expected(6) " << n5->data << endl;
}