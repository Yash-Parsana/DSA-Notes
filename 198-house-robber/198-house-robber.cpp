class Solution {
public:
    int solve(vector<int> &v,vector<int> &dp,int i)
    {
        if(i>=v.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];

        return dp[i]=max(solve(v, dp, i + 1), solve(v, dp, i + 2) + v[i]);
    }
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(),-1);
        return solve(nums,dp,0);
        
    }
};