class Solution {
public:
    
    int solve(vector<int>&v,int i,int j,vector<vector<int>>&dp)
    {
        if(i>j)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=1e9;
        for(int z=i;z<=j;z++)
        {
            ans=min(ans,v[j+1]-v[i-1]+solve(v,i,z-1,dp)+solve(v,z+1,j,dp));
        }
        
        return dp[i][j]=ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return solve(cuts,1,cuts.size()-2,dp);
        
    }
};