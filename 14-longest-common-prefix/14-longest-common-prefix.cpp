class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        
        int n=INT_MAX;
        
        for(int z=0;z<s.size();z++)
        {
            int t=s[z].size();
            n=min(n,t);
        }
        
        for(int z=1;z<s.size();z++)
        {
            int i=0;
            while(i<n&&s[z][i]==s[z-1][i])i++;
            n=i;
        }
        return s[0].substr(0,n);
        
    }
};