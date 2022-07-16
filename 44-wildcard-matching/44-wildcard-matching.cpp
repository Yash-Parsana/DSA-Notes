class Solution {
public:
    
    bool solve(string &s,string &p,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=s.size())
        {
            if(j>=p.size())return 1;
            while(j<p.size())
            {
                if(p[j]!='*')return 0;
                j++;
            }
            return 1;
        }
        if(j>=p.size())
        {
            return 0;
        }
    
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i]==p[j]||p[j]=='?')
            return dp[i][j]=solve(s,p,i+1,j+1,dp);

        if(p[j]=='*')
        {
            bool b=(solve(s,p,i+1,j,dp)||solve(s,p,i,j+1,dp));
            return dp[i][j]=b;
        }
        
        return dp[i][j]=0;
        
        
    }
    
    bool isMatch(string s, string p) {
        
        if(s.size()==0)
        {
            for(int z=0;z<p.size();z++)
            {
                if(p[z]!='*')return 0;
            }
            return 1;
        }
        if(s.empty()&&p.empty())return 1;
        
        if(p.empty()&&!s.empty())return 0;
        
        vector<vector<int>> dp(s.size(),vector<int>(p.size(),-1));
        return solve(s,p,0,0,dp);
        
    }
};