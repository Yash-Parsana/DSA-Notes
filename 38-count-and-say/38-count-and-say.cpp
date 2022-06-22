class Solution {
public:
string countAndSay(int n) {

    if(n==1)
        return "1";

    if(n==2)
        return "11";

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
    return ans;
}
};