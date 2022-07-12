class Solution {
public:
    vector<string> letterCombinations(string s) {
        
    vector<string> ans;
    
        if(s=="") return ans;
        
    ans.push_back("");
        
        vector<string> v = {"","","abc","def","ghi", "jkl","mno","pqrs","tuv","wxyz"};



    for(auto digit:s)
    {
        string chars = v[digit - '0'];
        vector<string> temp;
        for(auto ch:chars)
        {
            for(auto element:ans)
            {
                temp.push_back(element + ch);
            }
        }
        swap(temp, ans);
    }
        return ans;
    }
};