class Solution {
    
    public boolean solve(int n,int []dp)
    {
        if(n<=0)return true;
        
        if(dp[n]!=-1)return (dp[n]==1)?true:false;
        
        boolean ans=false;
        for(int z=1;z*z<=n;z++)
        {
            ans=ans||solve(n-z*z,dp);
        }
        dp[n]=(ans)?0:1;
        return !ans;
    }
    
    public boolean winnerSquareGame(int n) {
        int dp[]=new int[n+1];
        Arrays.fill(dp,-1);
        return !solve(n,dp);
    }
}