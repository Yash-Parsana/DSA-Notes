class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        string str=s;
        reverse(str.begin(),str.end());
        
        bool b=0;
        for(int z=0;z<n;z++)
        {
            if(str[0]==s[z])b=1;
            if(b)dp[z][0]=1;
        }
        b=0;
        for(int z=0;z<n;z++)
        {
            if(str[z]==s[0])b=1;
            
            if(b)dp[0][z]=1;
        }
        
        for(int z=1;z<n;z++)
        {
            for(int y=1;y<n;y++)
            {
                int take=0;
                if(s[z]==str[y])
                    take=dp[z-1][y-1]+1;
                int dontTake=max(dp[z-1][y],dp[z][y-1]);
                
                dp[z][y]=max(take,dontTake);
            }
        }
        return s.size()-dp[n-1][n-1];
    }
};