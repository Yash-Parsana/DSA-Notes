class Solution {
public:
    int fib(int n) {
        if(n==0||n==1)return n;
        vector<int> f(n+1,0);
        
        f[0]=0;f[1]=1;
        
        for(int z=2;z<=n;z++)
        {
            f[z]=f[z-1]+f[z-2];
        }
        
        return f[n];
    }
};