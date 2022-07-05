class Solution {
public:
    
    int solve(vector<int> &coins,vector<vector<int>>&dp,int i,int v,int &n)
    {
        if(i>=n)return 1e5;
        if(v==0)return 0;
        
        if(dp[i][v]!=-1)return dp[i][v];
        
        int ans=1e5;
        if(v>=coins[i])
            ans=solve(coins,dp,i,v-coins[i],n)+1;
        
        return dp[i][v]= min(ans,solve(coins,dp,i+1,v,n));
    
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        sort(coins.begin(),coins.end(),greater<int>());
        
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        int ans=solve(coins,dp,0,amount,n);
        if(ans==1e5)return -1;
        return ans;
        
    }
};