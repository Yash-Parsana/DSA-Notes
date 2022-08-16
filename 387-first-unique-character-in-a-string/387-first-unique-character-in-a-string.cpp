class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char, unsigned int> feq;
        for (char &c: s) feq[c]++;
        for (char &c: s) if (feq[c] == 1) return &c - &s[0];
        return -1;
    }
};