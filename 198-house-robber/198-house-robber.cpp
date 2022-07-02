class Solution {
public:

    int rob(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)return nums[0];
        
        vector<int> dp(n,0);
        
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        
        
        for(int z=2;z<n;z++)
        {
            dp[z]=max(dp[z-2]+nums[z],dp[z-1]);
        }
        return dp[n-1];
    }
};