class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> f;
        map<int,int> m;
        
        for(char c:s)
        {
            f[c]++;
        }
        
        for(auto i:f)
        {
            m[i.second]++;
        }
        int ans=0;
        
        for(auto i=m.rbegin();i!=m.rend();i++)
        {
            if(i->second>1)
            {
                ans+=(i->second-1);
                
                if(i->first-1>0)
                    m[i->first-1]+=i->second-1;
                
            }
        }
        return ans;
    }
};