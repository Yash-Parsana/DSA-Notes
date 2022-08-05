class Solution {
public:
    int solve(vector<int> &v,vector<int>&dp,int k)
    {
        if(k<0)return 0;
        if(k==0)return 1;
        if(dp[k]!=-1)return dp[k];
        int ans=0;
        for(int i:v)
        {
            ans+=solve(v,dp,k-i);
        }
        return dp[k]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return solve(nums,dp,target);
    }
};