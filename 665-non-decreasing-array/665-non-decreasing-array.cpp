class Solution {
public:
    bool checkPossibility(vector<int>& v) {
        
        int c=0,i=0;
        
        for(int z=0;z<v.size()-1;z++)
        {
            if(v[z]>v[z+1])
            {
                c++;
                if(c>1)return 0;
                
                if(z==0||v[z+1]>=v[z-1])
                {
                    v[z]=v[z+1];
                }
                else if(v[z-1]>v[z+1]){
                    v[z+1]=v[z];
                }
                
            }
        }
    
        return 1;
    }
};