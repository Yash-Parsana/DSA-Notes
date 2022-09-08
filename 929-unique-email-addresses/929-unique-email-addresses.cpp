class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        set<string> st;
        for(string s:emails)
        {
            string temp="";
            bool b=1;
            int i=0;
            while(i<s.size())
            {
                char c=s[i];
                if(c=='.'&&b);
                else if(c=='+'&&b)
                {
                    while(s[i]!='@')
                        i++;
                    temp+='@';
                    b=0;
                }
                else {
                    temp+=c;
                    if(c=='@')b=0;
                }
                // cout<<i<<endl;
                i++;
            }
            // cout<<temp<<endl;
            st.insert(temp);
        }
        return st.size();
    }
};