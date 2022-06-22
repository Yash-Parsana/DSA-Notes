class Solution {
public:
    
    int charToint(char c)
    {
        return ((c-'0')-('a'-'0'));
        
    }
    
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size()) return 0;

        vector<int> v(26,0);
    
        for(int z=0;z<s.size();z++)
        {
            v[charToint(s[z])]++;        
        }
        
        for(int z=0;z<t.size();z++)
        {
            v[charToint(t[z])]--;
        }
        
        for(int z=0;z<26;z++)
        {
            if(v[z]!=0)return 0;
        }
        return 1;
    }
};