class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pig=0;
        int base=minutesToTest/minutesToDie+1,temp=1;
        int ans=0;
        while(temp<buckets)
        {
            ans++;
            temp*=base;
        }
        
        return ans; 
    }
};