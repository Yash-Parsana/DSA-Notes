class Solution {
public:
    
    int solve(int i,vector<int>&p,int k,bool b,vector<vector<vector<int>>> &dp)
    {
        if(k<0)return 0;
        if(i>=p.size())return 0;  
        if(dp[i][k][b]!=-1)return dp[i][k][b];
        
        if(b)
        {
            return dp[i][k][b]=max(solve(i+1,p,k,0,dp)+p[i],solve(i+1,p,k,b,dp));
        }
        return dp[i][k][b]=max(solve(i+1,p,k-1,1,dp)-p[i],solve(i+1,p,k,0,dp));
    }
    
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(0,prices,k,0,dp);
    }
};