#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int NODE_NUM = 10; 

typedef struct tNode
{
	/* data */
	int data;
	tNode *lchild;
	tNode *rchild;
}tNode;


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

vector<list<tNode*> > createLevelLinkedList(tNode *root){
	vector<list<tNode*> > res;
	int level = 0;
	list<tNode*> li;
	li.push_back(root);
	res.push_back(li);
	while(!res[level].empty()){
		list<tNode*> l;
		list<tNode*>::iterator it;
		for(it = res[level].begin(); it!=res[level].end(); ++it){
			tNode *n = *it;
			if(n->lchild) l.push_back(n->lchild);
			if(n->rchild) l.push_back(n->rchild);
		}
		++level;
		res.push_back(l);
	}
	return res;

}

//print tree 
void printIn(tNode *root){
	if(root == NULL) return;
	printIn(root->lchild);
	cout << root->data << " ";
	printIn(root->rchild);
}

//print level tree
void printLvlTree(vector<list<tNode*> > res){
	vector<list<tNode*> >::iterator vit;
	for(vit = res.begin(); vit != res.end(); ++vit){
		list<tNode*> li = *vit;
		list<tNode*>::iterator lit;
		for(lit = li.begin(); lit != li.end(); ++lit){
			tNode *n = *lit;
			cout << n->data << " ";
		}
		cout << endl;
	}
}

int main(){
	int a[NODE_NUM];
	for(int i = 0; i < NODE_NUM; i++){
		a[i] = i+1;
	} 
	int begin = 0, end = NODE_NUM - 1;
	tNode *root = createTree(a, begin, end);
	cout <<"In-order DFS:" << endl;
	printIn(root);
	cout << endl;
	cout << "createLevelLinkedList" << endl;
	vector<list<tNode*> > res = createLevelLinkedList(root);
	printLvlTree(res);

}