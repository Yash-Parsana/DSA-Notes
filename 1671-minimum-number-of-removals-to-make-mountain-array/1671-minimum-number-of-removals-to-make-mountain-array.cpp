class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
    
        for(int z=0;z<n;z++)
        {
            for(int y=0;y<z;y++)
            {
                if(nums[z]>nums[y]&&dp1[z]<dp1[y]+1)
                    dp1[z]=dp1[y]+1;
            }
        }
        for(int z=n-1;z>=0;z--)
        {
            for(int y=n-1;y>z;y--)
            {
                if(nums[z]>nums[y]&&dp2[z]<dp2[y]+1)
                    dp2[z]=dp2[y]+1;
            }
        }
        int ans=INT_MAX;
        for(int z=1;z<n-1;z++)
        {
            if(dp1[z]!=1&&dp2[z]!=1)
                ans=min(ans,n-(dp1[z]+dp2[z]-1));    
        }
        return ans;
    }
};