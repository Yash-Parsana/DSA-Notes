class Solution {
public:
    int lastStoneWeightII(vector<int>& v) {
        int n=v.size();
        int sum=0;
        for(int i:v)sum+=i;
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
    
        for(int i=0;i<=sum;i++)
        {
            if(v[0]==i)
                dp[0][i]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
                dp[i][0]=1;
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(dp[i-1][j]||(j-v[i]>=0&&dp[i-1][j-v[i]]))
                    dp[i][j]=1;
            }
        }
        
        int ans=INT_MAX;
        
        for(int i=0;i<=sum;i++)
        {
            if(dp.back()[i])
                ans=min(ans,abs(sum-2*i));
        }
        return ans;
    }
};