int mod=1e9+7;
class Solution {
public:
    int solve(vector<vector<int>> &v,int i,int j,int &n,int &m,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=0;
        if(i+1<n&&v[i+1][j]>v[i][j])
            ans=solve(v,i+1,j,n,m,dp);
        if(j+1<m&&v[i][j+1]>v[i][j])
            ans=(ans+solve(v,i,j+1,n,m,dp))%mod;
        if(i-1>=0&&v[i-1][j]>v[i][j])
            ans=(ans+solve(v,i-1,j,n,m,dp))%mod;
        if(j-1>=0&&v[i][j-1]>v[i][j])
            ans=(ans+solve(v,i,j-1,n,m,dp))%mod;
        
        return dp[i][j]=(ans+1)%mod;
        
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=(ans+solve(grid,i,j,n,m,dp))%mod;
            }
        }
        return ans;
    }
};