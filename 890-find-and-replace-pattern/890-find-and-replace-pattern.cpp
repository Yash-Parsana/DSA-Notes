class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string &p) {
        vector<string> ans;
        for(string s:words)
        {
            map<char,char>m1;
            map<char,char>m2;
            
            for(int z=0;z<s.size();z++)
            {
                if(m1.find(s[z])!=m1.end()&&m1[s[z]]!=p[z])
                    break;
                if(m2.find(p[z])!=m2.end()&&m2[p[z]]!=s[z])
                    break;
                else if(m1.find(s[z])==m1.end()&&m2.find(p[z])==m2.end())
                    m1[s[z]]=p[z],m2[p[z]]=s[z];
                if(z==s.size()-1)ans.push_back(s);
            }
            
        }
        return ans;
    }
};