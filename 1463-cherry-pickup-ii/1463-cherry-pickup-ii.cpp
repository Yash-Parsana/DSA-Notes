class Solution {
public:
    
    
    int solve(vector<vector<int>> &v,int i,int j1,int j2,int &n,int &m,vector<vector<vector<int>>> &dp)
    {
        if(j1<0||j2<0||j1>=m||j2>=m)
            return -1e5;
        if(i==n-1)
        {
            if(j1==j2)return v[i][j1];
            else return v[i][j1]+v[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        
        int ans=-1;
        for(int z=-1;z<2;z++)
        {
            for(int y=-1;y<2;y++)
            {
                ans=max(ans,solve(v,i+1,j1+z,j2+y,n,m,dp));
            }
        }
        
        if(j1==j2)return dp[i][j1][j2]=ans+v[i][j1];
        
        return dp[i][j1][j2]=ans+v[i][j1]+v[i][j2];
            
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        return solve(grid,0,0,m-1,n,m,dp);
        
    }
};