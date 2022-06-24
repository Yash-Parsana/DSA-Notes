class Solution {
public:
    int numTrees(int n) {
        
        vector<int> v(n+1);
        v[0]=1;v[1]=1;
        
        for(int z=2;z<=n;z++)
        {
            int i=0,j=z-1;
            int temp=0;
            while(i<z)
            {
                temp+=(v[i]*v[j]);
                i++;j--;
            }
            v[z]=temp;
        }
        
        return v[n];
    }
};