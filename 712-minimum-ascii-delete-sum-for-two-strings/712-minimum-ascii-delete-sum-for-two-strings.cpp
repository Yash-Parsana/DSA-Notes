class Solution {
public:
    int rest0fString(string &s,int i)
    {
        int ans=0;
        for(int j=i;j<s.size();j++)ans+=s[j];
        
        return ans;
    }
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp)
    {
        if(i==s1.size()&&j==s2.size())return 0;
        
        if(i>=s1.size())
        {
            return rest0fString(s2,j);
        }
        if(j>=s2.size())
            return rest0fString(s1,i);
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s1[i]==s2[j])
            return dp[i][j]=solve(s1,s2,i+1,j+1,dp);
        
        return dp[i][j]=min(solve(s1,s2,i+1,j,dp)+s1[i],solve(s1,s2,i,j+1,dp)+s2[j]);
        
    }
    
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
        
        return solve(s1,s2,0,0,dp);
    }
};