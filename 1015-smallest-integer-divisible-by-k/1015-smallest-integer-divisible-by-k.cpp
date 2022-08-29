class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        if(k%2==0||k%5==0)return -1;
        
        int curr=0;
        for(int n=1;n<=k;n++)
        {
            curr=((curr*10)+1)%k;
            if(curr==0)return n;
        }
        return -1;
    }
};