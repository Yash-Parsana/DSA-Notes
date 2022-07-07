class Solution {
public:
    
    bool solve(string &s3,string &s1,string &s2,int i,int j1,int j2,vector<vector<int>> &dp)
    {
        if(i>=s3.size())return 1;
        if(j1>=s1.size()&&j2>=s2.size())return 0;
        
        if(dp[j1][j2]!=-1)return dp[j1][j2];
        
        bool ans=0;
                
        if(j1<s1.size()&&s1[j1]==s3[i]&&solve(s3,s1,s2,i+1,j1+1,j2,dp))
            ans=1;
        if(j2<s2.size()&&s2[j2]==s3[i]&&solve(s3,s1,s2,i+1,j1,j2+1,dp))
            ans=1;
        return dp[j1][j2]=ans;
        
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s3.size()!=s1.size()+s2.size())return 0;
        
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return solve(s3,s1,s2,0,0,0,dp);
    }
};