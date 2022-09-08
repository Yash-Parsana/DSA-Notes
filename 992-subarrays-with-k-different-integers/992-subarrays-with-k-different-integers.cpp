class Solution {
public:
    
    
    int atMost(vector<int>&v,int k)
    {
        int i=0,j=0,ans=0;
        
        map<int,int> mp;
        
        while(j<v.size())
        {
            
            mp[v[j]]++;
            
            while(mp.size()>k)
            {
                if(--mp[v[i]]==0)mp.erase(v[i]);
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};