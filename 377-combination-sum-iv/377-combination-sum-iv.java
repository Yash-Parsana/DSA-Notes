class Solution {
    
    int solve(int []v,int n,int k,int []dp)
    {
        if(k<0)return 0;
        if(k==0)return 1;
        int ans=0;
        if(dp[k]!=-1)return dp[k];
        for(int z=0;z<n;z++)
        {
            ans+=solve(v,n,k-v[z],dp);
        }
        return dp[k]=ans;
    }
    
    public int combinationSum4(int[] nums, int target) {
        int dp[]=new int[target+1];
        Arrays.fill(dp,-1);
        int n=nums.length;
        return solve(nums,n,target,dp);
    }
}