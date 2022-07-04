class Solution {
public:
    
    bool solve(vector<int> &v,int k,int i,int &n,vector<vector<int>> &dp)
    {
        if(i>=n)return 0;
        
        if(dp[i][k]!=-1)return dp[i][k];
        if(v[i]<=k)
        {
            if(v[i]==k)return dp[i][k]=1;
            if(solve(v,k-v[i],i+1,n,dp))return dp[i][k]=1;
        }
        
        return dp[i][k]=solve(v,k,i+1,n,dp);
    }
    
    
    bool canPartition(vector<int>& nums) {
        
        int k=0;
        for(int i:nums)
        {
            k+=i;
        }
        if(k&1)return 0;
        int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        
        return solve(nums,k/2,0,n,dp);
    }
};