class StockSpanner {
public:
    
    stack<int> s;
    vector<int> v;
    
    StockSpanner() {
    }
    
    int next(int p) {
        int ans=0;
        v.push_back(p);
        while(!s.empty()&&v[s.top()]<=p) s.pop();
        if(s.empty()) ans= v.size();
        else  ans=v.size()-s.top()-1;
        s.push(v.size()-1);
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */