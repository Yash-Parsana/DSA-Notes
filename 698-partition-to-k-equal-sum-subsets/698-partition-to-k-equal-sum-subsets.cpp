class Solution {
public:
    
    bool solve(int i,int n,vector<int> &v,vector<int> s,int &sum)
    {
        if(i>=n)
        {
            return 1;
        }
        
        for(int z=0;z<s.size();z++)
        {
            if(s[z]+v[i]>sum)continue;
            s[z]+=v[i];
            if(solve(i+1,n,v,s,sum))return 1;
            s[z]-=v[i];
            if(s[z]==0)return 0;
        }
        return 0;
    }
    
    bool canPartitionKSubsets(vector<int>& v, int k) {
        
        int sum=0;
        for(int i:v)sum+=i;
        
        if(sum%k)return 0;
        
        sum=sum/k;
        vector<int> s(k,0);

        sort(v.begin(),v.end(),greater<int>());
        return solve(0,v.size(),v,s,sum);
        
    }
};