#define ll long long
class Solution {
public:

    int numFactoredBinaryTrees(vector<int>& v) {
        sort(v.begin(),v.end());
        int mod=1e9+7;
        ll ans=0;
        int n=v.size();
        map<int,ll> dp;
        for(int i=0;i<n;i++)
        {
            dp[v[i]]=1;
            for(int j=0;j<n;j++)
            {
                if(v[i]%v[j]==0)
                    dp[v[i]]=(dp[v[i]]+ (dp[v[j]]*dp[v[i]/v[j]]))%mod;
            }
            ans=(ans+dp[v[i]])%mod;
        }
        return ans;
        
    }
};