class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0,close=0;
        int ans=0;
        for(char c:s)
        {
            if(c=='(')
            {
                open++;
                ans+=close;
                close=0;
            }
            else
            {
                if(open>0)open--;
                else close++;
            }
            
        }
        ans+=open;
        ans+=close;
        return abs(ans);
    }
};