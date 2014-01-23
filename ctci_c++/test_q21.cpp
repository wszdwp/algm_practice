node* init(int a[], int n) {
    node *head, *p;

    for(int i = 0; i < n; i++) {
        node *nnode = new node();
        nnode -> data = a[i];
        if( i == 0) {
            head = nnode;
            p = nnode;
            continue;
        }
        p->next = nnode;
        p = nnode;  
    }
    cout << p->next;
}








node* init(int a[], int n){
    node *head, *p;
    for(int i=0; i < n; ++i){
        node *nd = new node();
        nd->data = a[i];
        if(i==0){
            head = p = nd;
            continue;
        }
        p->next = nd;
        p = nd;
    }
    return head;
}