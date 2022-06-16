class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& num1, vector<int>& num2)     {
        
        unordered_map<int,int> m;
        
        stack<int> s;
        for(int z=num2.size()-1;z>=0;z--)
        {
            while(!s.empty()&&num2[z]>=s.top()) s.pop();
            
            if(!s.empty()) m[num2[z]]=s.top();
            
            s.push(num2[z]);
            
        }
        
        vector<int> ans;
        for(int z=0;z<num1.size();z++)
        {
            if(m.find(num1[z])==m.end())ans.push_back(-1);
            else ans.push_back(m[num1[z]]);
        }
        return ans;
    }
};