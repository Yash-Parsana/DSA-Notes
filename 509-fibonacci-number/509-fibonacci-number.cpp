class Solution {
public:
    int fib(int n) {
        if(n==0||n==1)return n;
        
        int pre1=1,pre2=0,curr=0;
        for(int z=2;z<=n;z++)
        {
            curr=pre1+pre2;
            pre2=pre1;
            pre1=curr;
        }
        return curr;
    }
};