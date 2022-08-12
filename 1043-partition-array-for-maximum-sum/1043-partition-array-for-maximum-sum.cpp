class Solution {
public:
    int solve(vector<int>&v,int i,int &k,vector<int>&dp)
    {
        if(i==v.size())return 0;
        if(dp[i]!=-1)return dp[i];
        
        int ans=0,mx=-1;
        for(int j=i;j<v.size()&&j<i+k;j++)
        {
            mx=max(mx,v[j]);
            ans=max(ans,solve(v,j+1,k,dp)+(j-i+1)*mx);
        }
        // cout<<i<<" "<<ans<<endl;
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return solve(arr,0,k,dp);
    }
};