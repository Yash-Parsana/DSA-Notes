class Solution {
public:
    
    int solve(int i,int &n,vector<int>&v,vector<unordered_map<int,int>> &dp,int target)
    {
        if(i>=n)
        {
            if(target==0)return 1;
            return 0;
        }
        
        if(dp[i].find(target)!=dp[i].end())return dp[i][target];
        
        return dp[i][target]=solve(i+1,n,v,dp,target-v[i])+solve(i+1,n,v,dp,target+v[i]);
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int,int>>dp(n);
      
        return solve(0,n,nums,dp,target);
        
    }
};