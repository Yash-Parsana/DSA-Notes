class Solution {
public:
    static bool cmp(string s1,string s2)
    {
        return s1.size()<s2.size();
        
    }
    int longestStrChain(vector<string>& wd) {
        map<string,int>dp;
        
        sort(wd.begin(),wd.end(),cmp);
        int ans=0;
        for(string s:wd)
        {
            dp[s]=1;
            for(int i=0;i<s.size();i++)
            {
                string str=s.substr(0,i)+s.substr(i+1);
                if(dp.find(str)!=dp.end()&&dp[s]<dp[str]+1)
                    dp[s]=dp[str]+1;
            }
            ans=max(ans,dp[s]);
        }
        return ans;
    }
};