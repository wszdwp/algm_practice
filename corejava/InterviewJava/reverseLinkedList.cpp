#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef struct node{
	int data;
	node* next;
	node(int adata){
		data = adata;
		next = NULL;
	}
}node;


node* init(int a[]){
	node* head = new node(a[0]);
	node* cur = head;
	for(int i = 1; i <= sizeof(a); i++){
		node* nnode = new node(a[i]);
		cur->next = nnode;
		cur = nnode;
	}
	return head;
}



node* reverseLinkedList(node* head){
	if(head == NULL || head->next == NULL)	return head;
	node* p = head;
	node* q = head->next;
	node* r;
	head->next = NULL;
	while(q){
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head = p;
	return head;
}

void printLlist(node* head){
	if( head == NULL)	return;
	while(head){
		cout << head->data;
		head = head->next;
		if(head)
			cout << "-->";
	}
	cout << endl;
}

void testBench(int testTime){
	if(testTime <= 0)	return;
	while(testTime){
		srand(time(NULL)+rand()%100);	
		int a[5];
		for(int i = 0; i < 5; i++){
			k: a[i] = rand() % 10 + 1;		//1 - 10
			for(int j = i-1; j >= 0; j--){
				if(a[i] == a[j])
					goto k;
			}
		}	

		node* test = init(a);
		cout << "Before reversed: ";
		printLlist(test);
		cout << "After reversed: ";
		node* revtest = reverseLinkedList(test);
		printLlist(revtest);
		testTime--;
	}
	
}

int main()
{
	int testTime = 5;
	testBench(testTime);

}