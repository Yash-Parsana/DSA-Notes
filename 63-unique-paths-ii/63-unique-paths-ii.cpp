class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int z=0;z<n;z++)
        {
            if(v[z][0]==1)break;
            
            dp[z][0]=1;
            
        }
        for(int z=0;z<m;z++)
        {
            if(v[0][z]==1)break;
            
            dp[0][z]=1;
        }
        
        for(int z=1;z<n;z++)
        {
            for(int y=1;y<m;y++)
            {
                if(v[z][y]!=1)
                    dp[z][y]=dp[z-1][y]+dp[z][y-1];
            }
        }
        
        return dp[n-1][m-1];
        
    }
};