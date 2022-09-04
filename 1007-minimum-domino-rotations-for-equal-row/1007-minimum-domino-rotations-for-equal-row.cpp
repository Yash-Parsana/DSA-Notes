class Solution {
public:
    
    int helper(int num,vector<int>& curr,vector<int>&use)
    {
        int n=curr.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(curr[i]==num)continue;
            else if(use[i]==num)ans++;
            else return INT_MAX;
        }
        return ans;
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans=INT_MAX;

        for(int i=1;i<=6;i++)
        {
            ans=min({ans,helper(i,tops,bottoms),helper(i,bottoms,tops)});   
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};