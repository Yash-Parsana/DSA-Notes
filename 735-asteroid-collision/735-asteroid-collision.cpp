class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        
        vector<int>ans;
        
        // ans.push_back(ast[0]);
        for(int z=0;z<ast.size();z++)
        {
            if(ans.empty())ans.push_back(ast[z]);
            else if(ans.back()*ast[z]>0||ans.back()<0&&ast[z]>0)
                ans.push_back(ast[z]);
            else
            {
                while(!ans.empty()&&ans.back()>0&&abs(ast[z])>ans.back())
                {
                    ans.pop_back();
                }
                if(!ans.empty())
                {
                    if(ans.back()<0)ans.push_back(ast[z]);
                    else if(ans.back()==abs(ast[z]))ans.pop_back();
                }
                else ans.push_back(ast[z]);
            }
        
        }
        return ans;
       
        
    }
};