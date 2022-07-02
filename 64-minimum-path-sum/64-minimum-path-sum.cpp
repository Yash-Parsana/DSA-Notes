class Solution {
public:
    
    int solve(vector<vector<int>> &v,int &n,int &m,int i,int j,vector<vector<int>>&dp)
    {
        if(i==n-1&&j==m-1)return v[n-1][m-1];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=1e8;
        if(i+1<n)
            ans=min(ans,solve(v,n,m,i+1,j,dp)+v[i][j]);
        if(j+1<m)
            ans=min(ans,solve(v,n,m,i,j+1,dp)+v[i][j]);
        return dp[i][j]=ans;
    }
    
    
    int minPathSum(vector<vector<int>>& v) {
        
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return solve(v,n,m,0,0,dp);
        
    }
};