class Solution {
public:
    string getHint(string secret, string guess) {
        int l=guess.size();
        int count1=0;
        for(int i=0;i<l;i++){
            if(secret[i]==guess[i]){
                count1++;
                secret[i]=-1;
                guess[i]=-1;
            }
        }
        unordered_map<char,int>pending;
        for(int i=0;i<l;i++){
            if(secret[i]!=-1){
               pending[secret[i]]++; 
            }
        }
        int count2=0;
        for(int i=0;i<l;i++){
            if(pending[guess[i]]>0){
                count2+=1;
                pending[guess[i]]--;
            }
        }
        string m="";
        m+=to_string(count1);
        m+="A";
        m+=to_string(count2);
        m+="B";
        return m;
    }
};