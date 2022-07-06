class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        
        vector<int> dp(amount+1,0);
        
        for(int z=0;z<amount+1;z++)
        {
            if(z%coins[0]==0)dp[z]=z/coins[0];
            else dp[z]=1e5;
        }

        for(int z=1;z<n;z++)
        {
            for(int y=0;y<=amount;y++)
            {
                int dontTake=dp[y];
                int take=INT_MAX;
                if(y>=coins[z])
                    take=dp[y-coins[z]]+1;
                
                dp[y]=min(take,dontTake);
            }
        }
        
        if(dp[amount]==1e5)return -1;
        return dp[amount];
    }
};
