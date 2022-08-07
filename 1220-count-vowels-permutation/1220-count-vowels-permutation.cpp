class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> r={{1,2,4},{0,2},{1,3},{2},{2,3}};
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        for(int z=0;z<5;z++)dp[1][z]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<5;j++)
            {
                for(int k:r[j])
                {
                    dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        int ans=0;
        for(int z=0;z<5;z++)
        {
            ans=(ans+dp[n][z])%mod;
        }
        return ans;
    }
};