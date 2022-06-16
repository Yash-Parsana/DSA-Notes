class MyStack {
public:
    
    queue<int> q1,q2;
    
    MyStack() {
        q1=queue<int>();     
        q2=queue<int>();   
   
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int temp=0;
        while(!q1.empty())
        {
            if(q1.size()==1)
            {
                temp=q1.front();
            }
            else q2.push(q1.front());
            
            q1.pop();
        }

        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return temp;
    }
    
    int top() {
        int temp=0;
        while(!q1.empty())
        {
            q2.push(q1.front());

            if(q1.size()==1) temp=q1.front();
            
            q1.pop();
        }

        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return temp;
        
    }
    
    bool empty() {
        if(q1.empty()) return 1;
        return 0;
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