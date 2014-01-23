#include <iostream>
#include <cmath>
using namespace std;

const int NODE_NUM = 10; 

typedef struct tNode
{
	/* data */
	int data;
	tNode *lchild;
	tNode *rchild;
}tNode;

tNode* init(int a[], int begin, int end){
	if(end < begin)
		return NULL;
	tNode *root = new tNode; 
	int mid = (begin + end) / 2;
	//cout << mid << " ";
	root->data = a[mid];
	root->lchild = init(a, begin, mid-1);
	root->rchild = init(a, mid+1, end);
	return root;
}

void printPre(tNode *root){
	if(root == NULL) return;
	cout << root->data << " ";
	printPre(root->lchild);
	printPre(root->rchild);
}

void printIn(tNode *root){
	if(root == NULL) return;
	printIn(root->lchild);
	cout << root->data << " ";
	printIn(root->rchild);
}

void printPos(tNode *root){
	if(root == NULL) return;
	printPos(root->lchild);
	printPos(root->rchild);
	cout << root->data << " ";
}
int height(tNode *root){
	if(root == NULL) return 0;
	return max(height(root->lchild), height(root->rchild)) + 1;
}

int main()
{
	int a[NODE_NUM];
	for(int i = 0; i < NODE_NUM; i++){
		a[i] = i;
	} 
	int begin = 0, end = NODE_NUM - 1;
	tNode *root = init(a, begin, end);
	
	cout <<"Pre-order DFS:" << endl;
	printPre(root);
	cout << endl;
	cout <<"In-order DFS:" << endl;
	printIn(root);
	cout << endl;
	cout <<"Post-ordet DFS " << endl;
	printPos(root);
	cout << endl;
	cout <<"Expected height (" << (NODE_NUM - 1) / 2 << "): " << height(root)<< endl;
}