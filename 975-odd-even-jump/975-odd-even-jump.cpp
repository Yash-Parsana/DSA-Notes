class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        
        int n=arr.size();
        vector<bool>h(n),l(n);
        map<int,int> mp;
        h[n-1]=l[n-1]=1;
        mp[arr.back()]=n-1;
        int ans=1;
        for(int i=n-2;i>=0;i--)
        {
            auto odd=mp.lower_bound(arr[i]),even=mp.upper_bound(arr[i]);
            
            if(odd!=mp.end())h[i]=l[odd->second];
            if(even!=mp.begin())l[i]=h[(*(--even)).second];
            if(h[i])ans++;
            mp[arr[i]]=i;
        }
        return ans;
    }
};