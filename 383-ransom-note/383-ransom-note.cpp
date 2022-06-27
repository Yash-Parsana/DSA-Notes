class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> map1;
        for(int i=0;i<ransomNote.size();i++){
            map1[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++){
            map1[magazine[i]]--;
            if(map1[magazine[i]]<=0)
                map1.erase(magazine[i]);
        }
        if(map1.size()==0)
            return true;
        return false;
    }
};