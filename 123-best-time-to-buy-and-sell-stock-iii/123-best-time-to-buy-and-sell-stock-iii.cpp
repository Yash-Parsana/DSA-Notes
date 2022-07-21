class Solution {
public:
    
    int solve(vector<int> &p,int i,int k,int b,vector<vector<vector<int>>>&dp)
    {
        if(i>=p.size())return 0;
        
        if(dp[i][k][b]!=-1)return dp[i][k][b];
        if(b)
        {
            int ans=solve(p,i+1,k,b,dp);
            if(k>0)
            {
                ans=max(ans,solve(p,i+1,k,0,dp)+p[i]);
            }
            else
                ans=max(ans,p[i]);
            
            return dp[i][k][b]=ans;
        }
        
        return dp[i][k][b]=max(solve(p,i+1,k-1,1,dp)-p[i],solve(p,i+1,k,0,dp));
        
    }
    
    int maxProfit(vector<int>& p) {
        
    vector<vector<vector<int>>>dp(p.size(),vector<vector<int>>(3,vector<int>(2,-1)));
        
        return solve(p,0,2,0,dp);   
    }
};