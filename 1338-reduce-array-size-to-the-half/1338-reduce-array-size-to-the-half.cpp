class Solution {
public:
    // static bool cmp()
    // {
    //     return p1.second>p2.second;
    // }
    int minSetSize(vector<int>& arr) {
        map<int,int>m;
        
        for(int i:arr)
        {
            m[i]++;
        }
        vector<int>v;
        for(auto i:m)
        {
            v.push_back(i.second); 
        }
        sort(v.begin(),v.end(),greater<int>());
        
        int sz=arr.size();
        int ans=0;
        for(int i:v)
        {
            sz-=i;
            ans++;
            if(sz<=arr.size()/2)
                break;
        }
        return ans;
    }
};