class Solution {
public:

    int rob(vector<int>& nums) {
        
        int n=nums.size();
        
        if(n==1)return nums[0];
        
        int pre2=nums[0],pre1=max(nums[0],nums[1]),curr=pre1;
        
        for(int z=2;z<n;z++)
        {
            curr=max(pre2+nums[z],pre1);
            pre2=pre1;
            pre1=curr;
        }
        return curr;
    }
};