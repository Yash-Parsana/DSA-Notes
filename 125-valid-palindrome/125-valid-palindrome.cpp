class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>='A' and s[i]<='Z')ans+=(s[i]+32);
            else if(s[i]>='a' and s[i]<='z' or   s[i]>='0' and s[i]<='9')ans+=s[i];
        }
        
        
        string temp=ans;
        // if(ans.size()<=2)return false;
        reverse(temp.begin(),temp.end());
        if(temp==ans)return true;
        return false;
    }
};