class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        
        int n=v.size();
        vector<int> dp(n,1e5);
        
        dp[0]=v[0][0];
        
        for(int z=1;z<n;z++)
        {
        
            for(int y=z;y>=0;y--)
            {
                if(y==0)dp[y]+=v[z][y];
                else
                    dp[y]=min(dp[y],dp[y-1])+v[z][y];
            }
            
        }
        
        int ans=1e5;
        
        for(int z=0;z<n;z++)
        {
            ans=min(ans,dp[z]);
        }
        return ans;
    }
};