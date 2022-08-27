class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mtx, int k) {
        
        int n=mtx.size(),m=mtx[0].size();
        int ans=INT_MIN;
        for(int i=0;i<m;i++)
        {
            vector<int> sum(n,0);
            for(int j=i;j<m;j++)
            {
                
                int temp=0,maxsum=INT_MIN;
                for(int r=0;r<n;r++)
                {
                    sum[r]+=mtx[r][j];
                    temp=max(temp+sum[r],sum[r]);
                    maxsum=max(maxsum,temp);
                }
                if(maxsum<=k)
                {
                    ans=max(ans,maxsum);
                    continue;                    
                }
                set<int> s;
                s.insert(0);
                temp=0;
                for(int sm:sum)
                {
                    temp+=sm;
                    auto it=s.lower_bound(temp-k);
                    if(it!=s.end())
                    {
                        ans=max(ans,temp-*it);
                    }
                    s.insert(temp);
                }
            }
        }
        return ans;
    }
};