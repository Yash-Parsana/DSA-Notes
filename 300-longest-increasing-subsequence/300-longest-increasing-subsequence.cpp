class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=1;
        for(int z=0;z<n;z++)
        {
            for(int y=0;y<z;y++)
            {
                if(nums[z]>nums[y]&&dp[y]+1>dp[z])
                    dp[z]=dp[y]+1,ans=max(ans,dp[z]);
            }
        }
        return ans;
    }
};