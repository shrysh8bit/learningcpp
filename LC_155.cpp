class MinStack {
public:
    
    stack<int> min_val;
    stack <int> nums;
    
    MinStack() {
        min_val.push(INT_MAX);
        
    }
    
    void push(int val) {
        nums.push(val);
        
        int minimum;
        if ( min_val.top() > val){
            minimum = val;
        }else{
            minimum = min_val.top();
        }
        
        min_val.push(minimum);
    }
    
    void pop() {
        nums.pop();
        min_val.pop();
        
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return min_val.top();
    }
    
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */