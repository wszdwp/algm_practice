#include <iostream>
#include <map>
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

tNode* first_ancestor1(tNode* n1, tNode* n2){
	if(n1 == NULL || n2 == NULL)	return NULL;
	map<tNode*, bool> m;
	while(n1){
		m[n1] = true;
		n1 = n1->parent;
	}
	while(n2 && !m[n2]){
		n2 = n2->parent;  
	}
	return n2;
}

bool father(tNode* n1, tNode* n2){
	if(n1 == NULL || n2 == NULL)	return false;
	if(n1 == n2)	return true;
	else	return	father(n1->lchild, n2) || father(n1->rchild, n2);
}

tNode* first_ancestor2(tNode* n1, tNode* n2){
	if(n1 == NULL || n2 == NULL)	return NULL;
	while(n1){
		if(father(n1, n2))	return n1;
		n1 = n1->parent;
	}
	return NULL;
}

void first_ancestor3(tNode* root, tNode* n1, tNode* n2, tNode* &ans){
	if(root == NULL || n1 == NULL || n2 == NULL)	return;
	if(root && father(root, n1) && father(root, n2)){
		ans = root;
		first_ancestor3(root->lchild, n1, n2, ans);
		first_ancestor3(root->rchild, n1, n2, ans);
	}

}

tNode* search(tNode* root, int x){
    if(root == NULL) return NULL;
    else if(x == root->data) return root;
    else if(x <= root->data) search(root->lchild, x);
    else search(root->rchild, x);
}

int main(){
    int a[] = {
        1, 2, 3, 4, 5, 6, 7, 8
    };
    init();
    tNode *root = NULL;
    create_minimal_tree(root, NULL, a, 0, 7);
    printIn(root);
	cout << endl;

	tNode* ans = NULL;
    //tNode *node1 = search(root, 3);
    //tNode *node2 = search(root, 5);
    //tNode *node1 = search(root, 5);
	//tNode *node2 = search(root, 7);
	tNode *node1 = search(root, 3);
	tNode *node2 = search(root, 7);
    tNode *ancestor1stbyway1 = first_ancestor1(node1, node2);
    cout << "(Way1)ancestor of " << node1->data << " and " << node2->data << " is " << ancestor1stbyway1->data << endl;
    tNode *ancestor1stbyway2 = first_ancestor2(node1, node2);
    cout << "(Way2)ancestor of " << node1->data << " and " << node2->data << " is " << ancestor1stbyway2->data << endl;
    first_ancestor3(root, node1, node2, ans);
    cout << "(Way3)ancestor of " << node1->data << " and " << node2->data << " is " << ans->data << endl;
}