class Solution {
public:
    
    int solve(vector<vector<int>> &v,int i,int j,int &n,vector<vector<int>> &dp)
    {
        if(i==n-1)
        {
            return v[i][j];
        }
            
        if(dp[i][j]!=-1)return dp[i][j];
        
        
        int ans=solve(v,i+1,j,n,dp);
        
        if(j-1>=0)
            ans=min(ans,solve(v,i+1,j-1,n,dp));
        if(j+1<n)
            ans=min(ans,solve(v,i+1,j+1,n,dp));
        
        return dp[i][j]=ans+v[i][j];
    
    }
    
    int minFallingPathSum(vector<vector<int>>& v) {
        
        int n=v.size();
        int ans=1e5;
        
        for(int z=0;z<n;z++)
        {
            vector<vector<int>> dp(n,vector<int>(n,-1));
            ans=min(ans,solve(v,0,z,n,dp));
        }
        return ans;
    }
};