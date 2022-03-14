class MinStack {
    
    stack<long int> s;
    long int min_element;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        
        if(s.empty()){
            s.push(val);
            min_element = val;
        }
        else if(val>=min_element){
            s.push(val);
        }
        else{
            s.push(1ll*2*val-min_element);
            min_element = val;
        }
    }
    
    void pop() {
        
        if(s.empty())
            return;
        if(min_element<=s.top())
            s.pop();
        else{
            min_element = 1ll*2*min_element - s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.empty())
            return -1;
        if(min_element<=s.top())
            return s.top();
        else 
            return min_element;
    }
    
    int getMin() {
        
        if(s.empty())
            return -1;
        return min_element;
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