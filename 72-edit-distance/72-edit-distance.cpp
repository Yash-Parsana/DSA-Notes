class Solution {
public:
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n==0&&m==0)return 0;
        if(n==0)return m;
        if(m==0)return n;
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        
        bool b=0;
        for(int z=0;z<m;z++)
        {
            if(s1[0]==s2[z])
                b=1;
            if(b)
                dp[0][z]=z;
            else dp[0][z]=z+1;
        }
        b=0;
        for(int z=0;z<n;z++)
        {
            
            if(s2[0]==s1[z])
                b=1;
            if(b)
                dp[z][0]=z;
            else dp[z][0]=z+1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(s1[i]==s2[j])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
            
        }
        return dp[n-1][m-1];
    }
};