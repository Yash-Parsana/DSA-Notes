class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n=s.size(),m=t.size();
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        
        int temp=0;
        for(int z=0;z<n;z++)
        {
            if(s[z]==t[0])
            {
                temp++;
            }
            dp[z][0]=temp;
        }
        
        for(int z=1;z<n;z++)
        {
            for(int y=1;y<m;y++)
            {
                if(s[z]==t[y]&&s.size()-z>=t.size()-y)
                {
                    dp[z][y]=dp[z-1][y-1]+dp[z-1][y];
                }
                else{
                    dp[z][y]=dp[z-1][y];
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};