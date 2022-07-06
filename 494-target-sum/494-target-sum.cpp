class Solution {
public:
    
//     s1-s2=target; s1=element with + sign ,s2= element with - sign
//     s1+s2=sum;
//     s1=(target+sum)/2;
    
//     Problem :- Find all subsequence which sum = s1
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sum=0;
        sum=accumulate(nums.begin(),nums.end(),sum);

        if(abs(target)>sum)return 0;
        if((sum+target)%2)return 0;
        sum=(sum+target)/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,0));

        dp[0][0]=1;
        if(nums[0]<=sum)dp[0][nums[0]]++;
        // for(int z=0;z<=sum;z++)
        // {
        //     cout<<dp[0][z]<<" ";
        // }
        // cout<<endl;
        for(int z=1;z<n;z++)
        {
            for(int y=0;y<=sum;y++)
            {
                int take=0;
                if(y>=nums[z])
                    take=dp[z-1][y-nums[z]];
                int dontTake=dp[z-1][y];
                
                dp[z][y]=take+dontTake;
                // cout<<dp[z][y]<<" ";
            }
            // cout<<endl;
        }
        
        return dp[n-1][sum];
    }
};