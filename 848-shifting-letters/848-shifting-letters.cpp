class Solution {
public:
    char shift(char c,int s)
    {
        char ans='a';
        int curr=c-'a';
        curr+=s;
        curr%=26;
        
        ans+=curr;
        return ans;
        
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        
        string ans="";
        int cs=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            cs=(cs+shifts[i])%26;
            ans+=shift(s[i],cs);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};