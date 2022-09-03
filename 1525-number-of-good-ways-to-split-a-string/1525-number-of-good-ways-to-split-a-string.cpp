class Solution {
public:
    int numSplits(string s) {
        int l=0,r=0;
        vector<int>lr(26,0),rl(26,0);
        int n=s.size();
        
        for(char c:s)
        {
            if(lr[c-'a']==0)
                r++;
            lr[c-'a']++;
        }

        int ans=0;

        for(char c:s)
        {
            if(!rl[c-'a'])
                l++;
            rl[c-'a']++;
            if(lr[c-'a']==1)
                r--;
            lr[c-'a']--;
            
            if(l==r)ans++;
        }
        
        return ans;
    }
};