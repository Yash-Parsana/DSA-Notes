class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        
        for(int z=0;z<amount+1;z++)
        {
            if(z%coins[0]==0)dp[0][z]=z/coins[0];
            else dp[0][z]=1e5;
        }

        for(int z=1;z<n;z++)
        {
            for(int y=0;y<=amount;y++)
            {
                int dontTake=dp[z-1][y];
                int take=INT_MAX;
                if(y>=coins[z])
                    take=dp[z][y-coins[z]]+1;
                
                dp[z][y]=min(take,dontTake);
                // cout<<dp[z][y]<<" ";
            }
        }
        
        if(dp[n-1][amount]==1e5)return -1;
        return dp[n-1][amount];
    }
};
