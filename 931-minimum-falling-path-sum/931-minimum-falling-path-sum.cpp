class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size();
        vector<int> dp(n,0),curr(n,0);
        
        for(int z=0;z<n;z++)
        {
            dp[z]=v[0][z];
        }
        

        for(int z=1;z<n;z++)
        {
            for(int y=0;y<n;y++)
            {
                curr[y]=dp[y];
                
                if(y!=0)curr[y]=min(curr[y],dp[y-1]);
                if(y!=n-1)curr[y]=min(curr[y],dp[y+1]);
                curr[y]+=v[z][y];
            }
            swap(dp,curr);
        }
        int ans=1e5;
        for(int z=0;z<n;z++)
        {
            ans=min(ans,dp[z]);
        }
        return ans;
    }
};