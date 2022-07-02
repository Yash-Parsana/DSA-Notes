class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        
        for(int z=0;z<n;z++)
        {
            for(int y=0;y<z;y++)
            {
                if(nums[y]+y>=z)
                {
                    dp[z]=min(dp[z],dp[y]+1);
                }
            }
        }
        return dp[n-1];
    }
};