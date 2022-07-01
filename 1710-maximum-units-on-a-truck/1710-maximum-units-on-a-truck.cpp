class Solution {
public:
    
    static bool cmp(vector<int> v1,vector<int> v2)
    {
        return v1[1]>v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int ans=0;
        
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        
        for(int z=0;z<boxTypes.size();z++)
        {
            if(truckSize>=boxTypes[z][0])
            {
                ans+=boxTypes[z][0]*boxTypes[z][1];
                truckSize-=boxTypes[z][0];
            }
            else{
                ans+=truckSize*boxTypes[z][1];
                truckSize=0;
            }
        }
        return ans;
    }
};