class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        

    priority_queue<int,vector<int>,greater<int>> h;

    for (int z = 0; z <= nums.size()-1;z++)
    {
        h.push(nums[z]);

        while(h.size()>k)
            h.pop();
    }
    return h.top();        
        
    }
};