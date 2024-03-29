class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,0)); 
        
        int ans=0;
        for(int i=0;i<n;i++)
            if(nums2[0]==nums1[i])
                dp[i][0]=1,ans=1;
        for(int i=0;i<m;i++)
            if(nums1[0]==nums2[i])
                dp[0][i]=1,ans=1;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(nums1[i]==nums2[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                ans=max(ans,dp[i][j]);
            }
        }
        
        return ans;
    }
};