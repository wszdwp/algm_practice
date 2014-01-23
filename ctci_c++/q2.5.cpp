#include <iostream>
#include <map>
using namespace std;

typedef struct node
{
	/* data */
	int data;
	node *next;
}node;

node* init(int a[], int n, int m){
    node *head, *p, *q;
    for(int i=0; i<n; ++i){
        node *nd = new node();
        nd->data = a[i];
        if(i==m) q = nd;
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    p->next = q;
    return head;
}

void print(node *head) {
	while(head) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

node* findLooppHead(node *head) {
	if (head == NULL)
		return NULL;
	node *fast = head, *slow = head;
	while(fast != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if( fast == slow)
			break;
	}

	slow = head;
	while(fast != NULL) {
		fast = fast->next;
		slow = slow->next;
		if( fast == slow)
			break;
	}

	return fast;
}

int main()
{
	int n = 10, m = 8;// m<n
    int a[] = {
        3, 2, 1, 3, 5, 6, 2, 6, 3, 1 
    };
    node *head = init(a, n, m);
    //node *p = loopstart(head);
    node *p = findLooppHead(head);
    if(p)
        cout<<p->data<<endl;
    return 0;
}