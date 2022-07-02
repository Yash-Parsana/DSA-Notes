class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int z=0;z<n;z++)
        {
            dp[0][z]=v[0][z];
        }
        

        for(int z=1;z<n;z++)
        {
            for(int y=0;y<n;y++)
            {
                dp[z][y]=dp[z-1][y];
                
                if(y!=0)dp[z][y]=min(dp[z][y],dp[z-1][y-1]);
                if(y!=n-1)dp[z][y]=min(dp[z][y],dp[z-1][y+1]);
                dp[z][y]+=v[z][y];
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