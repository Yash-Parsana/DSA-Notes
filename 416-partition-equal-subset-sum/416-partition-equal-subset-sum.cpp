class Solution {
public:
    bool canPartition(vector<int>& v) {
        
        int n=v.size();
        if(n==1)return false;
        int k=0;
        for(int i:v)k+=i;
        if(k&1)return 0;
        k=k/2;
        
        vector<bool> dp(k+1,0);
        
        dp[0]=1;

        if(v[0]<=k)
            dp[v[0]]=1;
        
        vector<bool> temp(k+1,0);
        for(int z=1;z<n;z++)
        {
            for(int target=1;target<=k;target++)
            {
                if(target-v[z]>=0)temp[target]=dp[target-v[z]];
                temp[target]=temp[target]|dp[target];
            }
            swap(dp,temp);
        }
        return dp[k];
        
    }
};