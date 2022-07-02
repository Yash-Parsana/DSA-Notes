class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0;
        
        int i=0,jump=0;
        while(i<nums.size()-1)
        {
            int temp=0,idx=i;
            if(i+nums[i]>=nums.size()-1)
            {
                ans++;break;
            }
            for(int z=i+1;z<=i+nums[i];z++)
            {
                if(z+nums[z]>temp)
                {
                    idx=z;
                    temp=z+nums[z];
                }
            }
            ans++;
            i=idx;
        }
        return ans;
    }
};