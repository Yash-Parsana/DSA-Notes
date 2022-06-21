class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int z=0;z<h.size()-1;z++)
        {
            int d=h[z+1]-h[z];
            
            if(d<=0)continue;
            
            pq.push(d);
            
            if(pq.size()>l)
            {
                if(pq.top()>b)return z;
                
                b-=pq.top();
                pq.pop();
            }
            
            
        }
        
        return h.size()-1;
        
    }
};