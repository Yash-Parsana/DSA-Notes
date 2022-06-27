class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() < 11) return {};
        
        vector<string> r;
        map<string, int> table;
        
        auto f = table.find("");
        int n = s.length() - 9;
        
        string s1;
        for (int i = 0; i < n; i++) {
            s1 = s.substr(i, 10);
            f = table.find(s1);
            if (f == table.end()) {
                table[s1] = 1;
            } else if (f->second == 1) {
                r.push_back(s1);
                f->second += 1;
            }
        }
        return r;
    }
     
};