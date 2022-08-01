class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        int n=v.size();
        vector<pair<int,int>>dp(n,{1,1}); //first ->len second ->no os ss

        int ans=0,maxLen=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[i]>v[j])
                {
                    if(dp[i].first<dp[j].first+1)
                    {
                        dp[i].first=dp[j].first+1;
                        dp[i].second=dp[j].second;
                    }
                    else if(dp[i].first==dp[j].first+1){
                        dp[i].second+=dp[j].second;
                    }
                }
            }
            if(maxLen<dp[i].first)
            {
                maxLen=dp[i].first;
                ans=dp[i].second;
            }
            else if(maxLen==dp[i].first)ans+=dp[i].second;
        }
        return ans;
    }
};