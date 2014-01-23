#include <iostream>
#include <cstring>
using namespace std;


typedef struct node
{
	/* data */
	int data;
	node *next;
}node;


node* init(int a[], int n) {
	node *head, *p;
	for(int i = 0; i < n; i++){
		node *nd = new node();
		nd -> data = a[i];
		nd -> next = NULL;
		if(i == 0) {
			p = nd;
			head = p;
			continue;
		}

		p -> next = nd;
		p = nd;
	}
	cout << p->next << endl;
	return head;
}

void removedup(node *head) {
	if(head == NULL)
		return;

	node *p, *q, *c = head;
	while(c) {
		p = c;
		q = p -> next;
		while(q) {	
			if( (c -> data) == (q -> data) ) {
				node* tmp = q;
				p -> next = q -> next;
				q = p -> next;
				//q = q -> next;
				//p -> next = q;
				delete tmp;
			} else {
				p = q;
				q = q -> next;
			}
		}
		c = c -> next;
	}
}

void print(node *head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
	int n = 10;
    int a[] = {
        3, 2, 1, 3, 5, 6, 2, 6, 3, 1 
    };

    node *head = init(a, n);
    removedup(head);
    //removedulicate1(head);
    print(head);
    return 0;

}