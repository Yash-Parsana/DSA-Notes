class Solution {
public:
    int uniquePaths(int n, int m) {
        
        vector<vector<int>> dp(n,vector<int>(m,1));
        
        for(int z=1;z<n;z++)
        {
            for(int y=1;y<m;y++)
            {
                dp[z][y]=dp[z-1][y]+dp[z][y-1];
            }
        }
        
        
        return dp[n-1][m-1];
    }
};