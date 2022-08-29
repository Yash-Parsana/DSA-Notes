class Solution {
public:
    int maxRepOpt1(string t) {
        int ans=1;
        
        vector<vector<int>> v(26);
        int n=t.size();
        for(int i=0;i<n;i++)
        {
            v[t[i]-'a'].push_back(i);
        }
        
        for(int i=0;i<26;i++)
        {
            int cnt=1,tempcnt=0,mx=0;
            for(int j=1;j<v[i].size();j++)
            {
                if(v[i][j]==v[i][j-1]+1)cnt++;
                else{
                    tempcnt=v[i][j-1]+2==v[i][j]?cnt:0;
                    cnt=1;
                }
                mx=max(mx,tempcnt+cnt);
            }
            ans=max(ans,mx+(v[i].size()>mx?1:0));
        }
        return ans;
    }
};