class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& st) {
        st.push_back({target,0});
        sort(st.begin(),st.end());
        int ans=0;
        priority_queue<int> pq;
        
        int d=0,i=0,cf=startFuel;
        while(i<st.size()&&d<target)
        {
            if(cf>=(st[i][0]-d))
            {
                pq.push(st[i][1]);
                cf-=(st[i][0]-d);
                d=st[i][0];
                i++;
            }
            else if(!pq.empty())
            {
                ans++;
                cf+=pq.top();
                pq.pop();
            }
            else break;
            
            // cout<<i<<" "<<cf<<" "<<d<<endl;
        }
        if(d<target&&cf<target-d)return -1;
        
        return ans;
        
    }
};