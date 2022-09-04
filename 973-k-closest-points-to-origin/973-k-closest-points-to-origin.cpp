class Solution {
public:
    
    static bool cmp(vector<int> &p1,vector<int>&p2)
    {
        return (pow(p1[0],2)+pow(p1[1],2))<(pow(p2[0],2)+pow(p2[1],2));
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        sort(points.begin(),points.end(),cmp);
        
        auto s=points.begin();
        vector<vector<int>> ans(k);
        copy(s,s+k,ans.begin());
        return ans;
    }
};