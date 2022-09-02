class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        vector<int>l(n,0),r(n,0);
        vector<bool>v(26,0);
        int t=0;
        for(int i=0;i<n;i++)
        {
            if(!v[s[i]-'a'])
            {
                t++;
                v[s[i]-'a']=1;
            }
            l[i]=t;
        }
        v=vector<bool>(26,0);
        t=0;
        for(int i=n-1;i>=0;i--)
        {
            if(!v[s[i]-'a'])
            {
                t++;
                v[s[i]-'a']=1;
            }
            r[i]=t;
        }
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            if(l[i]==r[i+1])
                ans++;
        }
        return ans;
    }
};