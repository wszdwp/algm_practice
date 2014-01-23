#include <iostream>

using namespace std;

typedef struct treeNode
{
	int data;
	treeNode *lchild;
	treeNode *rchild;
}treeNode;

int maxDepth(treeNode *root){
	int ldepth = 0, rdepth = 0;
	if(!root)	return 0;
	if(root->lchild)
		ldepth = maxDepth(root->lchild);
	if(root->rchild)
		rdepth = maxDepth(root->rchild);
	return	((ldepth > rdepth) ? ldepth+1 : rdepth+1);
}

int minDepth(treeNode *root){
	int ldepth = 0, rdepth = 0;
	if(!root)	return 0;
	if(root->lchild)
		ldepth = minDepth(root->lchild);
	if(root->rchild)
		rdepth = minDepth(root->rchild);
	return	((ldepth < rdepth) ? ldepth+1 : rdepth+1);
}

bool isBalance(treeNode *root) {
	return (maxDepth(root) -minDepth(root) <= 1) ? true : false;
}



int main()
{
	treeNode node1 = {1, NULL, NULL};
	treeNode node2 = {2, &node1, NULL};
	//treeNode node2 = {2, NULL, NULL};
	treeNode node5 = {5, NULL, NULL};
	treeNode node9 = {9, NULL, NULL};
	treeNode node4 = {0, &node2, &node5};
	treeNode node8 = {8, &node4, &node9};
	
	treeNode *root = &node8;

	cout << ((isBalance(root)) ? "balance":"not balance" )<< endl;

	return 0;
}