class Solution {
public:
    
    int solve(vector<int> &v,int i,int j)
    {
        if(i>j) return -1;
        
        int mid=(i+j)/2;
        
        if((mid!=0&&v[mid]==v[mid-1])||(mid!=v.size()-1&&v[mid]==v[mid+1]))
        {
            return max(solve(v,i,mid-1),solve(v,mid+1,j));
        }
        
        return v[mid];
        
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        
        return solve(nums,0,nums.size()-1);
        
    }
};