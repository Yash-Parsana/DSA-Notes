class Solution {
public:
    
    int solve(vector<int>&multi,vector<int>&nums,int i,int j,int ii,vector<vector<int>>&dp)
    {
        if(ii>=multi.size()||i>=multi.size())
            return 0;
        if(dp[ii][i]!=INT_MIN)return dp[ii][i];
        
        return dp[ii][i]=max(solve(multi,nums,i+1,j,ii+1,dp)+multi[ii]*nums[i],solve(multi,nums,i,j-1,ii+1,dp)+multi[ii]*nums[j]);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        vector<vector<int>> dp(multi.size(),vector<int>(multi.size(),INT_MIN));
        return solve(multi,nums,0,nums.size()-1,0,dp);
    }
};