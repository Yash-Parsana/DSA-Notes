class Solution {
public:
    int minPartitions(string s) {
        
        int ans=0;
        
        for(int z=0;z<s.size();z++)
        {
            ans=max(ans,s[z]-'0');
        }
        return ans;
    }
};