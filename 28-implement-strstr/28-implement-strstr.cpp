class Solution {
public:
    vector<int> prefixArr(string s)
    {
        int n = s.size();
        vector<int> pi(n,0);

        for (int z = 1; z < n;z++)
        {
            int j = pi[z - 1];
            while(j>0&&s[z]!=s[j])
            {
                j = pi[j - 1];
            }
            if(s[z]==s[j])
                j++;
            pi[z] = j;
        }
        return pi;
    }
    int strStr(string haystack, string needle) {
     
        if(needle=="")return 0;
        if(needle.size()>haystack.size()) return -1;    

        vector<int> pi=prefixArr(needle);

        int ansi = -1;

        int i = 0,j=0;
        while(i<haystack.size())
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else{
                if(j!=0)
                {
                    j = pi[j-1];
                }
                else
                    i++;
            }
            if(j==needle.length())
                return i - needle.size() ;
        }
        return -1;
    }
};