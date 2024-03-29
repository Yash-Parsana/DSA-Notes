class Solution {
public:
    int peopleAwareOfSecret(int n, int d, int f) {
    
        int mod=1e9+7;
        vector<long long> ans(n,0),temp(n,0);
        
        for(int z=0;z<d;z++)
        {
            ans[z]=1;
            temp[z]=0;
        }
        temp[0]=1;
        
        for(int z=d;z<n;z++)
        {
            ans[z]=ans[z-1];
            for(int y=z-f+1;y<=z-d;y++)
            {
                if(y>=0)
                {
                    ans[z]=((ans[z])%mod+temp[y]%mod)%mod;
                    temp[z]=((temp[z])%mod+(temp[y])%mod)%mod;
                }
            }
            if(z-f>=0)ans[z]=(ans[z]-temp[z-f]+mod)%mod;
            
        }
        return ans[n-1]%mod;
        
    }
};