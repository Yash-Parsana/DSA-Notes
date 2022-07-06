class Solution {
public:
    
    int solve(vector<int>&coins,vector<vector<int>>&dp,int i,int &n,int target)
    {
        if(i>=n)return 0;
        if(target==0)return 1;
        
        if(dp[i][target]!=-1)return dp[i][target];
        
        int take=0;
        if(coins[i]<=target)
            take=solve(coins,dp,i,n,target-coins[i]);
        
        return dp[i][target]=take+solve(coins,dp,i+1,n,target);
    }
    
    
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        return solve(coins,dp,0,n,amount);
        
    }
};