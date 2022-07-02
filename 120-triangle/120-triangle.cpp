class Solution {
public:
    
    int solve(vector<vector<int>> &v,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=v.size())return 1e8;
        if(i==v.size()-1)
        {
            return v[i][j];
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        return dp[i][j]=min(solve(v,i+1,j,dp),solve(v,i+1,j+1,dp))+v[i][j];
    
    }
    
    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return solve(v,0,0,dp);
        
    }
};