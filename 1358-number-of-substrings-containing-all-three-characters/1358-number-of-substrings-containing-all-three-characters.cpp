class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> mp;
        int i=0,j=0,ans=0;
        while(j<s.size())
        {
            mp[s[j]]++;
            while(mp.size()>=3)
            {
                if(--mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            ans+=i;
            j++;
        }
        return ans;
    }
};