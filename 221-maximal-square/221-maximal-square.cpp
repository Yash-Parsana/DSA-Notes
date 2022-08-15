class Solution {
public:
    int maximalSquare(vector<vector<char>>& mtx) {
        
        int n=mtx.size(),m=mtx[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        int ans=0;
        for(int z=0;z<n;z++)
        {
            dp[z][0]=mtx[z][0]-'0';
            ans=max(ans,dp[z][0]);
        }
        for(int z=0;z<m;z++)
        {
            dp[0][z]=mtx[0][z]-'0';
            ans=max(ans,dp[0][z]);
        }
        for(int z=1;z<n;z++)
        {
            for(int y=1;y<m;y++)
            {
                if(mtx[z][y]=='1')
                {
                    dp[z][y]=min({dp[z-1][y-1],dp[z][y-1],dp[z-1][y]})+1;
                }
                ans=max(ans,dp[z][y]*dp[z][y]);
            }
        }
        return ans;
        
    }
};