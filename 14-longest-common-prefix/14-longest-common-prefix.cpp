class Solution {
public:
    string longestCommonPrefix(vector<string> s) {
    
        if(s.size()==1&&s[0]=="") return "";
       
        int n=INT_MAX;
        for(int z=0;z<s.size();z++)
        {
            int k=s[z].length();
            n=min(n,k);
        }
        
        string ans="";
        char temp;
        int count=0;

        bool b=1;
        while(b&&count<n)
        {
            temp=s[0][count];
            for(int z=0;z<s.size();z++)
            {
                if(temp!=s[z][count]) b=0;
            }
            if(b)
            {
                ans+=s[0][count];
                count++;
            }
        }

        if(count)
        {
            return ans;
        }
            ans="";
         return ans;
        }
    
};