class Solution {
public:
    
    int solve(vector<int> &h,vector<vector<int>>&cost,int target,int i,int color,int &n,vector<vector<vector<int>>> &dp)
    {
        if(i==h.size())
        {
            if(target==0)return 0;
            return 1e7;
        }
        if(target<0)return 1e7;

        if(dp[i][color][target]!=-1)return dp[i][color][target];

        if(h[i]!=0)
        {
            if(color==h[i])
               return dp[i][color][target]=solve(h,cost,target,i+1,color,n,dp);
            return dp[i][color][target]=solve(h,cost,target-1,i+1,h[i],n,dp);  
        }
        int ans=1e7;
        for(int z=1;z<=n;z++)
        {
            if(color==z)
                ans=min(ans,solve(h,cost,target,i+1,z,n,dp)+cost[i][z-1]);
            else
                ans=min(ans,solve(h,cost,target-1,i+1,z,n,dp)+cost[i][z-1]);
        }
        return dp[i][color][target]=ans;
    }
    
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n+1,vector<int>(target+1,-1)));
        
        int ans=solve(houses,cost,target,0,0,n,dp);
        if(ans>=1e7)return -1;
        return ans;
    }
};