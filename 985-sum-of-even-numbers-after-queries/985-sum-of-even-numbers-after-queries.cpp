class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
     
        int sum=0;
        
        for(int i:nums)
        {
            if(!(i&1))
                sum+=i;
        }
        vector<int>ans;
        for(int i=0;i<q.size();i++)
        {
            if(nums[q[i][1]]%2)
            {
                nums[q[i][1]]+=q[i][0];
                if(nums[q[i][1]]%2==0)
                {
                    sum+=nums[q[i][1]];
                }
            }
            else
            {
                if((nums[q[i][1]]+q[i][0])%2)
                {
                    sum-=nums[q[i][1]];
                }
                else
                    sum+=q[i][0];
                nums[q[i][1]]+=q[i][0];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};