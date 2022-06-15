
class solve
{
    public:
    int val,i,j;
    
    solve(int va,int ii,int jj)
    {
        val=va;
        i=ii;
        j=jj;
    }
    
};

struct cmp{
    bool operator()(solve s1,solve s2)
    {
        return s1.val>s2.val;
    }
};

class Solution {
public:

    // bool cmp()(solve s1,solve s2)
    // {
    //     return s1.val<s2.val;
    // }
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n=nums1.size(),m=nums2.size();
        priority_queue<solve,vector<solve>,cmp> q;
        
        q.push(solve(nums1[0]+nums2[0],0,0));
        
        set<pair<int,int>> s;
        
        s.insert({0,0});
        
        vector<vector<int>> ans;
        while(ans.size()!=k&&!q.empty())
        {
            solve top=q.top();
            q.pop();
            
            int i=top.i,j=top.j;
            ans.push_back({nums1[i],nums2[j]});
            
            if(i<n-1&&s.count({i+1,j})==0)
            {
                q.push(solve(nums1[i+1]+nums2[j],i+1,j)); 
                s.insert({i+1,j});
            }
            if(j<m-1&&s.count({i,j+1})==0)
            {
                q.push(solve(nums1[i]+nums2[j+1],i,j+1));
                s.insert({i,j+1});
            }
            
        }
        
        return ans;
        
        
    }
};