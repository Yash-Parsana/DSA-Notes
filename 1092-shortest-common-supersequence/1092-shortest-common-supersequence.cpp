class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        int n=s1.size(),m=s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int z=0;z<=m;z++)
        { 
            dp[0][z]=0;
        }
        for(int z=0;z<=n;z++)
        {
            dp[z][0]=0;
        }
        string ans="";
        for(int z=1;z<=n;z++)
        {
            for(int y=1;y<=m;y++)
            {
                if(s1[z-1]==s2[y-1])
                    dp[z][y]=dp[z-1][y-1]+1;
            
                else dp[z][y]=max(dp[z-1][y],dp[z][y-1]);
                            
            }
        }
        
//         for(auto i:dp)
//         {
//             for(int j:i)
//             {
//                 cout<<j<<" ";
//             }
//             cout<<endl;
//         }
        
        int i=n,j=m;
        while(i>0&&j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                ans.push_back(s1[i-1]);
                i--;j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    ans.push_back(s1[i-1]);
                    i--;
                }
                else
                {
                    ans.push_back(s2[j-1]);
                    j--;
                }
            }
        }
        
        // if(i<0&&j<0)
        // {
        //     reverse(ans.begin(),ans.end());
        //     return ans;
        // }
        
        while(j>0)
        {
            ans.push_back(s2[j-1]);
            j--;
        }
        while(i>0)
        {
            ans.push_back(s1[i-1]);
            i--;
        }

        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};