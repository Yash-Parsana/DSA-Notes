class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int j=0;
        int size=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<size;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                if(abs(mp[nums[i]]-i)<=k)
                {
                    return true;
                }
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};