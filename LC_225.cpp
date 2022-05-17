class MyStack {
public:
    
    int size = 0;
    queue<int> que;
    
    MyStack() {
    }
    
    void push(int x) {
        
        que.push(x);
        size++;
        
        int front;
        for (int i = 1; i < size; i++){
            front = que.front();
            que.pop();
            que.push(front);
            // cout << x <<  " " << size << endl;
        }
        
        
    }
    
    int pop() {
        int val = que.front();
        que.pop();
        size--;
        return val;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */