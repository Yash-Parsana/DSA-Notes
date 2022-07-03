class Solution {
public:
    // pre=0 previous positive
    int solve(vector<int> &v,int i,int n,vector<vector<int>> &dp,bool pre)
    {
        if(dp[i][pre]!=-1)return dp[i][pre];
        
        int ans=0;
        if(pre==1)
        {
            for(int z=i+1;z<n;z++)
            {
                if(v[z]>v[i])
                  ans=max(ans,solve(v,z,n,dp,0));  
            }
        }
        else
        {
            for(int z=i+1;z<n;z++)
            {
                if(v[z]<v[i])
                    ans=max(ans,solve(v,z,n,dp,1));
            }   
        
        }

        return dp[i][pre]=ans+1;
    }
    
    int wiggleMaxLength(vector<int>& v) {
        
        int n=v.size();
        
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2&&v[0]!=v[1])return 2;
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        return max(solve(v,0,n,dp,0),solve(v,0,n,dp,1));
        
        
    }
};