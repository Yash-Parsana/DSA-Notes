class Solution {
public:
    int solve(vector<int>&v,int i,vector<int>&dp)
    {
        if(i>=v.size())return 0;
        
        int temp=0,ans=INT_MIN;
        if(dp[i]!=INT_MIN)return dp[i];
        for(int z=i;z<v.size()&&z<i+3;z++)
        {
            temp+=v[z];
            ans=max(ans,temp-solve(v,z+1,dp));
        }
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& v) {
        vector<int>dp(v.size(),INT_MIN);
        int ans=solve(v,0,dp);
        if(ans==0)return "Tie";
        if(ans>0)return "Alice";
        return "Bob";
    }
};