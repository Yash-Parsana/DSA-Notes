class Solution {
public:
    
    int solve(vector<int> &v,vector<int> &dp,int i,int n)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
            return dp[i];

        return dp[i]=max(solve(v, dp, i + 1,n), solve(v, dp, i + 2,n) + v[i]);
    }
    
    int rob(vector<int>& nums) {
        
        
        int n=nums.size();
        
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        
        
        vector<int> dp(n,-1);
        int ans1=solve(nums,dp,0,n-1);
        dp=vector<int>(n,-1);
        
        int ans2=solve(nums,dp,1,n);           
        return max(ans1,ans2);
    }
    

};