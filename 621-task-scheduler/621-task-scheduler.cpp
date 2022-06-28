class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto x:tasks)
            mp[x]++;
        
        priority_queue<int> pq;
        for(auto x:mp)
            pq.push(x.second);
        
        int ans=0;
        while(!pq.empty())
        {
            vector<int> t;
            for(int i=0;i<=n && !pq.empty();i++)
            {
                t.push_back(pq.top());
                pq.pop();
            }
            for(auto x:t)
            {
                if(x-1>0)
                    pq.push(x-1);
            }
            
            ans += pq.empty()? t.size(): n+1;
        }
        return ans;
    }
};