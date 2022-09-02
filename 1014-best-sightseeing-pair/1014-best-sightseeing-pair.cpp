class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int ans=-1;
        int temp=0;
        for(int i=0;i<v.size();i++)
        {
            ans=max(ans,temp+v[i]-i);
            temp=max(temp,v[i]+i);
            
        }
        return ans;
    }
};