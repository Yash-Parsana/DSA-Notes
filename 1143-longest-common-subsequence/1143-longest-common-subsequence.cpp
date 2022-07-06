class Solution {
public:
    
    int longestCommonSubsequence(string s1, string s2) {
        
        vector<int> dp(s2.size(),0);

        bool b=0;
        for(int z=0;z<s1.size();z++)
        {
            if(s1[z]==s2[0])b=1;

            dp[0]=b;
        }
        b=0;
        for(int z=0;z<s2.size();z++)
        {
            if(s2[z]==s1[0])b=1;
            dp[z]=b;
        }
        vector<int> temp(s2.size(),0);
        for(int z=1;z<s1.size();z++)
        {
            for(int y=0;y<s2.size();y++)
            {
                if(y==0)
                {
                    if(s1[z]==s2[y])temp[y]=1;
                    else{
                        temp[y]=dp[y];
                    }
                    continue;
                }
                int dontTake=max(temp[y-1],dp[y]);
                
                int take=0;
                if(s1[z]==s2[y])
                    take=dp[y-1]+1;
                temp[y]=max(take,dontTake);
            }
            dp=temp;
        }
        
        return dp[s2.size()-1];
    }
};