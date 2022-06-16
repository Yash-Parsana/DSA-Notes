class Solution {
public:
    bool isValid(string s) {
        
        int n=s.size();
        stack<char> st;
        
        for(int z=0;z<n;z++)
        {
            if(s[z]=='{'||s[z]=='('||s[z]=='[')
            {
                st.push(s[z]);
            }
            else if(st.empty()) return 0;
            else if(s[z]==')'&&st.top()=='(')
            {
                st.pop();
            }
            else if(s[z]==']'&&st.top()=='[')
            {
                st.pop();
            }
            else if(s[z]=='}'&&st.top()=='{')
            {
                st.pop();
            }
            else return 0;
        
        
        }
        if(!st.empty()) return 0;
        
        return 1;
        
    }
};