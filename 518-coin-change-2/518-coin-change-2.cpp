class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<int>dp(amount+1,0);
        
        for(int z=0;z<=amount;z++)
        {
            if(z%coins[0]==0)
                dp[z]=1;
        }
        
        for(int z=1;z<n;z++)
        {
            for(int y=0;y<=amount;y++)
            {
                int take=0;
                if(coins[z]<=y)
                    take=dp[y-coins[z]];
                int dontTake=dp[y];
                
                dp[y]=take+dontTake;
            }
        }
        return dp[amount];
    }
};