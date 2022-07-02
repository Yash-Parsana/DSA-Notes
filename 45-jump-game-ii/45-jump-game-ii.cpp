class Solution {
public:
    
    int minjump(vector<int> &v,int i,vector<int> &dp)
    {
        if(i==v.size()-1)
        {
            return 0;
        }
        
        if(dp[i]!=-1)return dp[i];
        
        int ans=1e6;
        
        for(int z=i+1;z<=i+v[i]&&z<v.size();z++)
        {
            ans=min(ans,minjump(v,z,dp)+1);
        }
        return dp[i]=ans;
    }
    
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        
        return minjump(nums,0,dp);
        
    }
};