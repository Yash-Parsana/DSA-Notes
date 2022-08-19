class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        
        int mx=-1,mi=INT_MAX;
        
        for(int i:nums)mx=max(mx,i),mi=min(mi,i);
        
        return max(0,mx-mi-2*k);
        
    }
};