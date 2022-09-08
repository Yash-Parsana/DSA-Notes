class Solution {
public:
    
    
    int atMost(vector<int>&v,int k)
    {
        int i=0,j=0,ans=0,temp=0;
        
        while(j<v.size())
        {
            if(v[j]&1)temp++;
            
            while(temp>k)
            {
                if(v[i]&1)temp--;
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        return atMost(nums,k)-atMost(nums,k-1);
        
    }
};