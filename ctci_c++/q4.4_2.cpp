#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

const int NODE_NUM = 6; 

typedef struct tNode
{
	/* data */
	int data;
	tNode *lchild;
	tNode *rchild;
}tNode;

typedef struct Node
{
	int data;
	Node *next;
}Node;

tNode* createTree(int a[], int begin, int end){
	if(end < begin)
		return NULL;
	tNode *root = new tNode; 
	int mid = (begin + end) / 2;
	//cout << mid << " ";
	root->data = a[mid];
	root->lchild = createTree(a, begin, mid-1);
	root->rchild = createTree(a, mid+1, end);
	return root;
}

Node* createLinkedList(tNode *root){
	queue<tNode*> q;
	tNode *t = new tNode();
	Node *head = new Node();
	Node *cur = head;
	head->data = root->data;
	q.push(root);
	while(!q.empty()){
		Node *nnode = new Node();
		t = q.front();	
		if(cur == head){
			continue;
		}else{
			nnode->data = t->data;
			cur->next = nnode;
			cur = nnode;
		}
		q.pop();
		if(t->lchild != NULL)
			q.push(t->lchild);
		if(t->rchild != NULL)
			q.push(t->rchild);
	}
	return head;
}

void printList(Node *head){
	if(!head) return;
	int count = 0;
	while(head){
		cout << head->data << " ";
		head = head->next;
		count++;
	}
	cout << endl;
	cout << "Length of the linkedlist = " << count << endl;
}

void printIn(tNode *root){
	if(root == NULL) return;
	printIn(root->lchild);
	cout << root->data << " ";
	printIn(root->rchild);
}

int main()
{
	int a[NODE_NUM];
	for(int i = 0; i < NODE_NUM; i++){
		a[i] = i+1;
	} 
	int begin = 0, end = NODE_NUM - 1;
	tNode *root = createTree(a, begin, end);
	cout <<"In-order DFS:" << endl;
	printIn(root);
	cout << endl;
	cout << "createLinkedList" << endl;

	Node *head = createLinkedList(root);
	printList(head);
}