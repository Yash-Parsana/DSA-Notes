class Solution {
public:
    bool isMatch(string s, string p) {
     
        
        if(s.empty()&&p.empty())return 1;
        if(s.empty())
        {
            for(int z=0;z<p.size();z++)
            {
                if(p[z]!='*')return 0;
            }
            return 1;
        }
        if(p.empty())return 0;
        
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,0));
        
        if(p[0]==s[0]||p[0]=='?')
        {
            dp[0][0]=1;
        }
        else if(p[0]=='*')
        {
            for(int z=0;z<s.size();z++)
            {
                dp[z][0]=1;
            }


        }
        bool b=0;
        for(int z=0;z<p.size();z++)
        {
            if(!b&&(p[z]==s[0]||p[z]=='?')){
                dp[0][z]=1;b=1;
            }
            else if(p[z]=='*')
            {
                dp[0][z]=1;                    
            }
            else break;
        }

        for(int z=1;z<s.size();z++)
        {
            for(int y=1;y<p.size();y++)
            {
                if(s[z]==p[y]||p[y]=='?')
                {
                    dp[z][y]=dp[z-1][y-1];
                }
                else if(p[y]=='*')
                {
                    dp[z][y]=dp[z-1][y]||dp[z][y-1];
                }
            }
        }

        return dp[s.size()-1][p.size()-1];
    }
};