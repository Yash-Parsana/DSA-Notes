class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        if(v1[0]==v2[0])
            return v1[1]>v2[1];
        return v1[0]<v2[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        
        sort(p.begin(),p.end(),cmp);
        int d=-1,ans=0;
        for(int i=p.size()-1;i>=0;i--)
        {
            if(p[i][1]<d)ans++;
            
            d=max(d,p[i][1]);
        }
        return ans;
    }
};