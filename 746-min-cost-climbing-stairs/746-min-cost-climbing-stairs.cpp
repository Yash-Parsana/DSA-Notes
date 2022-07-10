class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        if(n==2) return min(cost[0],cost[1]);
        
        
        for(int z=n-3;z>=0;z--)
        {
            cost[z]+=min(cost[z+1],cost[z+2]);
        }
        return min(cost[0],cost[1]);
    }
};