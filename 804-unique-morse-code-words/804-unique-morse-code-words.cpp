class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       vector<string> s={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}; 
        
        set<string> st;
        
        for(string str:words)
        {
            string temp="";
            for(char c:str)
            {
                temp+=s[c-'a'];
            }
            st.insert(temp);
        }
        return st.size();
    }
};