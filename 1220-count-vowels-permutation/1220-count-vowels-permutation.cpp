class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> r={{1},{0,2},{0,1,3,4},{2,4},{0}};
    
    int solve(int n,int v,vector<vector<int>> &dp)
    {
        if(n==1)return 1;
        if(dp[n][v]!=-1)return dp[n][v];
        int ans=0;
        for(int i:r[v])
        {
            ans=(ans+solve(n-1,i,dp))%mod;
        }
        return dp[n][v]=ans;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n+1,vector<int>(5,-1));
        int ans=0;
        for(int z=0;z<5;z++)
        {
            ans=(ans+solve(n,z,dp))%mod;
        }
        return ans;
    }
};