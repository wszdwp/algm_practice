#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};
Node *p, node[maxn];
int cnt;

void init(){
    p = NULL;
    memset(node, '\0', sizeof(node));
    cnt = 0;
}
void create_minimal_tree(Node* &root, Node *parent, int a[], int start, int end){
    if(start <= end){
        int mid = (start + end)>>1;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        root = &node[cnt++];
        create_minimal_tree(root->lchild, root, a, start, mid-1);
        create_minimal_tree(root->rchild, root, a, mid+1, end);
    }
}
Node* minimal(Node* no){    
    if(no == NULL) return NULL;
    while(no->lchild)
        no = no->lchild;
    return no;
}
Node* successor(Node* no){
    if(no == NULL) return NULL;
    if(no->rchild) return minimal(no->rchild);
    Node *y = no->parent;
    while(y && y->rchild==no){
        no = y;
        y = y->parent;
    }
    return y;
}

int main(){
    int a[] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    init();
    Node *root = NULL;
    create_minimal_tree(root, NULL, a, 0, 9);
    cout<<"the root is "<<root->key<<endl;
    cout<<"the successor of root is: "<<(successor(root))->key<<endl;
    return 0;
}