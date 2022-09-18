class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1,leftmax=0,rightmax=0;
        int ans=0;
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(leftmax>height[l]) ans+=leftmax-height[l];
                else leftmax=height[l];
                l++;
            }
            else
            {
                if(rightmax>height[r])ans+=rightmax-height[r];
                else rightmax=height[r];
                r--;
            }
        }
        return ans; 
        
    }
};