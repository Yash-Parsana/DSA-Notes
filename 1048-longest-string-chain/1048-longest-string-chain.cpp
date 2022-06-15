class Solution {
public:
    
    static bool cmp(string s1,string s2)
    {
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& v) {
        
        unordered_map<string ,int> dp;
        
        sort(v.begin(),v.end(),cmp);
        int ans=1;
        for(int z=0;z<v.size();z++)
        {
            dp[v[z]]=1;
            
            for(int y=0;y<v[z].size();y++)
            {
                string str=v[z].substr(0,y)+v[z].substr(y+1);
                
                if(dp.find(str)!=dp.end())
                {
                    dp[v[z]]=max(dp[v[z]],dp[str]+1);
                }
            }
            ans=max(ans,dp[v[z]]);
            
        }
        return ans;
        
        
        
    }
};