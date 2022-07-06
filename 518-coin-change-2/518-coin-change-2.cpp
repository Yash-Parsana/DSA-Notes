class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
        for(int z=0;z<=amount;z++)
        {
            if(z%coins[0]==0)
                dp[0][z]=1;
        }
        
        for(int z=1;z<n;z++)
        {
            for(int y=0;y<amount+1;y++)
            {
                int take=0;
                if(coins[z]<=y)
                    take=dp[z][y-coins[z]];
                int dontTake=dp[z-1][y];
                
                dp[z][y]=take+dontTake;
            }
        }
        return dp[n-1][amount];
    }
};