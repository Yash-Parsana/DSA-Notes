class Solution {
public:
    int kadanesalgo_noncircular(vector<int> v,int n)
    {
        int temp=0,ans=INT_MIN;
        for (int z = 0; z < n;z++)
        {
            temp += v[z];
            if(temp<0)
            {
                temp = 0;
            }
            else
                ans =max(ans,temp);
        }
        return ans;
    }
    int kadanesalgo_circular(vector<int> v, int n)
    {
        int ans1, ans2,ans;

        ans1 = kadanesalgo_noncircular(v, n);
        int temp = 0;
        for (int z = 0;z<n;z++)
        {
            temp += v[z];
            v[z] = -v[z];
        }
        ans2 = kadanesalgo_noncircular(v, n);

        return ans = max(ans1, temp + ans2);
    }

    int kConcatenationMaxSum(vector<int>& arr, int k) {
        
        int sum=0,mod=1e9+7;
        int n=arr.size();
        for(int z=0;z<n;z++)
        {
            sum+=arr[z];
        }
        
        int maxsum=kadanesalgo_noncircular(arr,arr.size());
        // cout<<" - "<<maxsum<<" - "<<sum<<endl;
        if(k==1)return maxsum;
        if(sum>=0)
        {
            arr.insert(arr.end(),arr.begin(),arr.end());
            maxsum=kadanesalgo_noncircular(arr,arr.size());
            // cout<<" * "<<maxsum<<endl;
            return (maxsum+(1L*(k-2)*sum)%mod)%mod; 
            
        }
        if(k>=2)
        {
            maxsum=kadanesalgo_circular(arr,arr.size());
            if(maxsum<0)return 0;            
            return maxsum;
        }
        if(maxsum<0)
        {
            return 0;
        }
        return maxsum%mod;

        
    } 
};