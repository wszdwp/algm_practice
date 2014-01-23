#include <iostream>
#include <cstring>
#include <vector>
#include <list>
using namespace std;

const int maxn = 100;
typedef struct tNode{
    int data;
    tNode *lchild, *rchild, *parent;
}tNode;

tNode node[maxn];
int cnt;

void init(){
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


bool match(tNode* r1, tNode* r2){
	if(r1 == NULL && r2 == NULL)	return true;
	else if(r1 == NULL || r2 == NULL)	return false;
	else if(r1->data != r2->data)	return false;
	else	return match(r1->lchild, r2->lchild) && match(r1->rchild, r2->rchild);
}

bool subtree(tNode* r1, tNode* r2){
	if(r1 == NULL)	return false;
	else if(r1->data == r2->data){
		if(match(r1, r2))	
			return true;
	}
	else return subtree(r1->lchild, r2) || subtree(r1->rchild, r2);
}

bool contain_tree(tNode* r1, tNode* r2){
	if(r2 == NULL)	return true;
	else return subtree(r1, r2);
}

vector<list<tNode*> > find_level_linklists(tNode *root){
    vector<list<tNode*> > res;
    int level = 0;
    list<tNode*> li;
    li.push_back(root);
    res.push_back(li);
    while(!res[level].empty()){
        list<tNode*> l;
        list<tNode*>::iterator it;
        for(it=res[level].begin(); it!=res[level].end(); ++it){
            tNode *n = *it;
            if(n->lchild) l.push_back(n->lchild);
            if(n->rchild) l.push_back(n->rchild);
        }
        ++level;
        res.push_back(l);
    }
    return res;
}

void print(vector<list<tNode*> > res){
    vector<list<tNode*> >::iterator vit;
    for(vit=res.begin(); vit!=res.end(); ++vit){
        list<tNode*> li = *vit;
        list<tNode*>::iterator lit;
        for(lit=li.begin(); lit!=li.end(); ++lit){
            tNode *n = *lit;
            cout<<n->data<<"\t";
        }
        cout<<endl;
    }
}

int main(){
	init();
    int a1[] = {
        0, 1, 2, 3, 4, 5, 6
    };
    int a2[] = {
        0, 1, 2
    };
    tNode *r1 = NULL, *r2 = NULL;
    create_minimal_tree(r1, NULL, a1, 0, 6);
    create_minimal_tree(r2, NULL, a2, 0, 2);
    /*
    vector<list<tNode*> > res1 = find_level_linklists(r1);
    vector<list<tNode*> > res2 = find_level_linklists(r2);
	cout << "Level tree1 is: " << endl;
	print(res1);
	cout << "Level tree2 is: " << endl;
	print(res2);
	*/
    if(contain_tree(r1, r2))
        cout<<"tree r1 contains r2"<<endl;
    else cout<<"tree r1 does not contains r2"<<endl;
    return 0;
}