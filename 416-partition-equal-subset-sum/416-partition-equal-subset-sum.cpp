class Solution {
public:
    bool canPartition(vector<int>& v) {
        
        int n=v.size();
        if(n==1)return false;
        int k=0;
        for(int i:v)k+=i;
        if(k&1)return 0;
        k=k/2;
        
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));
        
        for(int z=0;z<n;z++)
        {
            dp[z][0]=1;
        }
        if(v[0]<=k)
            dp[0][v[0]]=1;
        
        for(int z=1;z<n;z++)
        {
            for(int target=1;target<=k;target++)
            {
                if(target-v[z]>=0)dp[z][target]=dp[z-1][target-v[z]];
                dp[z][target]=dp[z][target]|dp[z-1][target];
            }
        }
        return dp[n-1][k];
        
    }
};