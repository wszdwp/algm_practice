#include <iostream>

using namespace std;

typedef struct node
{
	/* data */
	int data;
	node *next;
}node;

node* init(int a[], int n) {
	node *head=NULL, *p;

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

node* add(node* head1, node* head2) {
	if(head1 == NULL) 
		return head2;
	if(head2 == NULL)
		return head1;

	int carry = 0;
	node *head=NULL, *p;
	int count = 0, count2 = 0;
	while( head1!= NULL && head2!=NULL){
		
		int a = head1->data;
		int b = head2->data;
		int s = (a + b + carry) % 10;
		carry = (a + b + carry) / 10;

		p= new node();
		p->data = s;
	
		if(head == NULL) {
			head = p;
			count++;		
		} else {	
			p->next = head;
			head = p;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	
	while( head1 != NULL) {
		int a = head1->data;
		int s = (a + carry) % 10;
		carry = (a + carry) / 10;
		p= new node();
		p->data = s;
		p->next = head;
		head = p;
		head1 = head1->next;
	}
	while( head2 != NULL) {
		int a = head2->data;
		int s = (a + carry) % 10;
		carry = (a + carry) / 10;
		p= new node();
		p->data = s;
		p->next = head;
		head = p;
		head2 = head2->next;
	}
	

	return head;
}




int main()
{
	int n = 4, m = 3;
	int a[] = {3, 1, 7, 5};
	int b[] = {2, 9, 2};

	node *hd1 = init(a, n);
	node *hd2 = init(b, m);

	print(hd1);
	print(hd2);
	node* result = add(hd1, hd2);
	print(result);



}