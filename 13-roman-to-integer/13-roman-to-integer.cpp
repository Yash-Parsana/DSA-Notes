class Solution {
public:
    int romanToInt(string s) {
        
        
        map<char, int> m;
        m['M'] = 1000;
        m['D'] = 500;
        m['C'] = 100;
        m['L'] = 50;
        m['X'] = 10;
        m['V'] = 5;
        m['I'] = 1;

        int previous = 0,ans=0;
        for (int z = s.size(); z >= 0;z--)
        {
            if(m[s[z]]<previous)
            {
                ans -= m[s[z]];
            }
            else{
                ans += m[s[z]];
            }
            previous = m[s[z]];
        }
        return ans; 

    }
};