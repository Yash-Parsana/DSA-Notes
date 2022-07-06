class Solution {
public:
    
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=s1.size()||j>=s2.size())return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int take=0;
            if(s1[i]==s2[j])take=solve(s1,s2,i+1,j+1,dp)+1;
        int dontTake=max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
        
        return dp[i][j]=max(take,dontTake);
        
    }
    
    int longestCommonSubsequence(string s1, string s2) {
        
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
        return solve(s1,s2,0,0,dp);
    }
};