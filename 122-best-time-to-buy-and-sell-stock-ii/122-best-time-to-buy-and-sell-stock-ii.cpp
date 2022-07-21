class Solution {
public:
    
    int solve(vector<int> &p,int i,bool b,int pre,vector<vector<int>> &dp){
        
        if(i>=p.size())return 0;
        
        if(dp[i][b]!=-1)return dp[i][b];
        
        if(b)
        {            
            return dp[i][b]=max(solve(p,i+1,0,0,dp)+p[i],solve(p,i+1,1,pre,dp));
        }
        return dp[i][b]=max(solve(p,i+1,1,p[i],dp)-p[i],solve(p,i+1,0,0,dp));
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,0,0,dp);
        
    }
};