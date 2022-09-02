#define ll long long
class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        int n=p.size(),m=p[0].size();
        vector<vector<ll>> dp(n,vector<ll>(m,0));
        
        for(int i=0;i<m;i++)
            dp[0][i]=p[0][i];
        
        for(int i=1;i<n;i++)
        {
            vector<ll>l(m,-1),r(m,-1);
            l[0]=dp[i-1][0];
            for(int j=1;j<m;j++)
            {
                l[j]=max(l[j-1],dp[i-1][j]+j);
            }
            
            r.back()=dp[i-1].back()-(m-1);
            
            for(int j=m-2;j>=0;j--)
            {
                r[j]=max(r[j+1],dp[i-1][j]-j);
            }
            
            for(int j=0;j<m;j++)
            {
                dp[i][j]=max(l[j]-j,r[j]+j)+p[i][j];
            }
            
        }
        
        return *max_element(dp.back().begin(),dp.back().end());
        
    }
};