#define ll long long

class Solution {
public:
    
    
    int maximumRobots(vector<int>& c, vector<int>& r, long long b) {
        
        
        int i=0,j=0,ans=0;
        ll sum=0;;
        deque<int> dq;
        while(j<c.size())
        {
            
            if((dq.empty()&&c[j]+(j-i+1)*(sum+r[j])<=b)||!dq.empty()&&(max(c[dq.front()],c[j])+(j-i+1)*(sum+r[j]))<=b)
            {
                sum+=r[j];
                while(!dq.empty()&&c[dq.back()]<c[j])dq.pop_back();

                dq.push_back(j);
                ans=max(ans,j-i+1);
                j++;
            }
            else if(i!=j)
            {
                if(!dq.empty()&&dq.front()==i)dq.pop_front();
                sum-=r[i];
                i++;           
            }
            else {
                i++;j++;
            }
            
        }
        return ans;
        
    }
};