class Solution {
public:
    int minStartValue(vector<int>& nums) {
        
        int sum=1;
        int ans=1;
        for(int i:nums)
        {
            sum+=i;
            if(sum<1)
            {
                ans+=1-sum;
                sum=1;
            }
        }
        return ans;
    }
};