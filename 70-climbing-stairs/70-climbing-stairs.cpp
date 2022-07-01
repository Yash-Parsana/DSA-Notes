class Solution {
public:
    
        int totalSteps(int n,vector<int> &dp)
    {
        if(n<0)return 0;
        if(n==0)
        {
            return 1;
        }
        if(dp[n]!=-1)return dp[n];
        return dp[n]=totalSteps(n-1,dp)+totalSteps(n-2,dp);
    }
    
    int climbStairs(int n) {
        
       
        vector<int>dp(n+1,-1);
        totalSteps(n,dp);
        return dp[n];
        
    }
//     int climbStairs(int n) {
        
//         if(n==0||n==1)return n;
//         vector<int> dp(n+1,0);
//         dp[0]=0;
//         dp[1]=1;
        
//         for(int z=2;z<=n;z++)
//         {
//             dp[z]=dp[z-1]+dp[z-2]+1;
//         }
//         return dp[n];
//     }
};