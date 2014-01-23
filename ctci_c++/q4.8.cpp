#include <iostream>
#include <vector>

using namespace std;

typedef struct tNode
{
	/* data */
	int data;
	tNode *lchild, *rchild, *parent; 
}tNode;
//treeNode has prarent pointer
void print(tNode* node, int level){
	vector<int> v;
	for(int i = 0; i < level; ++i){
		v.push_back(node->data);
		node = node->parent;
	}
	while(!v.empty()){
		cout << v.back() << " ";
		v.pop_back();
	}
	cout << endl;
}

void find_sum(tNode* node, int sum){
	if(node == NULL)	return;
	tNode* no = node;
	int tmp = 0;
	for(int i = 1; no != NULL; ++i){
		tmp += no->data;
		if(tmp == sum)
			print(node, i);
		no = no->parent;
	}
	find_sum(node->lchild, sum);
	find_sum(node->rchild, sum);
}

void print2(vector<int> v, int level){
	for(int i = level; i < v.size(); ++i)
		cout << v.at(i) << " ";
	cout << endl;
}

void find_sum2(tNode* node, int sum, vector<int> v, int level){
	if(node == NULL)	return;
	v.push_back(node->data);
	int tmp = 0;
	for(int i = level; i > -1; --i){
		tmp += v.at(i);
		if(tmp == sum)
			print2(v, i);
	}
	vector<int> v1(v), v2(v);
	find_sum2(node->lchild, sum, v1, level+1);
	find_sum2(node->rchild, sum, v2, level+1);
}



int main(){

}