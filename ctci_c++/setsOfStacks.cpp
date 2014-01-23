class SetOfStacks{//without popAt()
private:
    stack *st;
    int cur;
    int capacity;

public:
    SetOfStacks(int capa=STACK_NUM){
        st = new stack[capa];
        cur = 0;
        capacity = capa;
    }
    ~SetOfStacks(){
        delete[] st;
    }
    void push(int val){
        if(st[cur].full()) ++cur;
        st[cur].push(val);
    }
    void pop(){
        if(st[cur].empty()) --cur;
        st[cur].pop();
    }
    int top(){
        if(st[cur].empty()) --cur;
        return st[cur].top();
    }
    bool empty(){
        if(cur==0) return st[0].empty();
        else return false;
    }
    bool full(){
        if(cur==capacity-1) return st[cur].full();
        else return false;
    }    
};

//set of stacks with popAt()
class SetOfStacks1{
private:
    stack *st;
    int cur;
    int capacity;

public:
    SetOfStacks1(int capa=STACK_NUM){
        st = new stack[capa];
        cur = 0;
        capacity = capa;
    }
    ~SetOfStacks1(){
        delete[] st;
    }
    void push(int val){
        if(st[cur].full()) ++cur;
        st[cur].push(val);
    }
    void pop(){
        while(st[cur].empty()) --cur;
        st[cur].pop();
    }
    void popAt(int idx){
        while(st[idx].empty()) --idx;
        st[idx].pop();
    }
    int top(){
        while(st[cur].empty()) --cur;
        return st[cur].top();
    }
    bool empty(){
        while(cur!=-1 && st[cur].empty()) --cur;
        if(cur==-1) return true;
        else return false;
    }
    bool full(){
        if(cur==capacity-1) return st[cur].full();
        else return false;        
    }
};