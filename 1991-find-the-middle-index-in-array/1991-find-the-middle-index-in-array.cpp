class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        vector<int>l(n,0),r(n,0);
        l[0]=nums[0];
        r.back()=nums.back();
        for(int z=1;z<n;z++)
        {
            l[z]=l[z-1]+nums[z];
            r[n-z-1]=r[n-z]+nums[n-z-1];
        }
        if(r[1]==0)return 0;
        for(int i=1;i<n-1;i++)
        {
            if(l[i-1]==r[i+1])
            {
                return i;
            }
        }
        if(l[n-2]==0)return n-1;

        return -1;        
    }
};