class MinStack {
public:
    
    stack<long> s;
    int mi=INT_MAX;
    
    
    MinStack() {
        s=stack<long>();
        mi=INT_MAX;
    }
    
    void push(int val) {
        
        if(s.empty())
        {
            s.push(val);
            mi=val;
        }
        else
        {
            if(val>mi)
            {
                s.push(val);
            }
            else
            {
                s.push((long)2*val-(long)mi);
                mi=val;
            }
        }
        
    }
    
    void pop() {
        if(s.top()<mi)
        {
            mi=(long)2*mi-(long)s.top();
        }
        s.pop();
    }
    
    int top() {
        if(s.top()<mi)
        {
            return mi;
        }
        return s.top();
    }
    
    int getMin() {
        return mi;
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