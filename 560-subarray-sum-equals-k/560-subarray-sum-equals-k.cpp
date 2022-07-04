class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> m;
        int sum=0,ans=0;
        for(int i:nums)
        {
            sum+=i;
         
            if(sum==k)ans++;
            
            if(m.find(sum - k) != m.end())
                ans+=m[sum-k];
            
            m[sum]++;
        }
        return ans;
        
    }
};