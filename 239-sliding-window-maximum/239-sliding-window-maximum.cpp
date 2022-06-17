class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int &k) {
        
        deque<int> dq;
        
        vector<int> ans;
        for(int z=0;z<v.size();z++)
        {
            if(!dq.empty()&&dq.front()==z-k) dq.pop_front();
            
            while(!dq.empty()&&v[dq.back()]<v[z]) dq.pop_back();
            
            dq.push_back(z);
            
            if(z>=k-1) ans.push_back(v[dq.front()]);
            
        }
            
        return ans;
        
    }
};