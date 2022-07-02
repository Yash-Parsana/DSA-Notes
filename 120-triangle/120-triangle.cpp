class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        
        int n=v.size();
        vector<vector<int>> dp(n,vector<int>(n,1e5));
        
        dp[0][0]=v[0][0];
        for(int z=1;z<n;z++)
        {
            dp[z][0]=dp[z-1][0]+v[z][0];
        }
        
        for(int z=1;z<n;z++)
        {
            for(int y=1;y<=z;y++)
            {
                dp[z][y]=min(dp[z-1][y],dp[z-1][y-1])+v[z][y];
            }
        }
        

        
        int ans=1e5;
        for(int z=0;z<n;z++)
        {
            ans=min(ans,dp[n-1][z]);
        }
        return ans;
    }
};