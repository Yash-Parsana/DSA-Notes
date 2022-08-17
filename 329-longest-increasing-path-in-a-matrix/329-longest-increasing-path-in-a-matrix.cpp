class Solution {
public:
    
    int solve(vector<vector<int>> &v,int i,int j,int &n,int &m,vector<vector<int>>&dp)
    {
        if(i>=n||j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        if(i+1<n&&v[i+1][j]>v[i][j])
        {
            ans=solve(v,i+1,j,n,m,dp);
        }
        if(j+1<m&&v[i][j+1]>v[i][j])
            ans=max(ans,solve(v,i,j+1,n,m,dp));
        if(i-1>=0&&v[i-1][j]>v[i][j])
            ans=max(ans,solve(v,i-1,j,n,m,dp));
        if(j-1>=0&&v[i][j-1]>v[i][j])
            ans=max(ans,solve(v,i,j-1,n,m,dp));
        
        return dp[i][j]=ans+1;
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n=matrix.size(),m=matrix[0].size();
        
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,solve(matrix,i,j,n,m,dp));
            }
        }
        
        return ans;
    }
};