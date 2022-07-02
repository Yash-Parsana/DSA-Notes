class Solution {
public:
    
    int rob(vector<int>& nums,int i,int n) {
        
        
        int pre2=nums[i];
        int pre1=max(nums[i],nums[i+1]);
        int curr=pre1;
        
        for(int z=i+2;z<n;z++)
        {
            curr=max(pre2+nums[z],pre1);
            pre2=pre1;
            pre1=curr;
        }
        return curr;
    }
    
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        if(n==3)return max({nums[0],nums[1],nums[2]});
        
        return max(rob(nums,0,n-1),rob(nums,1,n));
        
    }
};