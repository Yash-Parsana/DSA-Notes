class Solution {
public:
    
    int solve(vector<int>&v,int i,int j,vector<vector<int>>&dp)
    {
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=-1;
        
        for(int z=i;z<j;z++)
        {
            ans=max(ans,v[i-1]*v[z]*v[j]+solve(v,i,z,dp)+solve(v,z+1,j,dp));
        }
        return dp[i][j]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return solve(nums,1,nums.size()-1,dp);
    }
};