class Solution {
public:
    
//     s1-s2=target; s1=element with + sign ,s2= element with - sign
//     s1+s2=sum;
//     s1=(target+sum)/2;
    
//     Problem :- Find all subsequence which sum = s1
    
    int solve(vector<int>&v,int i,int &n,vector<vector<int>>&dp,int s)
    {
        if(i>=n)
        {
            if(s==0)return 1;
            return 0;
        }
        if(s==0&&v[i]!=0)return 1;

        if(dp[i][s]!=-1)return dp[i][s];
        
        int ans=0;
        if(v[i]<=s)ans=solve(v,i+1,n,dp,s-v[i]);
        
        return dp[i][s]=solve(v,i+1,n,dp,s)+ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),sum);

        if(abs(target)>sum)return 0;
        if((sum+target)%2)return 0;
        sum=(sum+target)/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
 
        
        return solve(nums,0,n,dp,sum);
        
    }
};