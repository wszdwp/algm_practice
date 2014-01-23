#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 10;
typedef struct tNode
{
	int data;
	tNode *lchild;
	tNode *rchild;
	tNode *parent;
}tNode;
tNode *p, node[maxn];
int cnt;

tNode* init(){
	p = NULL;
    memset(node, '\0', sizeof(node));
    cnt = 0;
}

void create_minimal_tree(tNode* &root, tNode *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        node[cnt].data = a[mid];
        node[cnt].parent = parent;
        root = &node[cnt++];
        create_minimal_tree(root->lchild, root, a, start, mid-1);
        create_minimal_tree(root->rchild, root, a, mid+1, end);
    }
}

void printIn(tNode *root){
	if(root == NULL) return;
	printIn(root->lchild);
	cout << root->data << " ";
	printIn(root->rchild);
}

tNode* successor(tNode *node){
	if(node == NULL) return NULL;
	if(node->rchild){
		node = node->rchild;
		//cout << node->data << endl;
		while(node->lchild){
			node = node->lchild;
			//cout << node->data << endl;
		}
		return node;
	}
	tNode *y = node->parent;
	while( y && y->rchild == node){
		node = y;
		y = y->parent;
	}
	return y;
}
/*
tNode* minimal(tNode* no){    
    if(no == NULL) return NULL;
    while(no->lchild)
        no = no->lchild;
    return no;
}
tNode* successor(tNode* no){
    if(no == NULL) return NULL;
    if(no->rchild) return minimal(no->rchild);
    tNode *y = no->parent;
    while(y && y->rchild==no){
        no = y;
        y = y->parent;
    }
    return y;
}
*/
int main(){
    int a[] = {
        1, 2, 3, 4, 5, 6, 7, 8
    };
    init();
    tNode *root = NULL;
    create_minimal_tree(root, NULL, a, 0, 7);
    printIn(root);

    cout << endl;
    //cout << root->rchild->rchild->rchild->data;
    tNode *test = root->lchild->lchild;
    cout << test->data << endl;
    tNode *succ = successor(test);
    cout << "successor of " << test->data << " is " << succ->data << endl;
}