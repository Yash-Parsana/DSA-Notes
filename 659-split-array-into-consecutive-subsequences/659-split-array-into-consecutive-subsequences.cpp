class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int,int> fre,endat;
        
        for(int i:nums)
        {
            fre[i]++;
        }
        
        for(int i:nums)
        {
            if(fre[i]==0)continue;
            
            if(endat[i-1]>0)
            {
                endat[i-1]--;
                endat[i]++;
            }
            else if(fre[i+1]>0&&fre[i+2]>0)
            {
                fre[i+1]--;
                fre[i+2]--;
                endat[i+2]++;
            }
            else return 0;
            fre[i]--;
        }
        return 1;
    }
};