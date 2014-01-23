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

bool remove(node *p) {
	if(p == NULL || p->next == NULL)
		return false;
	
	node *nd = p->next;
	p->data = nd->data;
	p->next = nd->next;
	delete nd;

	return true;
}

int main() 
{
	int n = 10;
    int a[] = {
        9, 2, 1, 3, 5, 6, 2, 6, 3, 1 
    };
    node *head = init(a, n);

    int cc = 10;
    node *c = head;
    for(int i=1; i<cc; ++i) 
    	c = c->next;
    print(head);

    if(remove(c))
        print(head);
    else
        cout<<"failure"<<endl;

    return 0;

}