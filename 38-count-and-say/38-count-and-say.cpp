vector<string> dp(31,"");
class Solution {
public:
string countAndSay(int n) {

    if(n==1)
        return dp[1]="1";

    if(n==2)
        return dp[2]= "11";
    
    if(!dp[n].empty()) return dp[n];
    
    string str = countAndSay(n - 1);

    string ans="";

    for (int z = 0; z < str.size();z++)
    {
        int count = 1;
        while(str[z]==str[z+1])
        {
            count++;
            z++;
        }
        // cout << count << " " << str[z] << endl;
        if(count>0)
            ans += to_string(count) + str[z];
    }
    return dp[n]= ans;
}
};