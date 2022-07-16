class Solution {
public:
    int mod=1e9+7;
    int solve(int &n,int &m,int cm,int i,int j,int &mxm,vector<vector<vector<int>>> &dp)
    {
        if(cm>mxm)return 0;

        if(dp[i][j][cm]!=-1)return dp[i][j][cm];     
        
        int ans=0;
        
        if(i+1<n)
            ans=(ans + solve(n,m,cm+1,i+1,j,mxm,dp)) % mod;        
        else if(i+1>=n&&cm<mxm)ans=(ans+1)%mod;
        
        if(j+1<m)
            ans=(ans+solve(n,m,cm+1,i,j+1,mxm,dp))%mod;
        else if(j+1>=m&&cm<mxm)
            ans=(ans+1)%mod;
        
        if(j-1>=0)
            ans=(ans+solve(n,m,cm+1,i,j-1,mxm,dp))%mod;
        else if(j-1<0&&cm<mxm)
            ans=(ans+1)%mod;
        
        if(i-1>=0)
            ans=(ans+solve(n,m,cm+1,i-1,j,mxm,dp))%mod;
        else if(i-1<0&&cm<mxm)
            ans=(ans+1)%mod;
        
        
        

        return dp[i][j][cm]=(ans)%mod;
        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return solve(m,n,0,startRow,startColumn,maxMove,dp);
        
    }
};