class Solution {
public:
    
    int solve(int i,vector<int>&p,bool b,vector<vector<int>>&dp)
    {
        if(i>=p.size())return 0;
        if(dp[i][b]!=-1)return dp[i][b];
        if(b)
        {
            return dp[i][b]=max(solve(i+2,p,0,dp)+p[i],solve(i+1,p,b,dp));
        }
        return dp[i][b]=max(solve(i+1,p,1,dp)-p[i],solve(i+1,p,0,dp));
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,prices,0,dp);
    }
};