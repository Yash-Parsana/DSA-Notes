class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        stack<char> st;
        
        for(int z=s.size()-1;z>=0;z--)
        {
            if(s[z]!='-')
            {
                st.push(toupper(s[z]));
            }
        }
        if(st.empty())return "";
        int n=st.size()/k;
        int extra=st.size()%k;
        
        string ans="";
        while(extra--)
        {
            ans+=st.top();
            st.pop();
        }
        if(!ans.empty())
            ans+="-";
        int c=0;
        while(!st.empty())
        {
            c++;
            ans+=st.top();
            st.pop();
            if(c==k)
            {
                ans+="-";
                c=0;
            }
        }
        
        ans.pop_back();
        return ans;
    }
};