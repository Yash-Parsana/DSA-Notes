class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        unordered_map<int,int> fre;
        
        for(int i:nums)
            fre[i]++;
        
        sort(nums.begin(),nums.end());
        for(int i:nums)
        {
            if(fre[i]==0)continue;
            int kk=k;
            
            for(int j=1;j<k;j++)
            {
                if(fre[i+j]<1)return 0;
                fre[i+j]--;
            }
            fre[i]--;
        }
        return 1;
    }
};