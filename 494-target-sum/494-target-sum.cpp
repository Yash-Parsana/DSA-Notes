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
        vector<int> dp(sum+1,0);

        dp[0]=1;
        if(nums[0]<=sum)dp[nums[0]]++;

        for(int z=1;z<n;z++)
        {
            for(int y=sum;y>=0;y--)
            {
                int take=0;
                if(y>=nums[z])
                    take=dp[y-nums[z]];
                int dontTake=dp[y];
                
                dp[y]=take+dontTake;
            }
        }
        
        return dp[sum];
    }
};