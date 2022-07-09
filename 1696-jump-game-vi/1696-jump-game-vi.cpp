class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        
        deque<int> dq;
        
        dq.push_back(0);
        
        for(int z=1;z<nums.size();z++)
        {
            if(dq.front()+k<z)dq.pop_front();
            
            nums[z]+=nums[dq.front()];
            
            while(!dq.empty()&&nums[dq.back()]<nums[z])dq.pop_back();
            
            dq.push_back(z);
            
        }
        
        return nums.back();
    }
};