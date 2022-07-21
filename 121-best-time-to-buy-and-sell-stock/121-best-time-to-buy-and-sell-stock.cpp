
class Solution {
public:

    int maxProfit(vector<int> &v) {
        
            int n=v.size();
            if(n<=1)return 0;
            int minBeforeThis = INT_MAX,ans=0;
            for (int z = 0; z <n; z++)
            {
                if(v[z]<minBeforeThis)
                {
                    minBeforeThis = v[z];
                    continue;
                }

                ans =max(v[z] - minBeforeThis,ans);

                
            }
        return ans;
    }
};