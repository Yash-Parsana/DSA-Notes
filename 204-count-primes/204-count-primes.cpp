class Solution {
public:
   int countPrimes(int n) {
        int c=0,i=2;
        vector<bool> v(n+1,true);
        v[0]=v[1]=false;
        while(i<n){
            if(v[i]==true)
                c++;
            for(int j=2*i;j<n;j+=i)
                v[j]=false;
            i++;
            while(v[i]==false)
                i++;
        }
        return c;
    }
};