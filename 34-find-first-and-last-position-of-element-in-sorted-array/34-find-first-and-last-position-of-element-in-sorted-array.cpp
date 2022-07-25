class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int &target) {
        int n=nums.size();
        if(n==0) return {-1,-1};
        int right=-1,left=-1;
        
        int i=0,j=n-1;

        //For left
        while(i<=j)
        {
            int mid=(i+j)/2;
            
            if(nums[mid]>=target)
            {
                if(nums[mid]==target)
                {
                    left=mid;
                }
                j=mid-1;
            }
            else i=mid+1;
        }
        
        //for right
        
        i=left>=0?left:0;
        
        j=n-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            
            if(nums[mid]<=target)
            {
                if(nums[mid]==target)
                {
                    right=mid;
                }
                i=mid+1;
            }
            else j=mid-1;
            
        }
        return {left,right};
    }
};