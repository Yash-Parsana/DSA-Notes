class Solution {
public:
    
    int longestCommonSubsequence(string s1, string s2) {
        
        vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));

        bool b=0;
        for(int z=0;z<s1.size();z++)
        {
            if(s1[z]==s2[0])b=1;

            dp[z][0]=b;
        }
        b=0;
        for(int z=0;z<s2.size();z++)
        {
            if(s2[z]==s1[0])b=1;
            dp[0][z]=b;
        }
        
        for(int z=1;z<s1.size();z++)
        {
            for(int y=1;y<s2.size();y++)
            {
                int dontTake=max(dp[z][y-1],dp[z-1][y]);
                
                int take=0;
                if(s1[z]==s2[y])
                    take=dp[z-1][y-1]+1;
                dp[z][y]=max(take,dontTake);
            }
        }
        
        return dp[s1.size()-1][s2.size()-1];
    }
};