class Solution {

public:
    
    bool isPalindrome(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])return 0;
            i++;j--;
        }
        return 1;
    }
    
    int solve(string &s,int i,int &n,vector<int>&dp)
    {
        if(i==n)return 0;
        
        int ans=1e9;
        if(dp[i]!=-1)return dp[i];
        for(int j=i;j<n;j++)
        {
            if(isPalindrome(s,i,j))
            {
                ans=min(ans,1+solve(s,j+1,n,dp));
            }
        }
        return dp[i]=ans;
    }
    
    
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(s,0,n,dp)-1;
    }
};