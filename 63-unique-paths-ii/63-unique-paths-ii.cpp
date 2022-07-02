class Solution {
public:
    
    int solve(vector<vector<int>>&v,int &n,int &m,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=n||j>=m||v[i][j]==1)return 0;
        
        if(i==n-1&&j==m-1)return 1;
    
        if(dp[i][j]!=-1)return dp[i][j];
        
        return dp[i][j]=solve(v,n,m,i+1,j,dp)+solve(v,n,m,i,j+1,dp);
    
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
     
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        
        return solve(v,n,m,0,0,dp);
        
    }
};