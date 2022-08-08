class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,0),path(n);
        int pre=0,mx=0;
        for(int z=1;z<n;z++)
        {
            path[z]=z;
            for(int j=0;j<z;j++)
            {
                if(nums[z]%nums[j]==0&&dp[j]+1>dp[z])
                    dp[z]=dp[j]+1,path[z]=j;
            }
            if(dp[z]>dp[mx])mx=z;
        }
        
        vector<int>ans;
        while(mx!=path[mx])
        {
            ans.push_back(nums[mx]);
            mx=path[mx];
        }
        ans.push_back(nums[mx]);
        return ans;
        
    }
};