class Solution {
public:
    
    int solve(vector<int>&v,int i,int m,vector<vector<int>>&dp)
    {
        if(i>=v.size())return 0;
        int temp=0,ans=INT_MIN;
        if(dp[i][m]!=INT_MIN)return dp[i][m];
        for(int z=i;z<i+2*m&&z<v.size();z++)
        {
            temp+=v[z];
            ans=max(ans,temp-solve(v,z+1,max(m,z-i+1),dp));
        }
        // cout<<i<<" "<<ans<<endl;
        return dp[i][m]=ans;
    }
    
    int stoneGameII(vector<int>& piles) 
    {
        if(piles.size()==1)return piles[0];
        int sum=0;
        for(int i:piles)sum+=i;
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(),INT_MIN));
        return (sum+solve(piles,0,1,dp))/2;
    }
};