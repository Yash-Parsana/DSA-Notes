class Solution {
public:
    
    int solve(vector<int> &p,int i,bool b,vector<vector<int>> &dp)
    {
        if(i>=p.size())return 0;
        
        if(dp[i][b]!=-1)return dp[i][b];
        
        if(b)
        {
            return dp[i][b]=max(solve(p,i+1,0,dp)+p[i],solve(p,i+1,b,dp));
        }
        
        return dp[i][b]=max(solve(p,i+1,1,dp)-p[i],solve(p,i+1,0,dp));
        
    }
    
    int maxProfit(vector<int>& v) {
        
        // vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        
        // return solve(prices,0,0,dp);
        
        int ans=0,n=v.size();
        for(int z=1;z<n;z++)
        {
            if(v[z]>v[z-1])
                ans+=v[z]-v[z-1];
        }
        return ans;
    }
};