class Solution {
public:
    int minScoreTriangulation(vector<int>& v) {
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int mi=1e9;
                for(int k=i;k<j;k++)
                {
                    mi=min(mi,dp[i][k]+dp[k+1][j]+v[i-1]*v[k]*v[j]);
                }
                dp[i][j]=mi;
            }
        }
        return dp[1][n-1];
    }
};