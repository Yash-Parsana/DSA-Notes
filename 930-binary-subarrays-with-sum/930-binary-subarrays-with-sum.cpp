class Solution {
public:
    
    int atMost(vector<int>&nums,int k)
    {
        int i=0,j=0,ans=0,temp=0;
        while(j<nums.size())
        {
            if(nums[j])temp++;
            while(temp>k)
            {
                if(nums[i])temp--;
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int k) {
        // cout<<atMost(nums,k)<<" "<<atMost(nums,k-1)<<endl;
        if(k==0)return atMost(nums,k);
        return atMost(nums,k)-atMost(nums,k-1);
    }
};