class Solution {
public:
    
    int rob(vector<int>& nums,int i,int n) {
        
        vector<int> dp(n,0);
        
        dp[i]=nums[i];
        dp[i+1]=max(dp[i],nums[i+1]);
        
        
        for(int z=i+2;z<n;z++)
        {
            dp[z]=max(dp[z-2]+nums[z],dp[z-1]);
        }
        return dp[n-1];
    }
    
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        if(n==3)return max({nums[0],nums[1],nums[2]});
        
        return max(rob(nums,0,n-1),rob(nums,1,n));
        
    }
};