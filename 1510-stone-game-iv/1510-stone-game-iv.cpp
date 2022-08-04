class Solution {
public:
    
    bool solve(int n,vector<int>&dp)
    {
        if(n<=0)return 1;
        
        if(dp[n]!=-1)return dp[n];
        bool ans=0;
        
        for(int z=1;z*z<=n;z++)
        {
            ans=ans||solve(n-z*z,dp);
        }
        return dp[n]=!ans;
    }
    
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,-1);
        return !solve(n,dp);
    }
};