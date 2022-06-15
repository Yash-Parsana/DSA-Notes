
struct cmp{
  
    bool operator()(pair<int,int> p1,pair<int,int> p2)
    {
        return p1.second>p2.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        
        for(int i:nums)
        {
            m[i]++;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> h;
        
        for(auto i:m)
        {
            h.push(i);
            if(h.size()>k)h.pop();
        }
        
        vector<int> ans;
        
        while(!h.empty())
        {
            ans.push_back(h.top().first);
            h.pop();
        }
        return ans;
        
    }
};