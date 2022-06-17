class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        
        
        int ans=0;
        
        stack<int> s;
        int i=0;
        while(i<=v.size())
        {
            while(!s.empty()&&(i==v.size()||v[s.top()]>v[i]))
            {
                int curr=s.top();s.pop();
                
                if(s.empty()) ans=max(ans,(i)*v[curr]);                                   else ans=max(ans,(i-s.top()-1)*v[curr]);

            }
            s.push(i);
            i++;
        }

        return ans;
        
    }
};