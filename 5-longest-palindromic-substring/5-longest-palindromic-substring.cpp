class Solution {
public:
    
    
    string evenString(string &s)
{
    int i=0, j=1;
    string ans = "";
    while(j<s.size())
    {
        int ii = i, jj = j;
        while(ii>=0&&jj<s.length()&&s[ii]==s[jj])
        {
            ii--;
            jj++;
        }
        ii++;
        jj--;
        if(ans.size()<jj-ii+1)
        {
            ans = s.substr(ii, jj - ii + 1);
        }
        i++;
        j++;
    }
    return ans;
}
string oddString(string &s)
{
    int i = 0, j = 2;
    string ans = "";

    while(j<s.size())
    {
        int ii = i, jj = j;
        while(ii>=0&&jj<s.length()&&s[ii]==s[jj])
        {
            ii--;
            jj++;
        }
        ii++;
        jj--;
        if(ans.size()<jj-ii+1)
        {
            ans = s.substr(ii, jj - ii + 1);
        }
        i++;
        j++;
    }
    return ans;
}

    
    string longestPalindrome(string s) {
        
        if(s.size()==1||s.size()==0)return s;
        
        string even = evenString(s),odd=oddString(s);

        if(even.size()==0&&odd.size()==0) return s.substr(0,1);
        
        if(even.size()<odd.size())
        {
            return odd;
        }
        return even; 
    }
};