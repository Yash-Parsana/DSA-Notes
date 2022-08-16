class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        if(v1[0]==v2[0])return v1[1]>v2[1];
        return v1[0]<v2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& v) {
        
        sort(v.begin(),v.end(),cmp);
            
        int ans=0,l=0,r=0;
        for(int z=0;z<v.size();z++)
        {
            if(!(l<=v[z][0]&&r>=v[z][1]))
            {
                l=v[z][0];
                r=v[z][1];
                ans++;
            }
        }
        return ans;
    }
};