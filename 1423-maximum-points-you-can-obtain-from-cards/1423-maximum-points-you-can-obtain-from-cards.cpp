class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        
        int n=v.size();
        
        if(n<k)return 0;
        
        int sum=0,window=n-k;
        
        int mi=INT_MAX,temp=0;
        
        for(int z=0;z<n;z++)
        {
            sum+=v[z];
            temp+=v[z];
            if(z>=window)
                temp-=v[z-window];
            if(z>=window-1)
                mi=min(mi,temp);
            
        }
        return sum-mi;        
    }
};