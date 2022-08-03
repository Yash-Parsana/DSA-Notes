class Solution {
public:
    
    int solve(vector<int>&v,vector<vector<int>>&dp,int i,int j)
    {
        if(i>j)return 0;
        if(i==j)return v[i];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int left=v[i]-solve(v,dp,i+1,j);
        int right=v[j]-solve(v,dp,i,j-1);
        
        return dp[i][j]=max(left,right);
        
    }
    
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return solve(piles,dp,0,n-1)>0;
    }
};