class Solution {
public:
    
    static bool cmp(vector<int> &v1,vector<int> &v2)
    {
        return v1[1]<v2[1];    
    }
    
    int scheduleCourse(vector<vector<int>>& c) {
        
        sort(c.begin(),c.end(),cmp);
        
        priority_queue<int> pq;
        
        int time=0;
        for(int z=0;z<c.size();z++)
        {
            time+=c[z][0];
            pq.push(c[z][0]);
            if(time>c[z][1])
            {
                time-=pq.top();pq.pop();
            }
        }
        return pq.size();
    }
};
